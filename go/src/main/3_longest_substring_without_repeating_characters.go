package main

import "fmt"

func lengthOfLongestSubstring(str string) int {
	cset := map[int32]bool{}
	max := 0
	cnt := 0
	idx := 0
	for _, c := range str {
		if _, ok := cset[c]; ok {
			if max < cnt {
				max = cnt
			}
			for int32(str[idx]) != c {
				delete(cset, int32(str[idx]))
				idx++
				cnt--
			}
			idx++
			cnt--
		}
		cset[c] = true
		cnt++
	}
	if max < cnt {
		max = cnt
	}

	return max
}

func main() {
	for _, unit := range []struct {
		str    string
		length int
	}{
		{"abcabcbb", 3},
		{"bbbbb", 1},
		{"pwwkew", 3},
		{"c", 1},
	} {
		if length := lengthOfLongestSubstring(unit.str); length != unit.length {
			fmt.Printf("lengthOfLongestSubstring(%v) = %v != %v\n", unit.str, length, unit.length)
		}
	}
}
