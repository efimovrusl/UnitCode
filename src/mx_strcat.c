#include "libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    char *ptr = s1 + mx_strlen(s1);
    int s2len = mx_strlen(s2);
    for (int i = 0; i < s2len; i++) {
        ptr[i] = s2[i];
    }
    ptr[s2len] = '\0';
    return s1;
}
