package main

import (
	"fmt"
)

func longestValidParentheses(str string) int {
	strlen := len(str)
	nums := make([]int, strlen+1)
	nums[0] = 5
	for i := 0; i < strlen; i++ {
		if str[i] == '(' {
			nums[i+1] = nums[i] + 1
		} else {
			nums[i+1] = nums[i] - 1
		}
	}

	maxLen := 0
	for i := 0; i < strlen; {
		for i < strlen && nums[i] > nums[i+1] {
			i++
		}
		val := nums[i]
		length := 0
		for ; i <= strlen && nums[i] >= val; i++ {
			if nums[i] == val {
				if maxLen < length {
					maxLen = length
				}
			}
			length += 1
		}
	}

	for i := strlen; i > 0; {
		for i > 0 && nums[i] > nums[i-1] {
			i--
		}
		val := nums[i]
		length := 0
		for ; i >= 0 && nums[i] >= val; i-- {
			if nums[i] == val {
				if maxLen < length {
					maxLen = length
				}
			}
			length += 1
		}
	}

	return maxLen
}

func main() {
	for _, unit := range []struct {
		str    string
		length int
	}{
		{"", 0},
		{")", 0},
		{"()", 2},
		{"(()", 2},
		{")()())", 4},
		{")()()(", 4},
		{")(((((()())()()))()(()))(", 22},
		{"))))())()()(()", 4},
	} {
		if length := longestValidParentheses(unit.str); length != unit.length {
			fmt.Printf("longestValidParentheses(%v) = %v != %v\n", unit.str, length, unit.length)
		}
	}
}
