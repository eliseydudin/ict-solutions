package main

import "fmt"

func maxArea(height []int) int {
	max_area := 0
	max_height_prev := 0

	for i := 1; i < len(height); i++ {
		if min(height[max_height_prev], height[i])*(i-max_height_prev) > max_area {
			max_area = min(height[max_height_prev], height[i]) * (i - max_height_prev)
		}

		if height[i] > max_height_prev {
			max_height_prev = height[i]
		}
	}

	return max_area
}

func main() {
	var n int
	fmt.Scan(&n)
	arr := make([]int, n)

	for i := range arr {
		fmt.Scan(&arr[i])
	}

	fmt.Println(maxArea(arr))
}
