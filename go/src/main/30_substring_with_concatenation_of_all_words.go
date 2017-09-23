package main

import (
	"fmt"
	"reflect"
)

func isSubString(str string, n int, wordExistMap map[string]int) bool {
	wordLen := len(str) / n
	for i := 0; i < len(str); i += wordLen {
		if times, ok := wordExistMap[str[i:i+wordLen]]; !ok || times <= 0 {
			return false
		} else {
			wordExistMap[str[i:i+wordLen]] -= 1
		}
	}
	return true
}

func findSubstring(str string, words []string) (indexs []int) {
	if len(words) == 0 {
		return []int{}
	}

	wordExistMap := map[string]int{}
	for _, word := range words {
		if _, ok := wordExistMap[word]; !ok {
			wordExistMap[word] = 0
		}
		wordExistMap[word] += 1
	}

	length := len(words) * len(words[0])
	for i := 0; i < len(str)-length+1; i++ {
		wordExistMapCopy := map[string]int{}
		for key, val := range wordExistMap {
			wordExistMapCopy[key] = val
		}
		if isSubString(str[i:i+length], len(words), wordExistMapCopy) {
			indexs = append(indexs, i)
		}
	}

	return indexs
}

func main() {
	for _, unit := range []struct {
		str    string
		words  []string
		indexs []int
	}{
		{"barfoothefoobarman", []string{"foo", "bar"}, []int{0, 9}},
		{"wordgoodgoodgoodbestword", []string{"word", "good", "best", "good"}, []int{8}},
	} {
		if indexs := findSubstring(unit.str, unit.words); !reflect.DeepEqual(indexs, unit.indexs) {
			fmt.Printf("findSubstring(%v, %v) = %v != %v\n", unit.str, unit.words, indexs, unit.indexs)
		}
	}
}
