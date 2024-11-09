package main

import (
	"fmt"
)

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	nums := combine(nums1, nums2)
	return median(nums)
}

func combine(mis, njs []int) []int {
	i, j := 0, 0
	len_m := len(mis)
	len_n := len(njs)
	res := make([]int, len_m+len_n)

	for k := 0; k < len_m+len_n; k++ {
		if i == len_m ||
			(i < len_m && j < len_n && mis[i] > njs[j]) {
			res[k] = njs[j]
			j++
			continue
		}

		if j == len_n ||
			(i < len_m && j < len_n && mis[i] <= njs[j]) {
			res[k] = mis[i]
			i++
		}
	}

	return res
}

func median(nums []int) float64 {
	l := len(nums)
	if l%2 == 0 {
		return float64(nums[l/2]+nums[l/2-1]) / 2.0
	}
	return float64(nums[l/2])
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	nums1 := make([]int, n)
	nums2 := make([]int, m)

	for i := 0; i < n; i++ {
		fmt.Scan(&nums1[i])
	}

	for i := 0; i < m; i++ {
		fmt.Scan(&nums2[i])
	}

	fmt.Println(findMedianSortedArrays(nums1, nums2))
}
