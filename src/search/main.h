#include "../library.h"
#include "../sorting/methods/bubble_sort.h"
#include "methods/binary_search.h"

void show_menu() {
    printf("-------------MENU-------------\n");
    printf("What do you want to do now?\n");
    printf("01) Search for another code.\n");
    printf("02) Close the program.\n");
}

void presentation() {
    printf("Hello! I am a bot that will help you to find a code in an array of "
           "codes.\n");
}

void create_code(CODE *target, char *code, int index, int month) {
    char month_str[MONTH_STR_SIZE];

    sprintf(month_str, "mes_%d", month);

    strcpy(target->code, code);
    target->index = index;
    strcpy(target->month, month_str);
}

CODE *expand_codes(CODE *array, int *size) {
    (*size)++;
    array = (CODE *)realloc(array, sizeof(CODE) * (*size));

    return array;
}

void search_for_repeated(int index, int limit, char ***data, int file,
                         CODE *found_codes, int *results) {
    int repeated = 0;

    if (index == -1) {
        return;
    }

    while (index + repeated < limit &&
           strcmp(data[file][index], data[file][index + repeated]) == 0) {
        found_codes = expand_codes(found_codes, results);
        create_code(&found_codes[*results - 1], data[file][index],
                    index + repeated + 1, file + 1);
        repeated++;
    }
}

CODE *search_code(char ***data, int size[FILES_QTT], char key[STRING_SIZE],
                  int *results) {
    CODE *found_codes;
    CODE new_code;
    int index;
    int repeated;

    *results = 0;
    found_codes = (CODE *)malloc(sizeof(CODE) * *results);

    for (int file = 0; file < FILES_QTT; file++) {
        repeated = 0;
        index = binary_search(data[file], size[file], key);

        search_for_repeated(index, size[file], data, file, found_codes,
                            results);
    }

    return found_codes;
}

void print_code(CODE *found_codes, int size) {

    if (size > 0) {
        printf("The key \"%s\" appears on:\n", found_codes[0].code);
        for (int i = 0; i < size; i++) {
            printf("Line #%d in the %s file\n", found_codes[i].index,
                   found_codes[i].month);
        }
    } else {
        printf("This key was not found in any file!\n");
    }
}