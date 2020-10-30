#include "pathfinder.h"

bool mx_is_int(char *str) {
    if (mx_strlen(str) == 0) return false;
    char *buffer = mx_strtrim(str);
    bool isNegative = false;
    if (buffer[0] == '+' || buffer[0] == '-') {
        if (buffer[0] == '-') isNegative = true;
        mx_strncpy(buffer, buffer + 1, mx_strlen(buffer) - 1);
        buffer[mx_strlen(buffer) - 1] = '\0';
    }
    int not_needed_zeros = 0;
    for (int i = 0; buffer[i] == '0'; i++, not_needed_zeros++);
    if (not_needed_zeros > 0) {
        mx_strncpy(buffer, buffer + not_needed_zeros, mx_strlen(buffer) - not_needed_zeros);
        buffer[mx_strlen(buffer) - not_needed_zeros] = '\0';
    }
    buffer = mx_strdup_free(buffer);
    for (int i = 0; i < mx_strlen(buffer); i++) {
        if (!mx_isdigit(buffer[i])) {
            free(buffer);
            return false;
        }
    }
    if (mx_strlen(buffer) > 10) {
        free(buffer);
        return false;
    }
    if (mx_strlen(buffer) == 10) {
        if (isNegative) {
            if (mx_strcmp(buffer, "2147483648") > 0) {
                free(buffer);
                return false;
            }
        } else {
            if (mx_strcmp(buffer, "2147483647") > 0) {
                free(buffer);
                return false;
            }
        }
    }
    free(buffer);
    return true;
}

bool mx_is_long(char *str) {
    if (mx_strlen(str) == 0) return false;
    char *buffer = mx_strtrim(str);
    bool isNegative = false;
    if (buffer[0] == '+' || buffer[0] == '-') {
        if (buffer[0] == '-') isNegative = true;
        mx_strncpy(buffer, buffer + 1, mx_strlen(buffer) - 1);
        buffer[mx_strlen(buffer) - 1] = '\0';
    }
    int not_needed_zeros = 0;
    for (int i = 0; buffer[i] == '0'; i++, not_needed_zeros++)
        ;
    if (not_needed_zeros > 0) {
        mx_strncpy(buffer, buffer + not_needed_zeros, mx_strlen(buffer) - not_needed_zeros);
        buffer[mx_strlen(buffer) - not_needed_zeros] = '\0';
    }
    buffer = mx_strdup_free(buffer);
    for (int i = 0; i < mx_strlen(buffer); i++) {
        if (!mx_isdigit(buffer[i])) {
            free(buffer);
            return false;
        }
    }
    if (mx_strlen(buffer) > 19) {
        free(buffer);
        return false;
    }
    if (mx_strlen(buffer) == 19) {
        if (isNegative) {
            if (mx_strcmp(buffer, "9223372036854775808") > 0) {
                free(buffer);
                return false;
            }
        } else {
            if (mx_strcmp(buffer, "9223372036854775807") > 0) {
                free(buffer);
                return false;
            }
        }
    }
    free(buffer);
    return true;
}

bool mx_is_pos_num(char *num) {
    char *str = mx_strtrim(num);
    if (mx_strlen(str) == 0) return false;
    if (str[0] == '+')
        str = mx_strncpy(str, str + 1, mx_strlen(str));
    if (str[0] == '-')
        return false;
    for (int i = 0; i < mx_strlen(str); i++)
        if (!mx_isdigit(str[i]))
            return false;
    return true;
}
