package main

import (
	"fmt"
	"reflect"
)

func twoSum(nums []int, target int) []int {
	numIdxMap := map[int]int{}

	for i := 0; i < len(nums); i++ {
		num := nums[i]
		if idx, ok := numIdxMap[target-num]; ok {
			return []int{idx, i}
		}
		numIdxMap[num] = i
	}

	return nil
}

func main() {
	for _, item := range []struct {
		nums   []int
		target int
		twoSum []int
	}{
		{[]int{2, 7, 11, 15}, 9, []int{0, 1}},
	} {
		if !reflect.DeepEqual(twoSum(item.nums, item.target), item.twoSum) {
			fmt.Printf("twoSum(%v, %v) != %v", item.nums, item.target, item.twoSum)
		}
	}
}
