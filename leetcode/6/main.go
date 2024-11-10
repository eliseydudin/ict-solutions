package main

import (
	"fmt"
	"strings"
)

func convert(s string, numRows int) string {
	if numRows == 1 || len(s) <= numRows {
		return s
	}

	var answer = strings.Builder{}
	var s_len = len(s)
	cycle_length := 2*numRows - 2

	for i := 0; i < s_len; i += cycle_length {
		answer.WriteByte(s[i])
	}

	for r := 1; r <= numRows-2; r++ {
		answer.WriteByte(s[r])

		for k := cycle_length; k-r < len(s); k += cycle_length {
			answer.WriteByte(s[k-r])
			if k+r < len(s) {
				answer.WriteByte(s[k+r])
			}
		}
	}

	for i := numRows - 1; i < len(s); i += cycle_length {
		answer.WriteByte(s[i])
	}

	return answer.String()
}

func main() {
	var s string
	var n int

	fmt.Scan(&n, &s)

	fmt.Println(convert(s, n))
}
