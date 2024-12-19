package main

import "fmt"

type Pair struct {
	first  int
	second int
}

func main() {
	var n int
	fmt.Scan(&n)

	arr := make([]Pair, n+1)
	arr[1].first = 1
	arr[1].second = 1

	for i := 2; i <= n; i++ {
		arr[i].first = arr[i-1].second
		arr[i].second = arr[i-1].first + arr[i-1].second
	}

	fmt.Println(arr[n].first + arr[n].second)
}
