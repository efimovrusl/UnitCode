#include "libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    if (src == NULL) return NULL;
    char *ptr = dst;
    int i = 0;
    for (; src[i] != '\0' && i < len; i++) dst[i] = src[i];
    for (; dst[i] != '\0' && i < len; i++) dst[i] = '\0';
    if (mx_strlen(dst) >= len) dst[len] = '\0';
    return ptr;
}
