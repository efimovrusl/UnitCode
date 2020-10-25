#include "libmx.h"
#include "stdio.h"
void *mx_memrchr(const void *s, int c, size_t n) {
    char *_s = (char *)s;
    // for (int i = 0; i < mx_strlen(s); i++) {
    //     printf("STRLEN %c\n", _s[i]);
    // }
    for (size_t i = n - 1;; i--) {
        if (_s[i] == (char)c) return &_s[i];
        if (i == 0) break;
    }
    return NULL;
}
