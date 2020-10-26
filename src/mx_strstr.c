#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
	char *t_haystack = (char *)haystack;
    char *t_needle = (char *)needle;
    
    if (!haystack || !needle) {
        return NULL;
    }
    if (!mx_strlen(needle)) {
        return t_haystack;
    }
    while (*t_haystack) {
        if (!mx_strncmp(t_haystack, t_needle, mx_strlen(t_needle))) {
            return t_haystack;
        }
        t_haystack++;
    }
    return NULL;
}
