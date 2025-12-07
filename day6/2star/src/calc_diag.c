#include <stdio.h>
#include <stdlib.h>
#include "calc_diag.h"

int calc_diagonally(const char* filepath, char** ptr_buffer, const int matrix_rows, const int matrix_columns){
    FILE *fptr = fopen(filepath, "rb");
    if (!fptr) {
        return 0;
    }
    long dlugosc;
    fseek(fptr, 0, SEEK_END);
    dlugosc = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);
    *ptr_buffer = malloc(dlugosc + 1);
    if (!*ptr_buffer) {
        printf("Brak zaalokowanej pamieci\n");
        return 0;
    }
    fread(*ptr_buffer, 1, dlugosc, fptr);
    (*ptr_buffer)[dlugosc] = '\0'; // nawiasy bo priorytety operatorow
    fclose(fptr);

    int end_of_line = ((dlugosc - 1) / matrix_rows); // dlugosc - 1 bo \0 i -1 kolejne bo indeks od zera
    char* buffer = *ptr_buffer;


    // read diagonally
    // i = i * (matrix_rows - 1) + matrix_columns - 1; // get to the lowest row
    int final_result = 0;
    // MAYBE CHANGE THIS
    int value_matrix[matrix_rows - 1]; // to store values which are in diagonal order (-1 cuz last is */+ or None)
    int which = 0; // for iterating through value matrix

    char last_char = '0';
    int current_col_start = 0;
    int j = current_col_start; // to iterate through buffer diagonally

    while (current_col_start < end_of_line)  {
        if (j >= dlugosc - 1) { // git
            which = 0;
            int check = 0;
            // logic for logging if whole column was empty
            for (check = 0; check < matrix_rows - 1; check++) {
                if (value_matrix[check] != 0) {
                    break;
                }
            }
            // printf("check value: %d\n", check);
            if (check == (matrix_rows - 1)) {
                last_char = '0';
                printf("PUSTE!\n");
            } else if (last_char != '0') {
                int value = 0;
                if (last_char == '+'){
                    for (check = 0; check < matrix_rows - 1; check++) {
                        value += value_matrix[check];
                    }
                } else {
                    value = 1;
                    for (check = 0; check < matrix_rows - 1; check++) {
                        if (value_matrix[check] != 0){
                            value *= value_matrix[check];
                        }
                    }
                }
                printf("DODANIE: %d, %c\n", value, last_char);
                final_result += value;
            }
            current_col_start++;
            j = current_col_start;
            which = 0;
            
            continue;
        }
        if (j < dlugosc){
            if (buffer[j] == ' ') {
                value_matrix[which] = 0;
            } else if (buffer[j] == '*' || buffer[j] == '+') {
                last_char = buffer[j];
            } else {
                value_matrix[which] = buffer[j] - '0';
            }
            if (which < matrix_rows - 1){
                printf("V: %d, j: %d\n", value_matrix[which], j);
            } 
            
        } else {
            printf("CZYTANIE POZA DLUGOSCIA!\n");
        }
        which++;
        j+= end_of_line + 1;
    }

    return final_result;
}