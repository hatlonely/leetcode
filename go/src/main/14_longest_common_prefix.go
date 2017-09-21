package main

import "fmt"

func longestCommonPrefix(strs []string) string {
	if len(strs) == 0 {
		return ""
	}

	str1 := strs[0]
	for i := 1; i < len(strs); i++ {
		str2 := strs[i]
		idx := 0
		for idx < len(str1) && idx < len(str2) && str1[idx] == str2[idx] {
			idx++
		}
		str1 = str1[:idx]
	}

	return str1
}

func main() {
	for _, unit := range []struct {
		strs   []string
		prefix string
	}{
		{[]string{"abc", "abcd", "ab"}, "ab"},
	} {
		if prefix := longestCommonPrefix(unit.strs); prefix != unit.prefix {
			fmt.Printf("longestCommonPrefix(%v) = %v != %v\n", unit.strs, prefix, unit.prefix)
		}
	}
}
