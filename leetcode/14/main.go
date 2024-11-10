package main

import (
	"fmt"
	"sort"
)

func longestCommonPrefix(strs []string) string {
	sort.Strings(strs)

	first := strs[0]
	last := strs[len(strs)-1]
	min_length := min(len(first), len(last))

	i := 0
	for i < min_length && first[i] == last[i] {
		i += 1
		if i == 0 {
			return "-1"
		}
	}
	return first[:i]
}

func main() {
	var n int
	fmt.Scan(&n)

	strings := make([]string, n)
	for i := range strings {
		fmt.Scan(&strings[i])
	}

	fmt.Println(longestCommonPrefix(strings))
}
