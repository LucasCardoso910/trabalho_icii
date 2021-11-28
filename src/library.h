#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

#define STRING_SIZE 12
#define FILENAME_SIZE 100
#define CSV_LINE 75
#define MONTH_STR_SIZE 6
#define FUNC_NAME_SIZE 25

#define METHD_FUNC_QTT 9
#define FILES_QTT 5

// General purpose functions prototypes
char **right_shift(char **array, int *size);
char **left_shift(char **array, int *size);
int compare(char *str1, char *str2);
void swap(char *obj1, char *obj2);
void move(char *dest, char *source);
void print(char **array, int size);
void print_subarray(char **array, int left, int right);
char **resize_array(char **array, int *size, int new_size);
FILE *open_file(char *filename, char *open_mode);
char **start_array(char **array, int *size);
void zero_counters();
char **expand_array(char **array, int *size);
char **read_file(char *filename, int *size);
void write_output_file(char filename[FILENAME_SIZE], char **content, int size);
char **copy_data(char **target, char **obj, int size);
void write_data_file(char filename[FILENAME_SIZE], char month[MONTH_STR_SIZE]);
void clean_answer(char answer[STRING_SIZE]);

// Sorting functions prototypes
char *bubble_sort(char **array, int size);
void heapify(char **array, int left, int right);
char *heap_sort(char **array, int size);
char *improved_bubble_sort(char **array, int size);
char *insert_binary_sort(char **array, int size);
char *insert_sort(char **array, int size);
void merge(char **array, int left, int h, int right, char **new_array);
void mpass(char **array, int size, int subseq_size, char **new_array);
char *merge_sort(char **array, int size);
char **quicksort(char **array, int left, int right);
char *selection_sort(char **array, int size);
char *shake_sort(char **array, int size);

// Search function prototypes
int binary_search(char **array, int size, char key[STRING_SIZE]);

// Structure for searching a desired code in the files with all relevant info
// to be printed to the user.
typedef struct found_code {
    int initial_index;
    int final_index;
} CODE;

int count_compare = 0; // Count number of comparisons made
int count_moves = 0;   // Count number of moves made
time_t start;
time_t end;

// The majority of sorting algorithms has no need of needing in the index 1, so
// was chosen that they must be 0 indexed. But there are a minority of cases
// that depend in the start at index 1, so this function works to transform a
// vector that is 0 indexed in 1 indexed by using realloc to increment its size
// and shifting all elements one to the right.
char **right_shift(char **array, int *size) {
    (*size)++;

    array = (char **)realloc(array, sizeof(char *) * (*size));
    for (int i = 0; i < (*size); i++) {
        array[i] = (char *)realloc(array[i], sizeof(char) * STRING_SIZE);
    }

    for (int i = (*size - 2); i >= 0; i--) {
        strcpy(array[i + 1], array[i]);
    }

    return array;
}

// Since all the other functions assume that the vector is 0 indexed, when we
// use the right_shift function, it is needed to change all elements back to its
// place and start again at zero. The left_shift does that by moving the
// elements one to the left and then reallocating the array one element less.
char **left_shift(char **array, int *size) {
    for (int i = 1; i < (*size); i++) {
        strcpy(array[i - 1], array[i]);
    }

    (*size)--;
    array = (char **)realloc(array, sizeof(char *) * (*size));

    return array;
}

// To increment the comparison counter every time and only when strcmp is called
// this "wrapper" function was created, executing always both as a pair.
int compare(char *str1, char *str2) {
    count_compare++;

    return strcmp(str1, str2);
}

// Atributes the value of obj1 in obj2 and vice-versa using the move function.
void swap(char *obj1, char *obj2) {
    char var[STRING_SIZE];

    move(var, obj1);
    move(obj1, obj2);
    move(obj2, var);
}

// Following the same logic in the compare function, this will atribute the
// value of source in dest, incrementing the value in the movementation counter.
void move(char *dest, char *source) {
    count_moves++;

    strcpy(dest, source);
}

