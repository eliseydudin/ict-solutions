package main

import "fmt"

/*
def longestUniqueSubstr(s):
    n = len(s)
    res = 0
    last_index = [-1] * 256
    start = 0
    for end in range(n):
        res = max(res, end - start + 1)
        last_index[ord(s[end])] = end

    return res
*/

func lengthOfLongestSubstring(s string) int {
	n := len(s)
	res := 0

	last_index := make([]int, 256)
	for i := 0; i < 256; i++ {
		last_index[i] = -1
	}

	start := 0

	for end := 0; end < n; end++ {
		start = max(start, last_index[s[end]]+1)
		res = max(res, end-start+1)
		last_index[s[end]] = end
	}

	return res
}

func main() {
	s := ""
	fmt.Scan(&s)

	fmt.Println(lengthOfLongestSubstring(s))
}
