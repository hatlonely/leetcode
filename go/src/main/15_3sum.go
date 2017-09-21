package main

import (
	"fmt"
	"reflect"
	"sort"
)

func threeSum(nums []int) (sums [][]int) {
	sort.Ints(nums)
	l := len(nums)

	for i := 0; i < l-1; i++ {
		idx1 := i + 1
		idx2 := l - 1

		for idx1 < idx2 {
			if nums[idx1]+nums[idx2]+nums[i] < 0 {
				idx1++
			} else if nums[idx1]+nums[idx2]+nums[i] > 0 {
				idx2--
			} else {
				sums = append(sums, []int{nums[i], nums[idx1], nums[idx2]})
				for idx1 < idx2 && nums[idx1] == nums[idx1+1] {
					idx1++
				}
				for idx2 > idx1 && nums[idx2] == nums[idx2-1] {
					idx2--
				}
				idx1++
				idx2--
			}
		}
		for ; i < l-1 && nums[i] == nums[i+1]; i++ {
		}
	}

	return sums
}

func main() {
	for _, unit := range []struct {
		nums []int
		sums [][]int
	}{
		{[]int{-1, 0, 1, 2, -1, -4}, [][]int{{-1, -1, 2}, {-1, 0, 1}}},
		{[]int{0, 0, 0}, [][]int{{0, 0, 0}}},
		{[]int{0, 0, 0, 0}, [][]int{{0, 0, 0}}},
		{[]int{-1, 0, 1, 0}, [][]int{{-1, 0, 1}}},
	} {
		if sums := threeSum(unit.nums); !reflect.DeepEqual(sums, unit.sums) {
			fmt.Printf("threeSum(%v) = %v != %v\n", unit.nums, sums, unit.sums)
		}
	}
}
