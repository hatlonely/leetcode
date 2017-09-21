package main

import "fmt"

var kRomanIntMap = map[int]int{
	'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000,
}

func romanToInt(roman string) (num int) {
	l := len(roman)
	for i := range roman {
		n := kRomanIntMap[int(roman[i])]
		if i < l-1 && n < kRomanIntMap[int(roman[i+1])] {
			num -= n
		} else {
			num += n
		}
	}
	return num
}

func main() {
	for _, unit := range []struct {
		roman string
		num   int
	}{
		{"C", 100},
		{"MCMLXXX", 1980},
	} {
		if num := romanToInt(unit.roman); num != unit.num {
			fmt.Printf("intToRoman(%v) = %v != %v\n", unit.num, num, unit.roman)
		}
	}
}
