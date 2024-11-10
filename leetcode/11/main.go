package main

import "fmt"

func maxArea(height []int) int {
	max_area := 0

	for i := 0; i < len(height); i++ {
		for j := i + 1; j < len(height); j++ {
			area := min(height[i], height[j]) * (j - i)
			if area > max_area {
				max_area = area
			}
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