// Shows in the screen the values in the array in a reasonable formatation.
void print(char **array, int size) { print_subarray(array, 0, size); }

// Prints a section of an array. It starts with element in the left index and
// goes to, but not including, the element in the right index.
void print_subarray(char **array, int left, int right) {
    for (int i = left; i < right; i++) {
        printf("%s\t", array[i]);
    }
    printf("\n");
}

// Changes the size in a dinamically allocated array and sets the size variable
// to the new array size.
char **resize_array(char **array, int *size, int new_size) {
    array = (char **)realloc(array, sizeof(char *) * new_size);
    (*size) = new_size;

    return array;
}

// Open a file with the path and open_mode given as parameter and deals with
// the case the file could not be open
FILE *open_file(char *filename, char *open_mode) {
    FILE *file;

    file = fopen(filename, open_mode);
    if (file == NULL) {
        printf("File is null! Check if file exists and its permissions!\n");
        exit(1);
    }

    return file;
}

// Performs the initial memory allocation of an array, allocating its main
// array and each string that will be part of it. The initial defined size to
// it is 3. The parameter size is a pointer only to retreave this new value,
// since while returning the pointer to the new array, it was not possible to
// receive this value.
char **start_array(char **array, int *size) {
    (*size) = 3;

    array = (char **)malloc(sizeof(char *) * (*size));
    for (int j = 0; j < (*size); j++) {
        array[j] = (char *)malloc(sizeof(char) * STRING_SIZE);
    }

    return array;
}

// Sets all the counters with value 0
void zero_counters() {
    count_compare = 0;
    count_moves = 0;
}

// Increments the size of an array in 3 and allocates its new strings.
char **expand_array(char **array, int *size) {
    array = resize_array(array, size, (*size) + 3);
    for (int j = *size - 3; j < (*size); j++) {
        array[j] = (char *)malloc(sizeof(char) * STRING_SIZE);
    }

    return array;
}

// Opens and closes a file in the reading mode and returns its content
char **read_file(char *filename, int *size) {
    char string[STRING_SIZE];
    int count = 0;
    char **array;
    FILE *file;

    zero_counters();

    file = open_file(filename, "r");
    array = start_array(array, size);

    while (fscanf(file, "%s\n", string) > 0) {
        if (count == (*size)) {
            array = expand_array(array, size);
        }

        strcpy(array[count], string);
        count++;
    }

    if (count != (*size)) {
        array = resize_array(array, size, count);
    }

    fclose(file);

    return array;
}

// Opens and close a file in the writing mode and writes the content given to it
// in the parameters in it.
void write_output_file(char filename[FILENAME_SIZE], char **content, int size) {
    FILE *file;

    file = open_file(filename, "w");

    for (int i = 0; i < size; i++) {
        fprintf(file, "%s\n", content[i]);
    }

    fclose(file);
}

// Returns a copy of the data given to it
char **copy_data(char **target, char **obj, int size) {
    target = (char **)malloc(sizeof(char *) * size);
    for (int i = 0; i < size; i++) {
        target[i] = (char *)malloc(sizeof(char) * STRING_SIZE);
        strcpy(target[i], obj[i]);
    }

    return target;
}

// Writes a .csv file with all the information registereds in the counter of
// comparisons and movimentations in a line with the month file that it relates
// to.
void write_data_file(char filename[FILENAME_SIZE], char month[MONTH_STR_SIZE]) {
    FILE *file;
    double time;

    time = (double)difftime(end, start) / CLOCKS_PER_SEC;

    file = open_file(filename, "a");
    fprintf(file, "%s,%d,%d,%f\n", month, count_compare, count_moves, time);
    fclose(file);
}

// Deals with the answer of a user, removing the \n if it exists and transform
// it in uppercase, to avoid mistakes made by the user.
void clean_answer(char answer[STRING_SIZE]) {
    answer[strcspn(answer, "\n")] = 0;

    for (int i = 0; i < STRING_SIZE; i++) {
        answer[i] = toupper(answer[i]);
    }
}