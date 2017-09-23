package main

import (
	"fmt"
)

var parenthesesMap = map[int32]int32{
	'{': '}', '[': ']', '(': ')',
}

func isValid(str string) bool {
	is := []int32{}
	for _, c := range str {
		if _, ok := parenthesesMap[c]; ok {
			is = append(is, c)
		} else {
			if len(is) == 0 {
				return false
			}
			if parenthesesMap[is[len(is)-1]] != c {
				return false
			}
			is = is[:len(is)-1]
		}
	}

	return len(is) == 0
}

func main() {
	for _, unit := range []struct {
		str   string
		vaild bool
	}{
		{"()[]{}", true},
		{"(]", false},
		{"([])", true},
	} {
		if valid := isValid(unit.str); valid != unit.vaild {
			fmt.Printf("isValid(%v) = %v != %v\n", unit.str, valid, unit.vaild)
		}
	}
}
