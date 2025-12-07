#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_matrix.h"
#include "transpone_matrix.h"

int main(){
    char* my_buffer = NULL;
    char** my_words = NULL;
    int count = 0;
    my_words = get_matrix_from_file("input.txt", &my_buffer, &count);
    /*
    if (my_words != NULL) {
        printf("my_words: %d\n", count);
        for (int i = 0; i < count; i++){
            printf("ZNAK: %s \n", my_words[i]);
        }
    }
    */

    char*** final_matrix = NULL;
    int final_rows = 0;
    int final_columns = 0;
    final_matrix = transpone_matrix(my_words, &count, &final_rows, &final_columns);
    printf("Transponowana macierz wymiary: %d wierszy, %d kolumn\n", final_rows, final_columns);
    long value_tab[final_columns - 1];
    long long final_value = 0;
    
    for (int i =0; i < final_rows;i++){
    for(int j=0; j < final_columns; j++){
        if (strcmp(final_matrix[i][j], "*") == 0) { // Obliczanie wyniku dla mnozenia
            long result_value = 1;
            for (int i =0;i<final_columns - 1;i++){
                result_value = result_value * value_tab[i];
            }
            final_value += result_value;
        } else if (strcmp(final_matrix[i][j], "+") == 0){ // Obliczanie wyniku dla dodawania
            long result_value = 0;
            for (int i =0;i<final_columns - 1;i++){
                result_value = result_value + value_tab[i];
            }
            final_value += result_value;
        }
        value_tab[j] = atoi(final_matrix[i][j]); // Tablica do zachowywania liczb ktore potem trzeba pomnozyc albo dodac
        
        // printf("%-8s ", final_matrix[i][j]);
    }
        // printf("\n\n");
    }
    printf("FINAL VALUE: %lld\n", final_value);
    if (my_words) free(my_words);
    if (my_buffer) free(my_buffer);
    if (final_matrix) free(final_matrix);
    return 0;
}