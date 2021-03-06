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