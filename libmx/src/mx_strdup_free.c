#include "libmx.h"

char *mx_strdup_free(const char *str) {
    char *buffer = mx_strnew(mx_strlen(str));
    mx_strcpy(buffer, str);
    free((char*)str);
    return buffer;
}
