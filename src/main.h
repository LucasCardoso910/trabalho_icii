#include "library.h"
#include "sorting/bubble_sort.h"
#include "sorting/heap_sort.h"
#include "sorting/insert_binary_sort.h"
#include "sorting/insert_sort.h"
#include "sorting/merge_sort.h"
#include "sorting/quick_sort.h"
#include "sorting/selection_sort.h"

#define FILENAME_SIZE 50
#define MONTH_STR_SIZE 6
#define FUNC_NAME_SIZE 25

FILE* open_file(char* filename, char* open_mode) {
    FILE* file;

    file = fopen(filename, open_mode);
    if (file == NULL) {
        printf("File is null! Check if file exists and its permissions!\n");
        exit(1);
    }

    return file;
}

void zero_counters() {
    count_compare = 0;
    count_moves = 0;
}

char** start_array(char** array, int *size) {
    (*size) = 3;

    array = (char**) malloc(sizeof(char*) * (*size));
    for (int j = 0; j < (*size); j++) {
        array[j] = (char*) malloc(sizeof(char) * STRING_SIZE);
    }

    return array;
}

char** expand_array(char** array, int *size) {
    int initial_size = (*size);
    (*size) += 3;

    array = (char**) realloc(array, sizeof(char*) * (*size));
    for (int j = initial_size; j < (*size); j++) {
        array[j] = (char*) malloc(sizeof(char) * STRING_SIZE);
    }

    return array;
}

void resize_array(char** array, int *size, int new_size) {
    array = (char**) realloc(array, sizeof(char*) * new_size);
    (*size) = new_size;
}

char** read_file(char* filename, int *size) {
    char string[STRING_SIZE];
    int count = 0;
    char** array;
    FILE *file;

    zero_counters();

    file = open_file(filename, "r");
    array = start_array(array, size);

    while (fscanf(file, "%s\n", string) > 0) {
        if (count == (*size)) {
            array = expand_array(array, size);
        }
        
        strcpy(array[count], string);
        count++;
    }

    if (count != (*size)) {
        resize_array(array, size, count);
    }

    fclose(file);

    return array;
}

void write_output_file(char month[MONTH_STR_SIZE], char** content, int size) {
    char filename[FILENAME_SIZE];
    FILE* file;

    sprintf(filename, "output/%s.txt", month);
    file = fopen(filename, "w");

    for (int i = 0; i < size; i++) {
        fprintf(file, "%s\n", content[i]);
    }

    fclose(file);
}

void write_data_file(char func_name[FUNC_NAME_SIZE], char month[MONTH_STR_SIZE]) {
    FILE* file;
    char filename[FILENAME_SIZE];

    sprintf(filename, "data/files/%s.csv", func_name);
    file = fopen(filename, "a");
    fprintf(file, "%s,%d,%d\n", month, count_compare, count_moves);
    fclose(file);
}

void sort(char* sort(char**, int), char** array, int *size, char* month) {
    char function_name[FUNC_NAME_SIZE];

    strcpy(function_name, sort(array, *size));
    write_output_file(month, array, *size);
    write_data_file(function_name, month);
}