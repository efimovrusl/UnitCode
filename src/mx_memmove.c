#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    if (dst == NULL) return NULL;
    if (src == NULL) return dst;
    char *buffer = (char*)malloc(len);
    mx_memcpy(buffer, src, len);
    void* fuck = mx_memcpy(dst, buffer, len);
    free(buffer);
    return fuck;
}
