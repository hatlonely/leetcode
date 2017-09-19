#!/usr/bin/env bash

MODULES="go"
HOST="go"
DEST="/data"
USER="root"

function pack() {
    ver=$1
    modules="${MODULES}"
    if [[ ! -z "$2" ]]; then
        modules="$2"
    fi

    for module in ${modules}; do
        output="output/${module}"
        mkdir -p ${output}/bin && mkdir -p ${output}/conf &&
        mv ${module} ${output}/bin &&
        cp conf/${ver}/${module}* ${output}/conf ||
        warn "pack fail" || return 255
    done
    info "pack success"
}

WORK_ROOT=`pwd`
export GOPATH=${WORK_ROOT}
export LD_LIBRARY_PATH="${WORK_ROOT}/third/protobuf-3.2.0/lib/"
export PATH="${WORK_ROOT}/bin:${PATH}"
alias protoc="${WORK_ROOT}/third/protobuf-3.2.0/bin/protoc"
if [[ $(uname -s) == "Linux" ]]; then
    alias echo="echo -e"
fi

function warn() {
    echo "[31m$1[0m"
}

function info() {
    echo "[32m$1[0m"
}

function install_protoc() {
    output=${WORK_ROOT}/third/protobuf-3.2.0
    [[ -e ${output} ]] && info "${output} is exists" && return 0
    mkdir -p third && cd third &&
    wget https://github.com/google/protobuf/releases/download/v3.2.0/protobuf-cpp-3.2.0.tar.gz &&
    tar -xzvf protobuf-cpp-3.2.0.tar.gz && cd protobuf-3.2.0 &&
    ./configure --prefix=${output} && make -j8 && make install &&
    info "install protoc success" && return 0
    warn "install protoc fail" && return 255
}

function install_go_dependency() {
    git config --global url."git@gitlab.mobvista.com:mtech/mgo.git".insteadOf "http://gitlab.mobvista.com/mtech/mgo.git"
    go get -v -u --insecure gitlab.mobvista.com/mtech/mgo
    go get -v -u gopkg.in/alecthomas/kingpin.v2 &&
    go get -v -u github.com/fzipp/gocyclo &&
    go get -v -u github.com/cihub/seelog &&
    go get -v -u github.com/spf13/viper &&
    go get -v -u google.golang.org/grpc &&
    go get -v -u github.com/spaolacci/murmur3 &&
    go get -v -u gopkg.in/mgo.v2 &&
    go get -v -u github.com/garyburd/redigo/redis &&
    go get -v -u github.com/chasex/redis-go-cluster &&
    go get -v -u github.com/go-redis/redis &&
    go get -v -u gopkg.in/gin-gonic/gin.v1 &&
    go get -v -u github.com/bluele/gcache &&
    # go get -v -u github.com/emirpasic/gods
    # go get -v -u github.com/golang/protobuf/proto github.com/golang/protobuf/protoc-gen-go &&
    # go get -v -u github.com/satori/go.uuid &&
    # go get -v -u github.com/syndtr/goleveldb/leveldb &&
    # go get -v -u github.com/go-sql-driver/mysql &&

    info "install go dependency success" && return 0
    warn "install go dependency fail" && return 255
}

function codegen() {
    cd proto &&
    protoc --go_out=plugins=grpc:. *.proto &&
    mkdir -p ${WORK_ROOT}/src/rta_proto &&
    mv *.go ${WORK_ROOT}/src/rta_proto &&
    info "gencode success" && return 0
    warn "gencode failed" && return 255
}

function build() {
    for f in $(\ls src/main); do
        go build src/main/${f}
        if [[ $? != 0 ]]; then
            warn "build src/main/${f} failed." && return 255
        fi
    done

    ver="release"
    if [[ $1 == "prerelease" || $1 == "offline" || $1 == "release" ]]; then
        ver=$1
    fi

    pack ${ver} ${MODULES} &&
    info "build ${ver} success" && return 0
    warn "build ${ver} fail" && return 255
}

