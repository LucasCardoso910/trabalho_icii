#include "../library.h"
#include "../sorting/methods/quick_sort.h" // Most efficient sorting algorithm
#include "methods/binary_search.h"

#define SEARCH 1
#define EXIT 2

#define NOT_FOUND -1

// Functions prototypes
int menu();
void presentation();
int search_doubles(char **data, int start, int end);
CODE *search_code(char ***data, int size[], char key[]);
void print_code(char key[], CODE *found_codes);
char ***get_data(int size[FILES_QTT]);

int menu() {
    int option;
    char read[STRING_SIZE];

    printf("\n-------------MENU------------\n");
    printf("What do you want to do now?\n");
    printf("1) Search for a code.\n");
    printf("2) Close the program.\n");

    do {
        printf("Insert your option (Number between 1 and 2): ");
        fscanf(stdin, "%s", read);
        cleanbuf();
    } while (read[0] < 49 || read[0] > 50);

    option = read[0] - 48;

    return option;
}

char *get_key() {
    char *key;

    printf("Insert the search key: ");
    key = (char *)malloc(sizeof(char) * STRING_SIZE);
    fgets(key, STRING_SIZE, stdin);

    clean_answer(key);

    return key;
}

void presentation() {
    printf("Hello! I will help you to find a code in the files.\n");
}

// Binary search returns only the most left index as result
// This function loops through the values in the right,
// checking if they are the same
int search_doubles(char **data, int start, int end) {
    int index = start + 1;

    if (start == NOT_FOUND) {
        return start; // Initial and final points to the same index
    }

    while (index < end && strcmp(data[index], data[start]) == 0) {
        index++;
    }

    return index;
}

// Search for a given code in all ordered files for all its occurrences
CODE *search_code(char ***data, int size[], char key[]) {
    CODE *found_codes;
    int index;

    found_codes = (CODE *)malloc(sizeof(CODE) * FILES_QTT);

    for (int file = 0; file < FILES_QTT; file++) {
        index = binary_search(data[file], size[file], key);
        found_codes[file].initial_index = index;
        found_codes[file].final_index =
            search_doubles(data[file], index, size[file]);
    }

    return found_codes;
}

// Print all occurrences of code correctly formatted
void print_code(char key[], CODE *found_codes) {
    // To know if the current code and the previous monthes are different
    int month_counter = 0;
    int total_counter = 0;
    int found = FALSE;

    for (int i = 0; i < FILES_QTT; i++) {
        if (found_codes[i].initial_index != NOT_FOUND) {
            found = TRUE;
        }
    }

    if (found == FALSE) {
        printf("\nThis key was not found in any file!\n");
        return;
    }

    printf("\nThe key \"%s\" appears on:\n", key);
    for (int month = 0; month < FILES_QTT; month++) {
        printf("\nIn file mes_%d:\n", month + 1);

        month_counter = 0;
        for (int line = found_codes[month].initial_index;
             line < found_codes[month].final_index; line++) {
            printf("- Line #%d\n", line + 1);
            month_counter++;
            total_counter++;
        }

        if (month_counter == 0) {
            printf("No lines in this file with this key!\n");
        }

        printf("Subtotal: %d\n", month_counter);
    }
    printf("Total: %d occurrences\n", total_counter);
}

// Reads all files info and sort it into a 3D array
char ***get_data(int size[FILES_QTT]) {
    char ***files_data;
    char month[MONTH_STR_SIZE];
    char input_file[FILENAME_SIZE];
    char output_file[FILENAME_MAX];

    files_data = (char ***)malloc(sizeof(char **) * FILES_QTT);

    // Sort files to be used in the search
    for (int file = 0; file < FILES_QTT; file++) {
        sprintf(month, "mes_%d", file + 1);
        sprintf(input_file, "input/%s.txt", month);
        sprintf(output_file, "output/search/%s.txt", month);

        files_data[file] = read_file(input_file, &size[file]);
        quick_sort(files_data[file], size[file]);
        write_output_file(output_file, files_data[file], size[file]);
    }

    return files_data;
}
