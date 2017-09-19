package main

import (
	"fmt"
	"reflect"
)

func twoSum(nums []int, target int) []int {
	numIdxMap := map[int]int{}

	for i, num := range nums {
		if idx, ok := numIdxMap[target-num]; ok {
			return []int{idx, i}
		}
		numIdxMap[num] = i
	}

	return nil
}

func main() {
	for _, unit := range []struct {
		nums   []int
		target int
		twoSum []int
	}{
		{[]int{2, 7, 11, 15}, 9, []int{0, 1}},
		{[]int{3, 2, 7}, 6, nil},
	} {
		if target := twoSum(unit.nums, unit.target); !reflect.DeepEqual(target, unit.twoSum) {
			fmt.Printf("twoSum(%v, %v) = %v != %v", unit.nums, unit.target, target, unit.twoSum)
		}
	}
}
