package main

import "fmt"

func get_div_sum(num int) int {
	sum := 0

	for i := 1; i <= num; i++ {
		if num%i == 0 {
			sum += i
		}
	}

	return sum
}

func solve(num int, target int) int {
	if num == target {
		return 1
	}

	if num > target {
		return 0
	}

	return solve(num+1, target) + solve(get_div_sum(num), target)
}

func main() {
	fmt.Println(solve(2, 24))
}
