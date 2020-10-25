#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int temp, counter = 0;
    if (mx_strcmp(sub, "") == 0) return 0;
    if (str == NULL || sub == NULL) return -1;
    for (int i = 0; i < mx_strlen(str); i++, str++) {
        temp = mx_get_substr_index(str + i, sub);
        if (temp >= 0) {
            counter++;
            i += temp + 1;
        }
    }

    return counter;
}
