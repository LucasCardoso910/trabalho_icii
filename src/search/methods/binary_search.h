int binary_search(char **array, int size, char key[STRING_SIZE]) {
    int left = 0;
    int right = size - 1;
    int medium;
    int result = -1;

    while (left < right) {
        medium = (right + left) / 2;

        if (strcmp(array[medium], key) < 0) {
            left = medium + 1;
        } else {
            right = medium;
        }
    }

    if (strcmp(array[right], key) == 0) {
        return right;
    }
    return -1;
}
