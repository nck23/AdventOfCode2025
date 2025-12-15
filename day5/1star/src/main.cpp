#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <set>
#include "readFile.h"


int main(){
    std::string linia;
    std::vector<Zakres> zakresy;
    std::vector<long long int> liczby;
    wczytajDane("input.txt", zakresy, liczby);

    int sum = 0;
    for (const auto& z : liczby) {
        for (const auto& wartosc : zakresy) {
            // std::cout << z << " " << wartosc << std::endl;
            if (z >= wartosc.x && z <= wartosc.y) {
                sum += 1;
                break;
            }
            
        }
        // std::cout << z << std::endl;
    }
    std::cout << sum << std::endl;


}

