package main

import "fmt"

func romanToInt(s string) int {
	var values = map[byte]int{
		'I': 1,
		'V': 5,
		'X': 10,
		'L': 50,
		'C': 100,
		'D': 500,
		'M': 1000,
	}

	res := 0
	i := 0

	for i < len(s) {
		s1 := values[s[i]]

		if i+1 < len(s) {
			s2 := values[s[i+1]]
			if s1 >= s2 {
				res += s1
			} else {
				res += (s2 - s1)
				i++
			}
		} else {
			res += s1
		}
		i++
	}

	return res
}

func main() {
	var input string
	fmt.Scan(&input)

	fmt.Println(romanToInt(input))
}
