#include "main.h"

int main() {
    int size;
    FILE* file;
    char **array;
    char input_file[FILENAME_SIZE];
    char output_file[FILENAME_SIZE];
    char month[MONTH_STR_SIZE];

    // Array with all sorting functions pointers
    char* (*sorting_functions[])(char**, int) = {
        &improved_bubble_sort,
        &bubble_sort,
        &shake_sort, 
        &insert_binary_sort, 
        &insert_sort, 
        &selection_sort,
        &heap_sort,
        &quick_sort
    };

    // clean_csv_files(); // How to clean files no matter os?
    
    for (int i = 0; i < 5; i++) {
        sprintf(month, "mes_%d", i+1);
        sprintf(input_file, "input/%s.txt", month);
        sprintf(output_file, "output/%s.txt", month);

        for (int j = 0; j < 8; j++) {
            array = read_file(input_file, &size);
            sort(*sorting_functions[j], array, &size, month);
        }
    }

    return 0;
}
