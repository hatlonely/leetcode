package main

import "fmt"

var kIntRomanMap = map[int]string{
	1: "I", 2: "II", 3: "III", 4: "IV", 5: "V", 6: "VI", 7: "VII", 8: "VIII", 9: "IX",
	10: "X", 20: "XX", 30: "XXX", 40: "XL", 50: "L", 60: "LX", 70: "LXX", 80: "LXXX", 90: "XC",
	100: "C", 200: "CC", 300: "CCC", 400: "CD", 500: "D", 600: "DC", 700: "DCC", 800: "DCCC", 900: "CM",
	1000: "M", 2000: "MM", 3000: "MMM",
	0: "",
}

func intToRoman(num int) (roman string) {
	return kIntRomanMap[num/1000*1000] + kIntRomanMap[(num%1000)/100*100] + kIntRomanMap[(num%100)/10*10] + kIntRomanMap[num%10]
}

func main() {
	for _, unit := range []struct {
		num   int
		roman string
	}{
		{100, "C"},
		{1980, "MCMLXXX"},
	} {
		if roman := intToRoman(unit.num); roman != unit.roman {
			fmt.Printf("intToRoman(%v) = %v != %v\n", unit.num, roman, unit.roman)
		}
	}
}
