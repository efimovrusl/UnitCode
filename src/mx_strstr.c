#include "libmx.h"

char *mx_strstr(const char *heystack, const char *needle) {
    if (heystack == NULL || needle == NULL) return NULL;
    char *ptr;
    for (int i = 0; i <= mx_strlen(heystack) - mx_strlen(needle); i++) {
        ptr = (char*)&heystack[i];
        for (int k = 0; k < mx_strlen(needle); k++)
            if (ptr[k] != needle[k]) {
                ptr = NULL;
                break;
            }
        if (ptr != NULL) return ptr;
    }
    return NULL;
}
