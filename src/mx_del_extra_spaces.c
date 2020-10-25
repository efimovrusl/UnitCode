#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
    if (str == NULL) return NULL;
    int curr = 0;
    char *buffer = mx_strnew(mx_strlen(str));
    char *clean_str;
    bool in_word = false;
    for (int i = 0; i < mx_strlen(str); i++) {
        if (mx_isspace(str[i]) && in_word) {
            in_word = false;
            buffer[curr++] = ' ';
        } else if (!mx_isspace(str[i]) && !in_word) {
            in_word = true;
        }
        if (!mx_isspace(str[i]) && in_word) {
            buffer[curr++] = str[i];
        }
    }
    clean_str = mx_strtrim(buffer);
    free(buffer);
    return clean_str;
}
