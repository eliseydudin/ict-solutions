package main

import "strconv"

func count_ones(s string) int {
	count := 0
	for _, r := range s {
		if r == rune('1') {
			count++
		}
	}

	return count
}

func main() {
	count := 0

	for i := int64(1); i < 10000; i++ {
		base2 := strconv.FormatInt(i, 2)
		base4 := strconv.FormatInt(i, 4)

		if count_ones(base2) == 4 && count_ones(base4) == 4 {
			count++
		}
	}

	println(count)
}
