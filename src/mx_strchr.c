#include "libmx.h"

char* mx_strchr(const char* s, int c) {
    int res;
    if (c == '\0') 
        res = mx_strlen(s);
    else
        res = mx_get_char_index(s, c);
    switch (res) {
        case -2:
            return NULL;
        case -1:
            return NULL;
        default:
            return (char*)s + res;
    }
}
