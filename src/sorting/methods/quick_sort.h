char **quicksort(char **array, int left, int right) {
    int i = left;
    int j = right;
    char x[STRING_SIZE];

    move(x, array[(left + right) / 2]);

    do {
        while (compare(array[i], x) < 0) {
            i = i + 1;
        }

        while (compare(x, array[j]) < 0) {
            j = j - 1;
        }

        if (i <= j) {
            swap(array[i], array[j]);
            i++;
            j--;
        }
    } while (i <= j);

    if (left < j) {
        quicksort(array, left, j);
    }

    if (i < right) {
        quicksort(array, i, right);
    }

    return array;
}

char *quick_sort(char **array, int size) {
    array = quicksort(array, 0, size - 1);
    return "quick_sort";
}