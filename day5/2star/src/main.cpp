#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <set>
#include <algorithm>
#include "readFile.h"


int main(){
    std::string linia;
    std::vector<Zakres> zakresy;
    std::vector<long long int> liczby;
    std::set<int> unikalne;
    wczytajDane("input.txt", zakresy, liczby);
    std::sort(zakresy.begin(), zakresy.end(), [](const Zakres& a, const Zakres& b) {
        return a.x < b.x;
    });
    long long int obecny_start = zakresy[0].x;
    long long int obecny_koniec = zakresy[0].y;
    long long int suma_unikalnych = 0;

    if (zakresy.empty()) {
        return 0;
    }

    for (size_t i = 1; i < zakresy.size(); i++) {
        const auto& z = zakresy[i];
        if (z.x <= obecny_koniec){
            obecny_koniec = std::max(obecny_koniec, z.y);
        }
        else {
            suma_unikalnych += (obecny_koniec - obecny_start + 1);
            obecny_start = z.x;
            obecny_koniec = z.y;
        }
    }
    suma_unikalnych += (obecny_koniec - obecny_start + 1);
    std::cout << suma_unikalnych << std::endl;
}

