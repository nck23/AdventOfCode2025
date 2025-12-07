#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc_diag.h"

int main(){
    const int matrix_rows = 4;
    char* my_buffer = NULL;
    unsigned long long output;
    output = calc_diagonally("input.txt", &my_buffer, matrix_rows);
    printf("final: %lld\n", output);

    if (my_buffer) free(my_buffer);
    return 0;
}