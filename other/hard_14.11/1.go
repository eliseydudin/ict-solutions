package main

import (
	"fmt"
	"math"
)

func solve(curr int, target int, caught14 bool) int {
	if curr == 14 {
		caught14 = true
	}
	if curr == 4 || curr == 43 {
		return 0
	}
	if curr < target {
		return 0
	}
	if curr == target {
		if caught14 {
			return 1
		} else {
			return 0
		}
	}

	return solve(curr-1, target, caught14) + solve(curr/3, target, caught14) + solve(int(math.Floor(math.Sqrt(float64(curr)))), target, caught14)
}

func main() {
	fmt.Println(solve(98, 2, false))
}
