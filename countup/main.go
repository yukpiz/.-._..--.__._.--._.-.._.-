package main

import (
	"fmt"
)

func main() {
	n := 0
	fmt.Scan(&n)

	sum := 0
	for i := 1; i <= n; i++ {
		sum += i
	}

	fmt.Println(sum)
}
