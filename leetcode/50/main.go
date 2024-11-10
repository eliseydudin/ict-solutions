package main

import "fmt"

func pow_neg(x float64, n int) float64 {
	result := 1.0
	n2 := x * x

	for n >= 2 {
		result /= n2
		n -= 2
	}
	if n == 1 {
		result /= x
	}

	return result
}

func pow_pos(x float64, n int) float64 {
	result := 1.0
	n2 := x * x

	for n >= 2 {
		result *= n2
		n -= 2
	}
	if n == 1 {
		result *= x
	}

	return result
}

func myPow(x float64, n int) float64 {
	if n > 0 {
		return pow_pos(x, n)
	} else {
		return pow_neg(x, -n)
	}
}

func main() {
	var x float64
	var n int
	fmt.Scan(&x, &n)

	fmt.Printf("%.5f\n", myPow(x, n))
}
