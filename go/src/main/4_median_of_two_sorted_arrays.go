package main

import "fmt"

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	nums := make([]int, len(nums1)+len(nums2))
	idx1 := 0
	idx2 := 0
	idx := 0

	for idx1 < len(nums1) && idx2 < len(nums2) {
		if nums1[idx1] < nums2[idx2] {
			nums[idx] = nums1[idx1]
			idx1++
		} else {
			nums[idx] = nums2[idx2]
			idx2++
		}
		idx++
	}

	for idx1 < len(nums1) {
		nums[idx] = nums1[idx1]
		idx1++
		idx++
	}

	for idx2 < len(nums2) {
		nums[idx] = nums2[idx2]
		idx2++
		idx++
	}

	if len(nums)%2 == 0 {
		return float64(nums[len(nums)/2]+nums[len(nums)/2-1]) / 2
	} else {
		return float64(nums[len(nums)/2])
	}
}

func main() {
	for _, unit := range []struct {
		nums1  []int
		nums2  []int
		median float64
	}{
		{[]int{1, 3}, []int{2}, 2.0},
		{[]int{1, 2}, []int{3, 4}, 2.5},
	} {
		if median := findMedianSortedArrays(unit.nums1, unit.nums2); median != unit.median {
			fmt.Printf("findMedianSortedArrays(%v, %v) = %v != %v\n", unit.nums1, unit.nums2, median, unit.median)
		}
	}
}
