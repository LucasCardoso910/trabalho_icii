#include "sorting/bubble_sort.h"

int main() {
    char** array;
    int size;

    printf("Insert how many strings: ");
    scanf("%d", &size);

    printf("Insert the strings:\n");
    array = (char**) malloc(sizeof(char*) * size);
    for (int i = 0; i < size; i++) {
        array[i] = (char*) malloc(sizeof(char) * STRING_SIZE);
        scanf("%s", array[i]);
    }
    
    array = bubble_sort(array, size);
    print(array, size);

    return 0;
}