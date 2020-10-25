#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    if (big == NULL || little == NULL) return (void*)big;
    if (big_len == 0 || little_len == 0 || little_len > big_len) return NULL;
    char* _big = (char*)big;
    char* _little = (char*)little;
    for (size_t i = 0; i <= big_len - little_len; i++) {
        size_t k = 0;
        for (; k < little_len && _big[i + k] == _little[k]; k++);
        if (k == little_len) return &_big[i];
    }
    return NULL;
}
