#include "libmx.h"

int mx_count_words(const char *str, char delimiter) {
    if (str == NULL) return -1;
    int amount = 0;
    bool isInWord = false;
    while (*str) {
        if (*str != delimiter && !isInWord) {
            isInWord = true;
            amount++;
        } else if (*str++ == delimiter) {
            isInWord = false;
        }
    }
    return amount;
}
