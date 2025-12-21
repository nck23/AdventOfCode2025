#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

struct Zakres {
    long long int x;
    long long int y;
};
void wczytajDane(std::string file_name, std::vector<Zakres>& zakresy, std::vector<long long int>& liczby);