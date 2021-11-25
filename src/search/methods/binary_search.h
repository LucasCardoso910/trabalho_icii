int binary_search(char** array, int size, char key[STRING_SIZE]) {
    int left = 0;
    int right = size - 1;
    int medium;
    int result = -1;
    char wait;

    while (left < right) {
        medium = (right + left) / 2;

        if (strcmp(array[medium], key) < 0) {
            left = medium + 1;
        }
        else {
            right = medium;
        }
    }

    if (strcmp(array[right], key) == 0) {
        printf ("%d\n", right);
        return right;
    }
    printf ("%d\n", -1);
    return -1;

    // while (left <= right) {
    //     medium = (left + right) / 2;

    //     if (strcmp(array[medium], key) == 0) {
    //         result = medium;
    //         right = medium - 1;
    //     }
    //     else if(strcmp(key,array[medium]) < 0){
    //         right = medium - 1; //TODO: LOOK AT ME!
    //     }
    //     else{
    //         left = medium + 1;
    //     }
    // }

    // return result;
}
