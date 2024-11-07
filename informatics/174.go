// WARNING
// This solution doesn't work, however it does have the right algo :)
// I rewrote it in golang to have more fun writing the sources

package main

import "fmt"

func main() {
	n := 0
	ret := 0
	inp := 0

	fmt.Scanf("%d", &n)
	for i := 0; i <= n*n; i++ {
		fmt.Scanf("%d", &inp)
		ret += inp
	}

	fmt.Printf("%d\n", ret/2)
}
