#include "libmx.h"

int mx_bubble_sort(char **arr, int size) {
    int c, d, counter = 0;
    char *buffer;
    for (c = 0; c < size - 1; c++) {
        for (d = 0; d < size - c - 1; d++) {
            if (mx_strcmp(arr[d], arr[d + 1]) > 0) {
                buffer = arr[d];
                arr[d] = arr[d + 1];
                arr[d + 1] = buffer;
                counter++;
            }
        }
    }
    return counter;
}
