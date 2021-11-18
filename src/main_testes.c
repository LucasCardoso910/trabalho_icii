#include "library.h"

int main() {
    char** array;
    int size;

    scanf("%d", &size);

    array = (char**) malloc(sizeof(char*) * size);
    for (int i = 0; i < size; i++) {
        array[i] = (char*) malloc(sizeof(char) * STRING_SIZE);
        scanf("%s", array[i]);
    }
    
    array = sort(array, size);
    print(array, size);

    return 0;
}