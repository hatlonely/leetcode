package main

import (
	"fmt"
	"reflect"
)

func reverseNums(nums []int, startIdx int) {
	l := len(nums)
	for i := startIdx; i < (l-startIdx)/2+startIdx; i++ {
		temp := nums[i]
		nums[i] = nums[l+startIdx-i-1]
		nums[l+startIdx-i-1] = temp
	}
}

func nextPermutation(nums []int) {
	l := len(nums)
	i := l - 2
	for ; i >= 0 && nums[i] >= nums[i+1]; i-- {
	}
	if i == -1 {
		reverseNums(nums, 0)
		return
	}

	j := l - 1
	for ; j > i && nums[i] >= nums[j]; j-- {
	}

	temp := nums[i]
	nums[i] = nums[j]
	nums[j] = temp

	reverseNums(nums, i+1)
}

func main() {
	for _, unit := range []struct {
		nums []int
		next []int
	}{
		{[]int{1, 2, 3}, []int{1, 3, 2}},
		{[]int{1, 3, 2}, []int{2, 1, 3}},
		{[]int{3, 2, 1}, []int{1, 2, 3}},
		{[]int{5, 1, 1}, []int{1, 1, 5}},
	} {
		nextPermutation(unit.nums)
		if !reflect.DeepEqual(unit.nums, unit.next) {
			fmt.Printf("nextPermutation() %v != %v\n", unit.nums, unit.next)
		}
	}
}
