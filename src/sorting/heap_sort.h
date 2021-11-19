void heapify(char** array, int left, int right) {
    int i = left;
    int j = 2 * left;
    char x[STRING_SIZE];
    move(x,array[left]);

    if ( (j<right) && (compare(array[j],array[j+1]) < 0)){
        j = j + 1;
    }
    
    while ( (j<=right) && (compare(x,array[j]) < 0)){
        move(array[i],array[j]);
        i = j;
        j = 2*j;

        if( (j<right) && (compare(array[j], array[j+1]) < 0)){
            j = j + 1;
        }
    }

    move(array[i],x);
    
}

char* heap_sort(char** array, int size) {
    int left;
    int right;

    for (left = size / 2; left >= 0; left--) {
        heapify(array, left, size-1);
    }

    for (right = size-1; right > 0; right--) {
        swap(array[0], array[right]);
        heapify(array, 0, right - 1);
    }

    return "heap_sort";
}