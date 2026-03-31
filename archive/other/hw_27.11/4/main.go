package main

import "fmt"

func solve(num int, target int, caught19 bool, caught16 bool) int {
	if num < target {
		return 0
	}

	if num == 19 {
		caught19 = true
	} else if num == 16 {
		caught16 = true
	}

	if caught16 && caught19 && num == target {
		return 1
	}

	return solve(num-1, target, caught19, caught16) + solve(num-3, target, caught19, caught16) + solve(num/2, target, caught19, caught16)
}

func main() {
	fmt.Println(solve(39, 7, false, false))
}
