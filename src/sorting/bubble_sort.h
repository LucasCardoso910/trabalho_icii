#include "../library.h"

char ** bubble_sort(char **array, int size){
    int changed;

    do{
        changed = FALSE;

        for(int i=0; i<size-1;i++){

            if (compare(array[i],array[i+1]) > 0){
                swap(array[i],array[i+1]);
                changed = TRUE;
            }
        }
    }while(changed);

    return array;
}