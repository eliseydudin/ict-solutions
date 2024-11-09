package main

import (
	"fmt"
	"strings"
)

type BData struct {
	size int
	data []byte
}

func intToRoman(num int) string {
	var builder strings.Builder

	var runes = []BData{
		{1000, []byte{'M'}},
		{900, []byte{'C', 'M'}},
		{500, []byte{'D'}},
		{400, []byte{'C', 'D'}},
		{100, []byte{'C'}},
		{90, []byte{'X', 'C'}},
		{50, []byte{'L'}},
		{40, []byte{'X', 'L'}},
		{10, []byte{'X'}},
		{9, []byte{'I', 'X'}},
		{5, []byte{'V'}},
		{4, []byte{'I', 'V'}},
		{1, []byte{'I'}},
	}

	for _, s := range runes {
		for num >= s.size {
			num -= s.size
			builder.Write(s.data)
		}
	}

	return builder.String()
}

func main() {
	var n int
	fmt.Scan(&n)

	fmt.Println(intToRoman(n))
}
