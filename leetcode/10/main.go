package main

import "fmt"

func isMatch(s string, p string) bool {
	m := len(s)
	n := len(p)

	cache := make([][]bool, m+1)
	for i := range cache {
		cache[i] = make([]bool, n+1)
	}
	cache[0][0] = true

	isMatch := func(i, j int) bool {
		return j >= 0 && (p[j] == '.' || s[i] == p[j])
	}

	for j := 0; j < n; j++ {
		if p[j] == '*' && cache[0][j-1] {
			cache[0][j+1] = true
		}
	}

	for i := range m {
		for j := range n {
			if p[j] == '*' {
				no_rep := cache[i+1][j-1]
				do_rep := isMatch(i, j-1) && cache[i][j+1]
				cache[i+1][j+1] = no_rep || do_rep
			} else if isMatch(i, j) {
				cache[i+1][j+1] = cache[i][j]
			}
		}
	}

	return cache[m][n]
}

func main() {
	var s, p string
	fmt.Scan(&s, &p)
	fmt.Println(isMatch(s, p))
}
