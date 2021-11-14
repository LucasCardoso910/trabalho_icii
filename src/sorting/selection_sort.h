#include "../library.h"

char** selection_sort(char** array, int size) {
    
    for (int i=0; i<size-1; i++){
        int minor_index = i;

        for (int j=i+1; j<size; j++){
            if (compare(array[j],array[minor_index]) < 0){
                minor_index = j;
            }
        }

        swap(array[i],array[minor_index]);
        // print(array, size);
    }

    return array;
}