#include "../library.h"

char** insert_binary_sort(char **array,int size) {
    char aux[STRING_SIZE];
    int left;
    int right;
    int medium;
    int j;

    for(int i=1; i<size; i++){
        strcpy(aux, array[i]);
        left = 0;
        right = i;

        while(left < right){
            medium = (left + right) / 2;

            if (compare(array[medium],aux) <= 0){
                left = medium + 1;
            }else{
                right = medium;
            }
        }

        j = i;
        while (j > right) {
            move(array[j], array[j - 1]);
            j--;
        }

        move(array[right], aux);
    }

    return array;
}
