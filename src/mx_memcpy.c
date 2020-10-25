#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    char *_dst = (char*)dst;
    char *_src = (char*)src;
    for (size_t i = 0; i < n; i++)
        _dst[i] = _src[i];
    return dst;
}
