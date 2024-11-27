package main

import "fmt"

func solve(num int, target int) int {
	if num > target {
		return 0
	} else if num == target {
		return 1
	}

	sum := solve(num+1, target)
	if num%2 == 0 {
		sum += solve(int(float64(num)*1.5), target)
	}

	return sum
}

func main() {
	fmt.Println(solve(1, 20))
}
