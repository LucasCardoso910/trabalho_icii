#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STRING_SIZE 12
#define TRUE 1
#define FALSE 0

#define FILENAME_SIZE 100
#define MONTH_STR_SIZE 6
#define FUNC_NAME_SIZE 25

char** right_shift(char** array, int *size);
char** left_shift(char** array, int *size);
int compare(char *str1, char *str2);
void swap(char* obj1, char *obj2);
void move(char *dest, char *source);
void print(char **array, int size);

typedef struct found_code {
    int index;
    char month[MONTH_STR_SIZE];
    char code[STRING_SIZE];
} CODE;

int count_compare = 0;  // Variável para contar número de comparações
int count_moves = 0;    // Variável para contar número de trocas

char** right_shift(char** array, int *size) {
    (*size)++;
    
    array = (char**) realloc(array, sizeof(char*) * (*size));
    for (int i = 0; i < (*size); i++) {
        array[i] = (char*) realloc(array[i], sizeof(char) * STRING_SIZE);
    }

    // Preserva a ordem, move todos os elementos um para a direita
    for (int i = (*size - 2); i >= 0; i--) {
        strcpy(array[i + 1], array[i]);
    }

    // Não preserva a ordem, move o primeiro elemento para o final
    // strcpy(array[*size - 1], array[0]);

    return array;
}

char** left_shift(char** array, int *size) {
    for (int i = 1; i < (*size); i++) {
        strcpy(array[i - 1], array[i]);
    }

    (*size)--;
    array = (char**) realloc(array, sizeof(char*) * (*size));

    return array;
}

int compare(char *str1, char *str2) {
    count_compare++;

    return strcmp(str1,str2);
}

void swap(char * obj1, char *obj2) {
    char var[STRING_SIZE];

    move(var, obj1);
    move(obj1, obj2);
    move(obj2, var);
}

void move(char *dest, char *source) {
    count_moves++;

    strcpy(dest,source);
}

void print(char **array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s\t", array[i]);
    }
    printf("\n");
}

void print_subarray(char **array, int left, int right) {
    for (int i = left; i < right; i++) {
        printf("%s\t", array[i]);
    }
    printf("\n");
}

void resize_array(char **array, int *size, int new_size) {
    array = (char **)realloc(array, sizeof(char *) * new_size);
    (*size) = new_size;
}

FILE *open_file(char *filename, char *open_mode) {
    FILE *file;

    file = fopen(filename, open_mode);
    if (file == NULL) {
        printf("File is null! Check if file exists and its permissions!\n");
        exit(1);
    }

    return file;
}

char **start_array(char **array, int *size) {
    (*size) = 3;

    array = (char **)malloc(sizeof(char *) * (*size));
    for (int j = 0; j < (*size); j++) {
        array[j] = (char *)malloc(sizeof(char) * STRING_SIZE);
    }

    return array;
}

void zero_counters() {
    count_compare = 0;
    count_moves = 0;
}

char **expand_array(char **array, int *size) {
    int initial_size = (*size);
    (*size) += 3;

    array = (char **)realloc(array, sizeof(char *) * (*size));
    for (int j = initial_size; j < (*size); j++) {
        array[j] = (char *)malloc(sizeof(char) * STRING_SIZE);
    }

    return array;
}

char **read_file(char *filename, int *size) {
    char string[STRING_SIZE];
    int count = 0;
    char **array;
    FILE *file;

    zero_counters();

    file = open_file(filename, "r");
    array = start_array(array, size);

    while (fscanf(file, "%s\n", string) > 0) {
        if (count == (*size)) {
            array = expand_array(array, size);
        }

        strcpy(array[count], string);
        count++;
    }

    if (count != (*size)) {
        resize_array(array, size, count);
    }

    fclose(file);

    return array;
}

// CODE *expand_array(CODE *array, int *size) {
//     int initial_size = (*size);
//     (*size) += 3;

//     array = (CODE *) realloc(array, sizeof(CODE) * (*size));

//     return array;
// }

void write_output_file(char filename[FILENAME_SIZE], char **content, int size) {
    FILE *file;
    
    file = fopen(filename, "w");

    for (int i = 0; i < size; i++) {
        fprintf(file, "%s\n", content[i]);
    }

    fclose(file);
}

char **copy_data(char **target, char **obj, int size) {
    target = (char **)malloc(sizeof(char *) * size);
    for (int i = 0; i < size; i++) {
        target[i] = (char *)malloc(sizeof(char) * STRING_SIZE);
        strcpy(target[i], obj[i]);
    }

    return target;
}

void write_data_file(char filename[FILENAME_SIZE], char month[MONTH_STR_SIZE]) {
    FILE *file;

    file = fopen(filename, "a");
    fprintf(file, "%s,%d,%d\n", month, count_compare, count_moves);
    fclose(file);
}