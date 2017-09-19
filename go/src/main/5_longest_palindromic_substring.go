package main

import "fmt"

func longestPalindrome(str string) (palindrome string) {
	maxlen := 0
	for i := range str {
		{
			j := 1
			for i-j >= 0 && i+j < len(str) && str[i-j] == str[i+j] {
				j++
			}
			j--
			if maxlen < 2*j+1 {
				maxlen = 2*j + 1
				palindrome = str[i-j : i+j+1]
			}
		}
		{
			j := 1
			for i-j+1 >= 0 && i+j < len(str) && str[i-j+1] == str[i+j] {
				j++
			}
			j--
			if maxlen < 2*j {
				maxlen = 2 * j
				palindrome = str[i-j+1 : i+j+1]
			}
		}
	}

	return palindrome
}

func main() {
	for _, unit := range []struct {
		str        string
		palindrome string
	}{
		{"babad", "bab"},
		{"cbbd", "bb"},
	} {
		if palindrome := longestPalindrome(unit.str); palindrome != unit.palindrome {
			fmt.Printf("longestPalindrome(%v) = %v != %v\n", unit.str, palindrome, unit.palindrome)
		}
	}
}
