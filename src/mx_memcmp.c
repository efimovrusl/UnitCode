#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    if (s1 == NULL && s2 != NULL) return -1;
    if (s2 == NULL && s1 != NULL) return 1;
    if (s1 == NULL && s2 == NULL) return 0;
    char *_s1 = (char *)s1;
    char *_s2 = (char *)s2;
    for (size_t i = 0; i < n; i++)
        if (_s1[i] != _s2[i]) return _s1[i] - _s2[i];
    return 0;
}
