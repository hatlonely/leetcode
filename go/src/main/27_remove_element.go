package main

import "fmt"

func removeElement(nums []int, val int) int {
	j := 0
	for i := 0; i < len(nums); i++ {
		if nums[i] != val {
			nums[j] = nums[i]
			j++
		}
	}
	return j
}

func main() {
	for _, unit := range []struct {
		nums   []int
		val    int
		length int
	}{
		{[]int{3, 2, 2, 3}, 3, 2},
	} {
		if length := removeElement(unit.nums, unit.val); length != unit.length {
			fmt.Printf("removeElement(%v, %v) = %v != %v\n", unit.nums, unit.val, length, unit.length)
		}
	}
}