function unit() {
    modules=${MODULES}
    if [[ ! -z "$1" ]]; then
        modules="$1"
    fi
    echo "module	status	time	coverage	code_linenum	test_linenum	code_gocyclo	test_gocyclo"
    for module in ${modules}; do
        time_coverage=$(go test -cover src/${module}/*.go)
        if [[ $? != 0 ]]; then
            go test src/${module}/*.go
            warn "unit test src/${module} failed." && return 255
        fi
        code_linenum=$(find src/${module} -name "*.go" | grep -v _test.go | xargs wc -l | awk '{sum+=$1}END{print sum}')
        test_linenum=$(find src/${module} -name "*.go" | grep _test.go | xargs wc -l | awk '{sum+=$1}END{print sum}')
        code_gocyclo=$(bin/gocyclo $(find src/${module} -name "*.go" | grep -v _test.go) | awk '{sum+=$1}END{print sum}')
        test_gocyclo=$(bin/gocyclo $(find src/${module} -name "*.go" | grep _test.go) | awk '{sum+=$1}END{print sum}')
        echo "${module}	$(echo ${time_coverage} | awk 'BEGIN{OFS="	"}{print $1,$3,$5}')	"             "${code_linenum}	${test_linenum}	${code_gocyclo}	${test_gocyclo}"
    done
    info "unit success" && return 0
}

function mstat() {
    gitlab=$(git remote -v | grep origin | grep fetch | awk '{print $2}')
    values=$(echo ${gitlab} | awk -F '[:/.]' 'BEGIN{OFS="	"}{print $(NF-2),$(NF-1),$0}')
    team=$(echo ${values} | awk '{print $1}')
    proj=$(echo ${values} | awk '{print $2}')
    unit $1 | grep ok | python3 -c "
import sys
import datetime
for line in sys.stdin:
    obj = {}
    values = line.split('	')
    obj['@team'] = '${team}'
    obj['@proj'] = '${proj}'
    obj['@timestamp'] = datetime.datetime.now() - datetime.timedelta(hours=8)
    obj['@module'] = values[0]
    obj['@id'] = '{}/{}/{}'.format(obj['@team'], obj['@proj'], obj['@module'])
    obj['status'] = values[1]
    obj['unittime'] = float(values[2][:-1])
    obj['coverage'] = float(values[3][:-1])
    obj['code_linenum'] = int(values[4])
    obj['test_linenum'] = int(values[5])
    obj['code_gocyclo'] = int(values[6])
    obj['test_gocyclo'] = int(values[7])
    print(('mstat', 'munit',
          '{}_{}_{}_{}'.format(obj['@team'], obj['@proj'], obj['@module'], obj['@timestamp'].strftime('%Y%m%d')), obj))
    "
}

function deploy() {
    host=${HOST}
    dest=${DEST}
    user=${USER}
    modules=${MODULES}

    if [[ ! -z $1 ]]; then
        host=$1
    fi
    if [[ ! -z $2 ]]; then
        dest=$2
    fi
    if [[ ! -z $3 ]]; then
        user=$3
    fi

    for module in ${modules}; do
        # 部署程序
        ansible ${host} -m copy -a "src=output/${module} dest=${dest} owner=${user} group=${user} mode=755" -s

        # 数据清理
        ansible ${host} -m cron -a "
            user='${user}'
            name='clean_${module}_log'
            minute='5'
            job='find ${dest}/${module}/log -ctime +1 | grep acclog | xargs rm -rf && find /data/${module}/log -ctime +14 | xargs rm -rf'
        " -s

        # 日志收集
        ansible ${host} -m cron -a "
            user='${user}'
            name='report_${module}_satlog'
            minute='*'
            job='tail -1 ${dest}/${module}/log/${module}.satlog | /usr/local/python3/bin/python3 /usr/local/mtool/mreport --host bj-report-ELB20151027-2124151593.us-east-1.elb.amazonaws.com:80 --user mob_report --password Mobvista_256 --index rta_report --doctype satlog_${module}'
        " -s
    done
}

function usage() {
    info "usage: "
    info "  sh everything.sh <dependency | unit | stat | build | deploy>"
    info "  dependency  安装依赖"
    info "  unit        单元测试[module]"
    info "  stat        统计"
    info "  build       编译[offline | prerelease | release]"
    info "  deploy      部署"
}

function main() {
    case "$1" in
        "protoc") install_protoc;;
        "dependency") install_go_dependency;;
        "codegen") codegen;;
        "unit") unit "$2";;
        "stat") mstat "$2";;
        "build") build "$2";;
        "deploy") deploy "$2" "$3" "$4";;
        *) usage;;
    esac
}

main "$@"
