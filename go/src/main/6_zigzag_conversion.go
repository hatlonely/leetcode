package main

import "fmt"

func convert(str string, n int) (zigzag string) {
	if n == 1 {
		return str
	}

	m := 2*n - 2
	for j := 0; j < len(str); j += m {
		zigzag += string(str[j])
	}
	for i := 1; i < n-1; i++ {
		j := 0
		for ; j+m-i < len(str); j += m {
			zigzag += string(str[j+i])
			zigzag += string(str[j+m-i])
		}
		if j+i < len(str) {
			zigzag += string(str[j+i])
		}
	}
	for j := n - 1; j < len(str); j += m {
		zigzag += string(str[j])
	}

	return zigzag
}

func main() {
	for _, unit := range []struct {
		str    string
		n      int
		zigzag string
	}{
		{"PAYPALISHIRING", 3, "PAHNAPLSIIGYIR"},
		{"0123456789", 3, "0481357926"},
		{"A", 1, "A"},
	} {
		if zigzag := convert(unit.str, unit.n); zigzag != unit.zigzag {
			fmt.Printf("convert(%v, %v) = %v != %v\n", unit.str, unit.n, zigzag, unit.zigzag)
		}
	}
}
