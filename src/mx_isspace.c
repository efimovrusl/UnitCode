#include "libmx.h"

bool mx_isspace(char c) {
    return c == 32 || (c >= 9 && c <= 13);
}
