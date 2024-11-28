package main

import "fmt"

func gcd(a, b int) int {
	for a != b {
		if a > b {
			a -= b
		} else {
			b -= a
		}
	}

	return a
}

func both_simple(num1, num2 int) bool {
	if num2 == -1 {
		return true
	}

	return gcd(num1, num2) == 1
}

func solve(num, target, last int) int {
	if num > target || !both_simple(num, last) {
		return 0
	} else if num == target {
		return 1
	}

	return solve(num+1, target, num) + solve(num+3, target, num) + solve(num+7, target, num)
}

func main() {
	fmt.Println(solve(13, 31, -1))
}
