#include "libmx.h"

char *mx_strdup(const char *str) {
	char *buffer = mx_strnew(mx_strlen(str));
	return mx_strcpy(buffer, str);
}
