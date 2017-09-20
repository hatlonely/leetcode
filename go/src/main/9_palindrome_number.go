package main

import "fmt"

func isPalindrome(x int) bool {
	if x < 0 {
		return false
	}

	y := 0
	z := x
	for z != 0 {
		y *= 10
		y += z % 10
		z /= 10
	}
	return x == y
}

func main() {
	for _, unit := range []struct {
		x int
		b bool
	}{
		{12321, true},
		{-123321, false},
	} {
		if b := isPalindrome(unit.x); b != unit.b {
			fmt.Printf("isPalindrome(%v) = %v != %v\n", unit.x, b, unit.b)
		}
	}
}
