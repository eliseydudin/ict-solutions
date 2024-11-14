package main

import (
	"fmt"
)

var cache = make(map[[2]int]int)

func deof(n, s int) int {
	if n == 1 {
		if s >= 0 && s <= 9 {
			return 1
		}
		return 0
	}

	key := [2]int{n, s}
	if val, exists := cache[key]; exists {
		return val
	}

	total := 0
	for i := 0; i < 10; i++ {
		total += deof(n-1, s-i)
	}

	cache[key] = total
	return total
}

func calc(n int) int {
	total := 0
	for i := 0; i <= 9*(n/2); i++ {
		total += deof(n/2, i) * deof(n/2, i)
	}
	return total
}

func main() {
	var n int
	fmt.Scan(&n)
	fmt.Println(calc(n))
}
