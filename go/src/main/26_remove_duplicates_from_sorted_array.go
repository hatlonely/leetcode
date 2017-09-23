package main

import "fmt"

func removeDuplicates(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	l := len(nums)
	j := 1
	for i := 1; i < l; i++ {
		if nums[i] != nums[i-1] {
			nums[j] = nums[i]
			j++
		}
	}
	return j
}

func main() {
	for _, unit := range []struct {
		nums   []int
		length int
	}{
		{[]int{1, 1, 2}, 2},
	} {
		if length := removeDuplicates(unit.nums); length != unit.length {
			fmt.Printf("removeDuplicates(%v) = %v != %v\n", unit.nums, length, unit.length)
		}
	}
}
