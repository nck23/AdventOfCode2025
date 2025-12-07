#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "transpone_matrix.h"

char*** transpone_matrix(char** ptr_words, int* ptr_count, int* ptr_rows, int* ptr_columns){
    int src_matrix_rows = 1; // od 1 bo zaczynamy od zera
    int src_matrix_columns = 0; // kolumny
    // Get exact columns and rows value of input matrix
    for (int i =0; i < *ptr_count; i++){
        if (strcmp(ptr_words[i], "\n") == 0){
            src_matrix_columns = i;
            break;
        }
    }
    for (int i =0; i < *ptr_count;i++){
        if (strcmp(ptr_words[i], "\n") == 0){
            src_matrix_rows++;
        }
    }
    printf("Oryginalne wymiary macierzy: %d wierszy, %d kolumn\n", src_matrix_rows, src_matrix_columns);

    // Assign memory for transponed matrix (inverted columns and rows!)
    char*** transponed_matrix = malloc(src_matrix_columns * sizeof(char**));
    for (int i=0;i<src_matrix_columns;i++){
        transponed_matrix[i] = malloc(src_matrix_rows * sizeof(char*));
    }

    // Iterate over original matrix and assign values to transponed matrix correctly
    int wiersz = 0;
    int kolumna = 0;
    for (int i = 0; i < *ptr_count; i++){
        if (strcmp(ptr_words[i], "\n") == 0) {
            kolumna = 0;
            wiersz++;
            continue;
        }
        // printf("W: %d K: %d WARTOSC: %-8s\n", wiersz, kolumna, ptr_words[i]);
        transponed_matrix[kolumna][wiersz] = ptr_words[i];
        kolumna++;
        
    }

    // Store transponed matrix columns and rows (inverted columns and rows!)
    *ptr_rows = src_matrix_columns;
    *ptr_columns = src_matrix_rows;
    // printf("Wymiary\nWIERSZE: %d\nKOLUMNY: %d\n", matrix_rows, matrix_columns);
    return transponed_matrix;
}