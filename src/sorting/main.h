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

void sort(char *sort(char **, int), char **array, int *size, char *month) {
    char function_name[FUNC_NAME_SIZE];
    char filename[FILENAME_SIZE];

    strcpy(function_name, sort(array, *size));
    sprintf(filename, "output/sorting/%s/%s.txt", month, function_name);

    write_output_file(filename, array, *size);
    write_data_file(function_name, month);
}