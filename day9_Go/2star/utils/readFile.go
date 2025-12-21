package utils

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Punkt [2]int
type TwoPoints [2]Punkt

func (p Punkt) MniejszyNiz(q Punkt) bool {
	if p[0] != q[0] {
		return p[0] < q[0]
	}
	return p[1] < q[1]

}

func (p Punkt) CalcArea(q Punkt) int {
	var totalX int
	var totalY int
	if p[0] >= q[0] {
		totalX = p[0] - q[0] + 1 // wazne +1
	} else {
		totalX = q[0] - p[0] + 1
	}
	if p[1] >= q[1] {
		totalY = p[1] - q[1] + 1 // wazne +1
	} else {
		totalY = q[1] - p[1] + 1
	}
	return totalX * totalY
}

func ReadFile(filePath string) []Punkt {
	dane, err := os.ReadFile(filePath)
	var pointsCombined []Punkt
	if err != nil {
		fmt.Println("No file found in", filePath)
		return pointsCombined
	}
	linie := strings.Split(string(dane), "\n")
	for _, linia := range linie {
		line_splitted := strings.Split(linia, ",")
		var punkt Punkt
		for i, liczba_string := range line_splitted {
			liczba, err := strconv.Atoi(strings.TrimSpace(liczba_string))
			if err != nil {
				fmt.Println("No value")
				return pointsCombined
			}
			punkt[i] = liczba
		}
		pointsCombined = append(pointsCombined, punkt)

	}
	return pointsCombined
}
