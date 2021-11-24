#include "library.h"
#include "methods/merge_sort.h"

int main() {
    char** new_array;
    char** array;
    int size;

    scanf("%d", &size);

    array = (char**) malloc(sizeof(char*) * size);
    for (int i = 0; i < size; i++) {
        array[i] = (char*) malloc(sizeof(char) * STRING_SIZE);
        scanf("%s", array[i]);
    }

    new_array = (char**) malloc(sizeof(char*) * size);
    for (int i = 0; i < size; i++) {
        new_array[i] = (char*) malloc(sizeof(char) * STRING_SIZE);
    }
    
    merge_sort(array, size);

    printf("Comparações: %d\n", count_compare);
    printf("Movimentações: %d\n", count_moves);

    return 0;
}

