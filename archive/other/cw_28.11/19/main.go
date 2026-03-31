package main

import "fmt"

var result = make(map[int]struct{})

func is_odd(num int) bool {
	return num%2 != 0
}

func to_int(arg bool) int {
	if arg {
		return 1
	} else {
		return 0
	}
}

func solve(num int) int {
	if num < 100 {
		if is_odd(num) && num != 1 {
			result[num] = struct{}{}
		}

		solve(num + 3)
		solve(num * 3)
	}

	return len(result)
}

func main() {
	fmt.Println(solve(1))
}
