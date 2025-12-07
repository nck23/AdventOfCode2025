#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc_diag.h"

int main(){
    const int matrix_rows = 5;
    const int matrix_columns = 1000;
    char* my_buffer = NULL;
    int output;
    output = calc_diagonally("input.txt", &my_buffer, matrix_rows, matrix_columns);
    printf("final: %d\n", output);

    if (my_buffer) free(my_buffer);
    return 0;
}