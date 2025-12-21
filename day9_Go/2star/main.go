package main

import (
	"2star/utils"
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

			area := p.CalcArea(q)
			// fmt.Println(p, q, area)
			if max < area {
				max = area
			}
		}
	}
	fmt.Println("MAX: ", max)
}
