package main

import "fmt"

func solve(num int, target int, caught20 bool) int {
	if num == 16 || num > target {
		return 0
	} else if num == target && caught20 {
		return 1
	}

	if num == 20 {
		caught20 = true
	}

	return solve(num+1, target, caught20) + solve(num+3, target, caught20) + solve(num*num, target, caught20)
}

func main() {
	fmt.Println(solve(3, 26, false))
}
