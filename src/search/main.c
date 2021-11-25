#include "main.h"

void show_menu(){
    printf("-------------MENU-------------\n");
    printf("What do you want to do now?\n");
    printf("01) Search for another code.\n");
    printf("02) Close the program.\n");

}

void presentation(){
    printf("Hello! I am a bot that will help you to find a code in an array of codes.\n");

}

void create_code (CODE* target, char* code, int index, int month) {
    char month_str[MONTH_STR_SIZE];

    sprintf(month_str, "mes_%d", month);

    strcpy(target->code, code);
    target->index = index;
    strcpy(target->month, month_str);
}

CODE* expand_codes(CODE* array, int* size) {
    (*size)++;
    array = (CODE*) realloc(array, sizeof(CODE) * (*size));

    return array;
}

void search_for_repeated(int index, int limit, char ***data, int file, CODE* found_codes, int *results) {
    int repeated = 0;

    if (index == -1) {
        return;
    }
    
    while (index + repeated < limit && strcmp(data[file][index], data[file][index+repeated]) == 0 ){
        found_codes = expand_codes(found_codes, results);
        create_code(&found_codes[*results - 1], data[file][index], index + repeated + 1, file + 1);
        repeated++;
    }
}

CODE* search_code(char*** data, int size[5], char key[STRING_SIZE], int *results) {
    CODE* found_codes;
    CODE new_code;
    int index;
    int repeated;

    *results = 0;
    found_codes = (CODE*) malloc(sizeof(CODE) * *results);

    for (int file = 0; file < 5; file++) {
        repeated = 0;
        index = binary_search(data[file], size[file], key);

        search_for_repeated(index, size[file], data, file, found_codes, results);
    }

    return found_codes;
}

void print_code(CODE* found_codes, int size){
    
    if (size > 0) {
        printf("The key \"%s\" appears on:\n",found_codes[0].code);
        for(int i=0;i<size;i++){
            printf("Line #%d in the %s file\n",found_codes[i].index,found_codes[i].month);
        }
    }
    else {
        printf("This key was not found in any file!\n");
    }
}

void clean_answer(char answer[STRING_SIZE]) {
    answer[strcspn(answer, "\n")] = 0;

    for (int i = 0; i < STRING_SIZE; i++) {
        answer[i] = toupper(answer[i]);
    }
}

int main() {
    CODE* found_codes;
    char option[10];
    char key[STRING_SIZE];
    char month[MONTH_STR_SIZE];
    char input_file[FILENAME_SIZE];
    char output_file[FILENAME_MAX];
    char** files_data[5];
    int size[5];
    int results;
    
    for (int file = 0; file < 5; file++) {
        sprintf(month, "mes_%d", file + 1);
        sprintf(input_file, "input/%s.txt", month);
        sprintf(output_file, "output/search/%s.txt", month);
        
        files_data[file] = read_file(input_file, &size[file]);
        bubble_sort(files_data[file], size[file]);
        write_output_file(output_file, files_data[file], size[file]);
    }

    presentation();
    
    do{
        show_menu();

        fgets(option,10,stdin);
        option[strcspn(option, "\n")] = 0;
        printf("%s\n", option);
        
        if(strcmp(option,"01") == 0 || strcmp(option,"1") == 0){
            fgets(key,STRING_SIZE,stdin);
            clean_answer(key);
            
            found_codes = search_code(files_data,size,key, &results);

            if (results != 0) {
                print_code(found_codes, results);
            }
        }
    } while(strcmp(option,"02") != 0 && strcmp(option,"2") != 0);

    return 0;
}
