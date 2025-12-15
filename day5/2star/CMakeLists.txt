# 1. Wymagana wersja CMake (standardowy start)
cmake_minimum_required(VERSION 3.10)

# 2. Nazwa projektu
project(SzybkiProjekt)

# 3. Standard C++ (opcjonalne, ale warto ustawić np. na 17 lub 20)
set(CMAKE_CXX_STANDARD 17)

# 4. Co budujemy? (nazwa_pliku_wynikowego  pliki_zrodlowe)
add_executable(main 
    src/main.cpp 
    src/readFile.cpp
)
target_include_directories(main PUBLIC include)

configure_file(input.txt input.txt COPYONLY)