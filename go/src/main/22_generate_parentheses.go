package main

import (
	"fmt"
	"reflect"
)

func generateParenthesisRecursive(prefix string, l, r int) (parenthesis []string) {
	if l == 0 && r == 0 {
		return []string{prefix}
	}
	if l > r || l < 0 || r < 0 {
		return []string{}
	}
	parenthesis = generateParenthesisRecursive(prefix+"(", l-1, r)
	for _, parenthes := range generateParenthesisRecursive(prefix+")", l, r-1) {
		parenthesis = append(parenthesis, parenthes)
	}
	return parenthesis
}

func generateParenthesis(n int) []string {
	return generateParenthesisRecursive("", n, n)
}

func main() {
	for _, unit := range []struct {
		n           int
		parenthesis []string
	}{
		{1, []string{"()"}},
		{3, []string{"((()))", "(()())", "(())()", "()(())", "()()()"}},
	} {
		if parenthesis := generateParenthesis(unit.n); !reflect.DeepEqual(parenthesis, unit.parenthesis) {
			fmt.Printf("generateParenthesis(%v) = %v != %v\n", unit.n, parenthesis, unit.parenthesis)
		}
	}
}
