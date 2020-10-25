#include "libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
    for (int i = 0; arr[i] != NULL; i++) {
        mx_printstr(arr[i]);
        mx_printchar(*delim);
    }
}
