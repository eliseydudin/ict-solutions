package main

import "sort"

func threeSum(nums []int) [][]int {
	length := len(nums)
	sort.Ints(nums)

	var result [][]int
	for i1 := 0; i1 < length-2; i1++ {
		if i1 > 0 && nums[i1] == nums[i1-1] {
			continue
		}

		i2 := i1 + 1
		i3 := length - 1
		for i2 < i3 {
			sum := nums[i2] + nums[i3] + nums[i1]
			if sum == 0 {
				// Add triplet to result
				result = append(result, []int{nums[i1], nums[i2], nums[i3]})
				i2++
				i3--

				for i2 < i3 && nums[i3] == nums[i3+1] {
					i3--
				}
				for i2 < i3 && nums[i2] == nums[i2-1] {
					i2++
				}
			} else if sum > 0 {
				i3--
			} else {
				i2++
			}
		}
	}
	return result
}

func main() {
	// i was too lazy
}
