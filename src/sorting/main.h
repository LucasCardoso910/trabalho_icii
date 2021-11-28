#include "../library.h"
#include "methods/bubble_sort.h"
#include "methods/heap_sort.h"
#include "methods/improved_bubble_sort.h"
#include "methods/insert_binary_sort.h"
#include "methods/insert_sort.h"
#include "methods/merge_sort.h"
#include "methods/quick_sort.h"
#include "methods/selection_sort.h"
#include "methods/shake_sort.h"

void delete_file_content(char filename[FILENAME_SIZE]) {
    FILE *file = fopen(filename, "w");
    fclose(file);
}

int count_lines_in_file(char filename[FILENAME_SIZE]) {
    FILE *file = fopen(filename, "r");
    char line[CSV_LINE];
    int lines = 0;

    while (fgets(line, sizeof(line), file)) {
        lines++;
    }

    fclose(file);

    return lines;
}

void sort(char *sort(char **, int), char **array, int *size, char *month) {
    char function_name[FUNC_NAME_SIZE];
    char filename[FILENAME_SIZE];

    // Executes the function and stores its name to be used
    start = clock();
    strcpy(function_name, sort(array, *size));
    end = clock();

    // Create output file
    sprintf(filename, "output/sorting/%s/%s.txt", month, function_name);
    write_output_file(filename, array, *size);

    // Create data file
    sprintf(filename, "data/files/%s.csv", function_name);

    // Delete file if it is already full (old content)
    if (count_lines_in_file(filename) >= FILES_QTT) {
        delete_file_content(filename);
    }

    // Writes data to file
    write_data_file(filename, month);
}