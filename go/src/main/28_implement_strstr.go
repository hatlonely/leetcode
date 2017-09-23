package main

import (
	"fmt"
	"strings"
)

func strStr(source string, pattern string) int {
	return strings.Index(source, pattern)
}

func main() {
	for _, unit := range []struct {
		source  string
		pattern string
		index   int
	}{
		{"1234", "23", 1},
	} {
		if index := strStr(unit.source, unit.pattern); index != unit.index {
			fmt.Printf("strStr(%v, %v) = %v != %v\n", unit.source, unit.pattern, index, unit.index)
		}
	}
}
