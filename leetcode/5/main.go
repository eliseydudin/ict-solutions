package main

import "fmt"

func longestPalindrome(s string) string {
	n := len(s)
	if n == 0 {
		return ""
	}

	start, max_len := 0, 1

	for i := range n {
		for j := range 2 {
			low := i
			high := i + j
			for low >= 0 && high < n && s[low] == s[high] {
				curr_len := high - low + 1
				if curr_len > max_len {
					start = low
					max_len = curr_len
				}
				low--
				high++
			}
		}
	}

	return s[start : start+max_len]
}

func main() {
	var s string
	fmt.Scan(&s)
	fmt.Println(longestPalindrome(s))
}
