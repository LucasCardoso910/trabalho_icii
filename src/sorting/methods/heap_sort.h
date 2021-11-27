void heapify(char **array, int left, int right) {
    int i = left;
    int j = (2 * left);
    char x[STRING_SIZE];

    move(x, array[left]);
    if ((j < right) && (compare(array[j], array[j + 1]) < 0)) {
        j++;
    }

    while ((j <= right) && (compare(x, array[j]) < 0)) {
        move(array[i], array[j]);
        i = j;
        j *= 2;

        if ((j < right) && (compare(array[j], array[j + 1]) < 0)) {
            j++;
        }
    }

    move(array[i], x);
}

char *heap_sort(char **array, int size) {
    int left;
    int right;

    array = right_shift(array, &size);

    for (left = ((size - 1) / 2); left > 0; left--) {
        heapify(array, left, size - 1);
    }

    for (right = (size - 1); right > 1; right--) {
        swap(array[1], array[right]);
        heapify(array, 1, right - 1);
    }

    array = left_shift(array, &size);

    return "heap_sort";
}