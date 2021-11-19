char* bubble_sort(char **array, int size){

    for(int i = 1;i<size; i++){

        for(int j=size-1; j>=i; j--){

            if(compare(array[j-1],array[j]) > 0){
                swap(array[j-1],array[j]);
            }
        }
    }

    return "bubble_sort";
}

char* improved_bubble_sort(char **array, int size) {
    int changed;
    int count = 1;

    do{
        changed = FALSE;

        for(int i = 0; i < size - count; i++) {
            if (compare(array[i], array[i + 1]) > 0) {
                swap(array[i], array[i + 1]);
                changed = TRUE;
            }
        }

        count++;
    } while(changed);

    return "improved_bubble_sort";
}

