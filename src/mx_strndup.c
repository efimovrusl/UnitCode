#include "libmx.h"

char *mx_strndup(const char *str, size_t n) {
    if (str == NULL) return NULL;
    char *buffer = mx_strnew(min(n, mx_strlen(str)));
    for (int i = 0; i < min(n, mx_strlen(str)); i++)
        buffer[i] = str[i];
    return buffer;
}
