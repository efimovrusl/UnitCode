#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    char *_s = (char *)s;
    for (size_t i = 0; i < n; i++)
        if (_s[i] == (char)c) return &_s[i];
    return NULL;
}
