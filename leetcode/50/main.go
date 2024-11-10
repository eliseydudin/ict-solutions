package main

import "fmt"

func myPow(x float64, n int) float64 {
	if n == 0 {
		return 1.0
	} else if n < 0 {
		return 1 / myPow(x, -n)
	} else if n%2 == 1 {
		return x * myPow(x, n-1)
	}

	return myPow(x*x, n/2)
}

func main() {
	var x float64
	var n int
	fmt.Scan(&x, &n)

	fmt.Printf("%.5f\n", myPow(x, n))
}
