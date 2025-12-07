#include <stdio.h>
#include <stdlib.h>
#include "get_matrix.h"

char** get_matrix_from_file(const char* filepath, char** ptr_buffer, int* ptr_count){
    // get pointer to beggining of file
    FILE *fptr = fopen(filepath, "rb");
    if (!fptr) {
        return NULL;
    }

    // get file length so we can properly iterate over file
    // also our ptr_buffer contains all characters of the file
    long dlugosc;
    fseek(fptr, 0, SEEK_END);
    dlugosc = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);
    *ptr_buffer = malloc(dlugosc + 1);
    if (!*ptr_buffer) {
        printf("Brak zaalokowanej pamieci\n");
        return NULL;
    }
    fread(*ptr_buffer, 1, dlugosc, fptr);
    (*ptr_buffer)[dlugosc] = '\0'; // nawiasy bo priorytety operatorow
    fclose(fptr);

    // words is our matrix, we are filling it with memory addresses of strings
    // we are overwriting buffer matrix with '\0' so we know when integers begin
    // or we get \n etc.
    int word_count = 0;
    char* newline_str = "\n";
    int i = 0;
    char** words = NULL;
    char* buffer = *ptr_buffer;
    while (buffer[i] != '\0'){
        // for space or \r 
        if (buffer[i] == ' ' || buffer[i] == '\r'){
            buffer[i] = '\0';
            i++;
            continue;
        }
        if (buffer[i] == '\n') {
            buffer[i] = '\0'; // we put this so last integer is read correctly
            words = realloc(words, sizeof(char*) * (word_count + 1) );
            words[word_count] = newline_str; // and also we store \n
            word_count++;
            i++;
            continue;
        }
        if (i == 0 || buffer[i-1] == '\0') { // we store address of beginning of that string
            words = realloc(words, sizeof(char*) * (word_count + 1));
            words[word_count] = &buffer[i];
            word_count++;
        }
        i++;
    }
    *ptr_count = word_count;
    return words;
}