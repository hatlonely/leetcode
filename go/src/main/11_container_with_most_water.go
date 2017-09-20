package main

import "fmt"

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func maxAreaRecursive(height *[]int, l int) (area int) {
	if l <= 1 {
		return 0
	}
	for i := range *height {
		area = max(area, (l-i-1)*min((*height)[i], (*height)[l-1]))
	}

	return max(area, maxAreaRecursive(height, l-1))
}

func maxArea(height []int) (area int) {
	return maxAreaRecursive(&height, len(height))
}

func main() {
	for _, unit := range []struct {
		height []int
		area   int
	}{
		{[]int{1, 2}, 1},
		{[]int{1, 1}, 1},
	} {
		if area := maxArea(unit.height); area != unit.area {
			fmt.Printf("maxArea(%v) = %v != %v\n", unit.height, area, unit.area)
		}
	}
}
