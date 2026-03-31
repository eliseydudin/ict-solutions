package main

const N = 20

func get_in_base(base int) int {
	return base*base + base*2 + 3
}

func main() {
	solution := 0
	for base := 4; base <= N; base++ {
		solution += get_in_base(base)
	}

	println(solution)
}

// solution: 2872
