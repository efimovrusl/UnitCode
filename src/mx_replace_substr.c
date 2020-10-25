#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (str == NULL || sub == NULL || replace == NULL)
        return NULL;
    if (mx_get_substr_index(str, sub) < 0)
        return mx_strdup(str);
    int sub_amount = mx_count_substr(str, sub);
    int len_diff = mx_strlen(replace) - mx_strlen(sub);
    int new_len = mx_strlen(str) + len_diff * sub_amount;
    char *result = mx_strnew(new_len);
    for (int i = 0, j = 0; i < new_len; i++) {
        if (mx_get_substr_index(&str[j], sub) != 0) {
            result[i] = str[j++];
        } else {
            for (int k = 0; k < mx_strlen(replace); k++, i++)
                result[i] = replace[k];
            j += mx_strlen(sub);
            i--;
        }
    }
    return result;
}
