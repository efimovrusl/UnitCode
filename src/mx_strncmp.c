#include "libmx.h"

int mx_strncmp(const char *s1, const char *s2, int n) {
    if (s1 == NULL && s2 != NULL) return -1;
    if (s2 == NULL && s1 != NULL) return 1;
    if (s1 == NULL && s2 == NULL) return 0;
    for (int i = 0; i < n; i++)
        if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0') return s1[i] - s2[i];
    return 0;
}
