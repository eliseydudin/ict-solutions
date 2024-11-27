package main

import "fmt"

func solve(num int, target int) int {
	if num > target {
		return 0
	} else if num == target {
		return 1
	}

	return solve(num+2, target) + solve(num*3, target)
}

func main() {
	fmt.Println(solve(1, 55))
}
