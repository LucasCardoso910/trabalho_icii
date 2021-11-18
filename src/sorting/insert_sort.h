char* insert_sort(char** array, int size) {    
    array = right_shift(array, &size);

    for (int i = 2; i < size; i++) {
        char sentinel[STRING_SIZE];
        int j;
        
        move(sentinel, array[i]);
        move(array[0], sentinel);

        j = i;
        while(compare(sentinel, array[j-1]) < 0) {
            move(array[j], array[j-1]);
            j--;
        }
        move(array[j], sentinel);    
    }

    array = left_shift(array, &size);

    return "insert_sort";
}
