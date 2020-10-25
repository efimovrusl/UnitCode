#include "libmx.h"

char *mx_file_to_str(const char *filename) {
    int file = 0;
    char *buffer = mx_strnew(0x400);
    char *str = NULL;
    if ((file = open(filename, O_RDONLY)) == -1) {
        close(file);
        return NULL;
    } else {
        int len = 0;
        while (read(file, buffer, 0x400))
            len += mx_strlen(buffer);
        close(file);
        file = open(filename, O_RDONLY);
        str = mx_strnew(len);
        read(file, str, len);
        close(file);
    }
    free(buffer);
    return str;
}
