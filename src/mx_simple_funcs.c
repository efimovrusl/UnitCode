#include "libmx.h"

bool mx_isalpha(int c) {
    return (c > 64 && c < 91) || (c > 96 && c < 123);
}

bool mx_isdigit(char c) {
    return (c >= '0' && c <= '9');
}

bool mx_islower(int c) {
    return c > 96 && c < 123;
}

bool mx_isupper(int c) {
    return c > 64 && c < 91;
}

int mx_static_abs(int num) {
    return num < 0 ? -num : num;
}

int min(int a, int b) {
    return a < b ? a : b;
}

bool mx_isspace(char c) {
    if (c == 32 || (c >= 9 && c <= 13))
        return 1;
    else
        return 0;
}
