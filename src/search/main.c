#include "main.h"

int main() {
    CODE *found_codes;
    char option[STRING_SIZE];
    char key[STRING_SIZE];
    char month[MONTH_STR_SIZE];
    char input_file[FILENAME_SIZE];
    char output_file[FILENAME_MAX];
    char **files_data[FILES_QTT];
    int size[FILES_QTT];
    int results;

    for (int file = 0; file < FILES_QTT; file++) {
        sprintf(month, "mes_%d", file + 1);
        sprintf(input_file, "input/%s.txt", month);
        sprintf(output_file, "output/search/%s.txt", month);

        files_data[file] = read_file(input_file, &size[file]);
        bubble_sort(files_data[file], size[file]);
        write_output_file(output_file, files_data[file], size[file]);
    }

    presentation();

    do {
        show_menu();

        // Mudar para scanf e ler como inteiro?
        // Vantagens: comparação mais fácil,
        //            não ter de lidar com \n,
        //            0 a esquerda não importa

        fgets(option, STRING_SIZE, stdin);
        option[strcspn(option, "\n")] = 0;

        if (strcmp(option, "01") == 0 || strcmp(option, "1") == 0) {
            printf("Insert the search key: ");
            fgets(key, STRING_SIZE, stdin);
            clean_answer(key);

            found_codes = search_code(files_data, size, key, &results);

            if (results > 0) {
                print_code(found_codes, results);
            }
        }
    } while (strcmp(option, "02") != 0 && strcmp(option, "2") != 0);

    return 0;
}
