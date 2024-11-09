package main

import "fmt"

func twoSum(nums []int, target int) []int {
	result := make([]int, 2)
	m := make(map[int]int)

	for i, elem := range nums {

		val, ok := m[elem]

		if ok {
			result[0] = val
			result[1] = i
			return result
		} else {
			m[target-elem] = i
		}
	}

	return result
}

func main() {
	n := 0
	m := 0
	fmt.Scan(&n, &m)

	nums := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&nums[i])
	}

	fmt.Println(twoSum(nums, m))
}
