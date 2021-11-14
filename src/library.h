#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STRING_SIZE 12

char** right_shift(char** array, int *size);
char** left_shift(char** array, int *size);
int compare(char *str1, char *str2);
void swap(char* obj1, char *obj2);
void move(char *dest, char *source);
void print(char **array, int size);

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