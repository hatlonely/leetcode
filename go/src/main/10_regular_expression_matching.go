package main

import "fmt"

func isMatch(source string, pattern string) (match bool) {
	if len(source) != 0 && len(pattern) == 0 {
		return false
	}
	if len(source) == 0 && len(pattern) == 0 {
		return true
	}

	star := len(pattern) >= 2 && pattern[1] == '*'

	if len(source) > 0 && (source[0] == pattern[0] || pattern[0] == '.') {
		if star {
			return isMatch(source, pattern[2:]) || isMatch(source[1:], pattern)
		} else {
			return isMatch(source[1:], pattern[1:])
		}
	} else {
		if star {
			return isMatch(source, pattern[2:])
		} else {
			return false
		}
	}

	return false
}

func main() {
	for _, unit := range []struct {
		source  string
		pattern string
		match   bool
	}{
		{"aa", "a", false},
		{"aa", "aa", true},
		{"aaa", "aa", false},
		{"aa", "a*", true},
		{"aa", ".a", true},
		{"ab", ".*", true},
		{"aab", "c*a*b", true},
		{"a", "ab*", true},
	} {
		if match := isMatch(unit.source, unit.pattern); match != unit.match {
			fmt.Printf("isMatch(%v, %v) = %v != %v\n", unit.source, unit.pattern, match, unit.match)
		}
	}
}
