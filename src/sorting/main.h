#include "../library.h"
#include "methods/bubble_sort.h"
#include "methods/heap_sort.h"
#include "methods/insert_binary_sort.h"
#include "methods/insert_sort.h"
#include "methods/merge_sort.h"
#include "methods/quick_sort.h"
#include "methods/selection_sort.h"

void write_data_file(char func_name[FUNC_NAME_SIZE],
                     char month[MONTH_STR_SIZE]) {
    FILE *file;
    char filename[FILENAME_SIZE];

    sprintf(filename, "data/files/%s.csv", func_name);
    file = fopen(filename, "a");
    fprintf(file, "%s,%d,%d\n", month, count_compare, count_moves);
    fclose(file);
}

void sort(char *sort(char **, int), char **array, int *size, char *month) {
    char function_name[FUNC_NAME_SIZE];
    char filename[FILENAME_SIZE];

    strcpy(function_name, sort(array, *size));
    sprintf(filename, "output/sorting/%s/%s.txt", month, function_name);

    write_output_file(filename, array, *size);
    write_data_file(function_name, month);
}