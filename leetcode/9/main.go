package main

import (
	"fmt"
	"strconv"
)

func isPalindrome(x int) bool {
	var as_str = strconv.Itoa(x)
	var str_len = len(as_str)

	for i := 0; i < str_len/2+1; i++ {
		if as_str[i] != as_str[str_len-i-1] {
			return false
		}
	}

	return true
}

func main() {
	var n int
	fmt.Scan(&n)

	fmt.Println(isPalindrome(n))
}
