#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    char *_dst = (char*)dst;
    char *_src = (char*)src;
    for (size_t i = 0; i < n && _src[i] != (char)c; i++)
        _dst[i] = _src[i];
    return dst;
}
