#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    size_t cur_size;
    void *new_ptr;
   
    if (!ptr) {
	    return malloc(size);
    }
    #ifdef os_mac
        cur_size = malloc_size(ptr);
    #elif defined(os_linux)
        cur_size = malloc_usable_size(ptr);
    #else
        cur_size = 0;
    #endif
    if (size <= cur_size) {
	    return ptr;
    }
    new_ptr = malloc(size);
    mx_memcpy(new_ptr, ptr, cur_size);
    free(ptr);
    return new_ptr;
}
