#include "../src/library.h"
#include "../src/sorting/methods/bubble_sort.h"
#include "../src/sorting/methods/heap_sort.h"
#include "../src/sorting/methods/improved_bubble_sort.h"
#include "../src/sorting/methods/insert_binary_sort.h"
#include "../src/sorting/methods/insert_sort.h"
#include "../src/sorting/methods/merge_sort.h"
#include "../src/sorting/methods/quick_sort.h"
#include "../src/sorting/methods/selection_sort.h"
#include "../src/sorting/methods/shake_sort.h"

int main() {
    int lines_in_file = 0;
    char** data[METHD_FUNC_QTT];
    char** file_data;
    char function_name[FUNC_NAME_SIZE];
    char output_file[FILENAME_SIZE];
    char file[FILENAME_SIZE];

    // Array with all sorting functions pointers
    char *(*sorting_functions[])(char **, int) = {
        &improved_bubble_sort,
        &bubble_sort,
        &shake_sort,
        &insert_binary_sort,
        &insert_sort,
        &selection_sort,
        &heap_sort,
        &quick_sort,
        &merge_sort,
    };

    scanf("%d\n", &lines_in_file);
    file_data = (char**) malloc(sizeof(char*) * lines_in_file);
    for (int j = 0; j < lines_in_file; j++) {
        file_data[j] = (char*) malloc(sizeof(char) * STRING_SIZE);
        scanf("%s\n", file_data[j]);
    }
    scanf("%s\n", file);

    for (int i = 0; i < METHD_FUNC_QTT; i++) {
        zero_counters();
        data[i] = copy_data(data[i], file_data, lines_in_file);
        strcpy(function_name, sorting_functions[i](data[i], lines_in_file));

        sprintf(output_file, ".temp/%s.txt", function_name);
        write_output_file(output_file, data[i], lines_in_file);

        sprintf(output_file, ".temp/data/%s.csv", function_name);
        write_data_file(output_file, file);
    }

    return 0;
}
