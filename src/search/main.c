#include "main.h"

int main() {
    CODE *found_codes;     // Array to store found codes
    int option;            // The user's choice for what to do (search || exit)
    char key[STRING_SIZE]; // The key the user is searching in the files
    char ***files_data;    // 3D matrix with all strings in all files
    int size[FILES_QTT];   // Array of the file sizes

    files_data = get_data(size);
    presentation();

    do {
        option = menu();

        if (option == SEARCH) {
            strcpy(key, get_key());

            found_codes = search_code(files_data, size, key);
            print_code(key, found_codes);
        }
    } while (option != EXIT);

    return 0;
}
