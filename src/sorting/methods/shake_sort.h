char *shake_sort(char **array, int size) {
    int left = 1;
    int right = size - 1;
    int k = size - 1;

    do {
        for (int j = right; j >= left; j--) {
            if (compare(array[j - 1], array[j]) > 0) {
                swap(array[j - 1], array[j]);
                k = j;
            }
        }

        left = k + 1;

        for (int j = left; j <= right; j++) {
            if (compare(array[j - 1], array[j]) > 0) {
                swap(array[j - 1], array[j]);
                k = j;
            }
        }

        right = k - 1;
    } while (left <= right);

    return "shake_sort";
}