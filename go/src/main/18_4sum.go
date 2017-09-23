package main

import (
	"fmt"
	"reflect"
	"sort"
)

func fourSum(nums []int, target int) (sums [][]int) {
	sort.Ints(nums)
	l := len(nums)
	for i := 0; i < l-2; i++ {
		for j := i + 1; j < l-1; j++ {
			idx1 := j + 1
			idx2 := l - 1
			for idx1 < idx2 {
				total := nums[i] + nums[j] + nums[idx1] + nums[idx2]
				if total < target {
					idx1++
				} else if total > target {
					idx2--
				} else {
					sums = append(sums, []int{nums[i], nums[j], nums[idx1], nums[idx2]})
					for idx1 < idx2 && nums[idx1] == nums[idx1+1] {
						idx1++
					}
					for idx1 < idx2 && nums[idx2] == nums[idx2-1] {
						idx2--
					}
					idx1++
					idx2--
				}
			}
			for j < l-1 && nums[j] == nums[j+1] {
				j++
			}
		}
		for i < l-2 && nums[i] == nums[i+1] {
			i++
		}
	}

	return sums
}

func main() {
	for _, unit := range []struct {
		nums   []int
		target int
		sums   [][]int
	}{
		{[]int{1, 0, -1, 0, -2, 2}, 0, [][]int{{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}}},
	} {
		if sums := fourSum(unit.nums, unit.target); !reflect.DeepEqual(sums, unit.sums) {
			fmt.Printf("fourSum(%v, %v) = %v != %v\n", unit.nums, unit.target, sums, unit.sums)
		}
	}
}
