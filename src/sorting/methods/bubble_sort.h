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

char *improved_bubble_sort(char **array, int size) {
    int changed;
    int count = 1;

    do {
        changed = FALSE;

        for (int i = 0; i < size - count; i++) {
            if (compare(array[i], array[i + 1]) > 0) {
                swap(array[i], array[i + 1]);
                changed = TRUE;
            }
        }

        count++;
    } while (changed);

    return "improved_bubble_sort";
}

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