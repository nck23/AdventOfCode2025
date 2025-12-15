#include "readFile.h"
#include <iostream>

void wczytajDane(std::string file_name, std::vector<Zakres>& zakresy, std::vector<long long int>& liczby) {
    std::ifstream plik(file_name);
        if (!plik.is_open()) {
            std::cerr << "Blad: Nie mozna otworzyc pliku!" << std::endl;
            return;
        }
        std::string linia;
        long long int x1;
        long long int x2;
        char oddzielnik;
        bool zamiana = false;
        while (std::getline(plik, linia)) {
            if (linia.empty()) {
                zamiana = true;
                continue;
            }
            if (!zamiana) {
                std::stringstream ss(linia);
                ss >> x1 >> oddzielnik >> x2;
                Zakres z = {x1, x2};
                zakresy.push_back(z);
            } else {
                std::stringstream ss(linia);
                long long int liczba;
                ss >> liczba;
                liczby.push_back(liczba);
            }
            
        }
}