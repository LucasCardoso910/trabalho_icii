char *bubble_sort(char **array, int size) {
    for (int i = 1; i < size; i++) {

        for (int j = size - 1; j >= i; j--) {

            if (compare(array[j - 1], array[j]) > 0) {
                swap(array[j - 1], array[j]);
            }
        }
    }

    return "bubble_sort";
}