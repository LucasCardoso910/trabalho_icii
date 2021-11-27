#include "../library.h"
#include "../sorting/methods/bubble_sort.h"
#include "methods/binary_search.h"

void show_menu() {
    printf("\n-------------MENU------------\n");
    printf("What do you want to do now?\n");
    printf("01) Search for a code.\n");
    printf("02) Close the program.\n");
    printf("Insert your option: ");
}

void presentation() {
    printf("Hello! I will help you to find a code in the files.\n");
}

CODE create_code(char *code, int index, int month) {
    CODE new_code;

    strcpy(new_code.code, code);
    new_code.index = index;
    new_code.month = month;

    return new_code;
}

CODE *expand_codes(CODE *array, int *size) {
    (*size)++;
    array = (CODE *)realloc(array, sizeof(CODE) * (*size));

    return array;
}

void search_doubles(char **array, int start, int end, CODE *codes, int *size) {
    int file;
    int index = start;

    if (index == -1) {
        return;
    }

    file = codes[*size - 1].month;
    while (index < end && strcmp(array[start], array[index]) == 0) {
        index++;
        codes = expand_codes(codes, size);
        codes[*size - 1] = create_code(array[start], index, file);
    }
}

CODE *search_code(char ***data, int size[], char key[], int *results) {
    CODE *found_codes;
    CODE new_code;
    int index;
    int repeated;

    *results = 0;
    found_codes = (CODE *)malloc(sizeof(CODE) * *results);

    for (int file = 0; file < FILES_QTT; file++) {
        repeated = 0;
        index = binary_search(data[file], size[file], key);

        if (index != -1) {
            found_codes = expand_codes(found_codes, results);
            found_codes[*results - 1] = create_code(key, index, file + 1);
        }
        search_doubles(data[file], index, size[file], found_codes, results);
    }

    return found_codes;
}

void print_code(CODE *found_codes, int size) {
    // To know if the current code and the previous monthes are differente
    int month_previous = -1;
    int month_counter = 0;
    int total_counter = 0;

    if (size == 0) {
        printf("This key was not found in any file!\n");
        return;
    }

    printf("\nThe key \"%s\" appears on:\n", found_codes[0].code);
    for (int i = 0; i < size; i++) {
        if (found_codes[i].month != month_previous) {
            if (month_previous != -1) {
                printf("Subtotal: %d\n", month_counter);
            }

            printf("\n");
            printf("In file mes_%d:\n", found_codes[i].month);

            month_counter = 0;
            month_previous = found_codes[i].month;
        }
        printf("- Line #%d\n", found_codes[i].index);
        month_counter++;
        total_counter++;
    }
    printf("Subtotal: %d\n", month_counter);
    printf("Total: %d occurences\n", total_counter);
}