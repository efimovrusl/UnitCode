#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if (str == NULL || sub == NULL) return -2;
    char *ptr;
    for (int i = 0; i <= mx_strlen(str) - mx_strlen(sub); i++) {
        ptr = (char*)&str[i];
        int k = 0;
        for (; k < mx_strlen(sub); k++)
            if (ptr[k] != sub[k]) {
                ptr = NULL;
                break;
            }
        if (ptr != NULL) return i;
    }
    return -1;
}

/*
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
*/
