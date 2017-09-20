package main

import (
	"fmt"
	"math"
)

func myAtoi(str string) (num int) {
	if len(str) == 0 {
		return 0
	}

	for i := range str {
		if str[i] != ' ' {
			str = str[i:]
			break
		}
	}

	factor := 1
	if str[0] == '+' {
		str = str[1:]
		factor = 1
	} else if str[0] == '-' {
		str = str[1:]
		factor = -1
	}

	for _, c := range str {
		if c < '0' || c > '9' {
			break
		}
		num *= 10
		num += int(c - '0')
		if num > math.MaxInt32 {
			if factor > 0 {
				return math.MaxInt32
			} else {
				return math.MinInt32
			}
		}
	}

	return num * factor
}

func main() {
	for _, unit := range []struct {
		str string
		i   int
	}{
		{"123", 123},
		{"+", 0},
		{"", 0},
		{"  123", 123},
		{"-2147483648", -2147483648},
		{"2147483648", 2147483647},
		{"9223372036854775809", 2147483647},
	} {
		if i := myAtoi(unit.str); i != unit.i {
			fmt.Printf("myAtoi(%v) = %v != %v\n", unit.str, i, unit.i)
		}
	}
}
