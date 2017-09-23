package main

import (
	"fmt"
	"math"
)

func divideRecursive(a int, b int) int {
	if a < 0 {
		if b < 0 {
			return divideRecursive(-a, -b)
		} else {
			return -divideRecursive(-a, b)
		}
	}
	if b < 0 {
		return -divideRecursive(a, -b)
	}

	if a < b {
		return 0
	}

	c := 1
	d := b
	for a > d*2 {
		d *= 2
		c *= 2
		if c > math.MaxInt32+1 {
			return math.MaxInt32 + 1
		}
	}

	return c + divideRecursive(a-d, b)
}

func divide(a int, b int) int {
	c := divideRecursive(a, b)
	if c > math.MaxInt32 {
		return math.MaxInt32
	}
	if c < math.MinInt32 {
		return math.MinInt32
	}
	return c
}

func main() {
	for _, unit := range []struct {
		a int
		b int
		c int
	}{
		{3, 2, 1},
		{-1, 1, -1},
		{-2147483648, -1, 2147483647},
		{-2147483648, 1, -2147483648},
	} {
		if c := divide(unit.a, unit.b); c != unit.c {
			fmt.Printf("divide(%v, %v) = %v != %v\n", unit.a, unit.b, c, unit.c)
		}
	}
}
