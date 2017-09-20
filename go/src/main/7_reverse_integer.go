package main

import (
	"fmt"
	"math"
)

func reverse(x int) (y int) {
	y = 0
	for x != 0 {
		y *= 10
		y += x % 10
		x /= 10
	}

	if y > math.MaxInt32 || y < math.MinInt32 {
		return 0
	}

	return y
}

func main() {
	for _, unit := range []struct {
		x int
		y int
	}{
		{8, 8},
		{123, 321},
	} {
		if y := reverse(unit.x); y != unit.y {
			fmt.Printf("reverse(%v) = %v != %v\n", unit.x, y, unit.y)
		}
	}
}
