#include "libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int low, high, mid;
    low = 0;
    high = size - 1;
    *count = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        (*count)++;
        if (mx_strcmp(s, arr[mid]) == 0) {
            return mid;
        } else if (mx_strcmp(s, arr[mid]) > 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    *count = 0;
    return -1;
}
