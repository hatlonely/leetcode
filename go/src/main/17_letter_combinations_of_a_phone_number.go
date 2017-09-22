package main

import (
	"fmt"
	"reflect"
)

var digitLettersMap = map[int]string{
	'2': "abc", '3': "def",
	'4': "ghi", '5': "jkl", '6': "mno",
	'7': "pqrs", '8': "tuv", '9': "wxyz",
}

func letterCombinationsRecursive(digits string) (combinations []string) {
	if len(digits) == 0 {
		return []string{""}
	}

	lcs := letterCombinationsRecursive(digits[1:])
	for _, c := range digitLettersMap[int(digits[0])] {
		for _, lc := range lcs {
			combinations = append(combinations, string(c)+lc)
		}
	}

	return combinations
}

func letterCombinations(digits string) (combinations []string) {
	if len(digits) == 0 {
		return []string{}
	}

	return letterCombinationsRecursive(digits)
}

func main() {
	for _, unit := range []struct {
		digits       string
		combinations []string
	}{
		{"23", []string{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}},
	} {
		if combinations := letterCombinations(unit.digits); !reflect.DeepEqual(combinations, unit.combinations) {
			fmt.Printf("letterCombinations(%v) = %v != %v\n", unit.digits, combinations, unit.combinations)
		}
	}
}
