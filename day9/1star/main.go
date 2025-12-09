package main

import (
	"1star/utils"
	"fmt"
)

func main() {
	macierz := utils.ReadFile("input.txt")
	// fmt.Println(macierz)
	var max = -1
	for _, p := range macierz {
		for _, q := range macierz {
			if p == q {
				continue
			}
			// to make it faster can implement hashmap
			// to not calculate same points twice

			// or maybe just start calculating from corners?
			area := p.CalcArea(q)
			// fmt.Println(p, q, area)
			if max < area {
				max = area
			}
		}
	}
	fmt.Println("MAX: ", max)
}
