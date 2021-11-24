void merge(char **array, int left, int h, int right, char **new_array) {
    int i = left;
    int j = h + 1;
    int k = left - 1;

    while (i <= h && j <= right) {
        k++;

        if (compare(array[i], array[j]) < 0) {
            move(new_array[k], array[i]);
            i++;
        } else {
            move(new_array[k], array[j]);
            j++;
        }
    }

    while (i <= h) {
        k++;
        move(new_array[k], array[i]);
        i++;
    }

    while (j <= right) {
        k++;
        move(new_array[k], array[j]);
        j++;
    }
}

void mpass(char **array, int size, int subseq_size, char **new_array) {
    int i = 0;

    while (i < size - 2 * subseq_size + 1) {
        merge(array, i, i + subseq_size - 1, i + 2 * subseq_size - 1,
              new_array);
        i += 2 * subseq_size;
    }

    if (i + subseq_size < size) {
        merge(array, i, i + subseq_size - 1, size - 1, new_array);
    } else {
        for (int j = i; j < size; j++) {
            move(new_array[j], array[j]);
        }
    }
}

char *merge_sort(char **array, int size) {
    char **new_array;
    int subseq_size = 1;

    new_array = (char **)malloc(sizeof(char *) * size);
    for (int i = 0; i < size; i++) {
        new_array[i] = (char *)malloc(sizeof(char) * STRING_SIZE);
    }

    while (subseq_size < size) {
        mpass(array, size, subseq_size, new_array);
        subseq_size *= 2;
        mpass(new_array, size, subseq_size, array);
        subseq_size *= 2;
    }

    return "merge_sort";
}