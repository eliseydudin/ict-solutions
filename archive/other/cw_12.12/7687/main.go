package main

import (
	"fmt"
)

func solve(current int, goal int) int {
	if current < goal {
		return 0
	} else if current == goal {
		return 1
	}

	result := 0
	result += solve(current-3, goal)

	if current%2 == 0 {
		result += solve(current/3, goal)
	}

	if current/10 > 0 {
		result += solve(current/10, goal)
	}

	return result
}

func main() {
	fmt.Println(solve(1250, 20))
}
