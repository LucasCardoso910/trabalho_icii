#include "main.h"

int main() {
    CODE *found_codes;     // Array to store found codes
    int option;            // The user's choice for what to do (search || exit)
    char key[STRING_SIZE]; // The key the user is searching in the files
    char ***files_data;    // 3D matrix with all strings in all files
    int size[FILES_QTT];   // Array of the file sizes
    int results;           // Number of found codes

    files_data = get_data(files_data, size);
    presentation();

    do {
        show_menu();

        scanf("%d", &option);

        // Make sure that does not have trash in the buffer
        fflush(stdin);
        setbuf(stdin, NULL);

        if (option == SEARCH) {
            printf("Insert the search key: ");
            fgets(key, STRING_SIZE, stdin);
            clean_answer(key);

            found_codes = search_code(files_data, size, key, &results);
            print_code(found_codes, results);
        }
    } while (option != EXIT);

    return 0;
}
