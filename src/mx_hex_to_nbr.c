#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    if (hex == NULL) return 0;
    for (int i = 0; hex[i]; i++) {
        if (!(hex[i] >= '0' && hex[i] <= '9') &&
            !(hex[i] >= 'a' && hex[i] <= 'f') &&
            !(hex[i] >= 'A' && hex[i] <= 'F')) return 0;
    }
    int len = 0;
    unsigned long decimal = 0;
    const char *buf = hex;
    while (*buf++) len++;
    unsigned long j = 0;
    for (int i = 0; i < len; i++, j = 0) {
        if (mx_isdigit(hex[i]))
            j = hex[i] - '0';
        else if (mx_islower(hex[i]))
            j = hex[i] - 'a' + 10;
        else
            j = hex[i] - 'A' + 10;
        for (int k = i; k < len - 1; k++) j *= 16;
        decimal += j;
    }
    return decimal;
}
