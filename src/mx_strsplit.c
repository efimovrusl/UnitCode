#include "libmx.h"

char **mx_strsplit(char const *s, char c) {
    if (s == NULL) return NULL;
    int amountW = mx_count_words(s, c);
    char **words = (char **)malloc((amountW + 1) * 8);
    words[amountW] = NULL;
    for (int i = 0, len = 0; i < amountW; i++, len = 0) {
        while (*s && *s == c) s++;
        while (*s && *s != c) s++, len++;
        words[i] = mx_strnew(len);
        mx_strncpy(words[i], s - len, len);
    }
    return words;
}
