package main

import (
	"fmt"
	"math"
	"sort"
)

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func threeSumClosest(nums []int, target int) int {
	sort.Ints(nums)
	l := len(nums)

	closest := math.MaxInt32

	for i := 0; i < l; i++ {
		idx1 := i + 1
		idx2 := l - 1

		for idx1 < idx2 {
			diff := nums[i] + nums[idx1] + nums[idx2] - target
			if abs(diff) < abs(closest) {
				closest = diff
			}
			if diff < 0 {
				idx1++
			} else if diff > 0 {
				idx2--
			} else {
				return target
			}
		}
	}

	return target + closest
}

func main() {
	for _, unit := range []struct {
		nums   []int
		target int
		sum    int
	}{
		{[]int{-1, 2, 1, -4}, 1, 2},
		{[]int{0, 0, 0}, 1, 0},
	} {
		if sum := threeSumClosest(unit.nums, unit.target); sum != unit.sum {
			fmt.Printf("threeSumClosest(%v, %v) = %v != %v\n", unit.nums, unit.target, sum, unit.sum)
		}
	}
}
