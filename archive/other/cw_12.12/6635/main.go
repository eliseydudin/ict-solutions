package main

import "fmt"

var used_solutions = make(map[int]struct{})

func solve(current int, commands int) int {
	_, found := used_solutions[current]
	if commands == 0 && current < 0 && !found {
		used_solutions[current] = struct{}{}
		return 1
	} else if commands == 0 {
		return 0
	}

	commands -= 1
	return solve(current-3, commands) + solve(current*(-3), commands)
}

func main() {
	fmt.Println(solve(333, 13))
}
