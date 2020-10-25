#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    void *_new;
    if ((_new = malloc(size))) {
        mx_memset(_new, 0, size);
        if (ptr != NULL) {
            mx_memcpy(_new, ptr, size);
            free(ptr);
        }
    } else {
        return NULL;
    }
    return _new;
}
