package main

import "fmt"

func maxArea(height []int) int {
	n := len(height)
	max_area := 0
	left, right := 0, n-1

	for left < right {

		max_area = max(max_area, min(height[left],
			height[right])*(right-left))

		if height[left] < height[right] {
			left++
		} else {
			right--
		}
	}

	return max_area
}

func main() {
	var n int
	fmt.Scan(&n)
	height := make([]int, n)

	for i := range height {
		fmt.Scan(&height[i])
	}

	fmt.Println(maxArea(height))
}
