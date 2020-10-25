#include "libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (buf_size == 0) return -2;
    int res = 0;
    size_t bytes;
    char *buffer = mx_strnew(buf_size);
    if (read(fd, buffer, buf_size) == -1) return -2;
    while((bytes = read(fd, buffer, buf_size)) > 0) {
        if (mx_get_char_index(buffer, delim) >= 0) {
            buffer[mx_get_char_index(buffer, delim)] = '\0';
            *lineptr = mx_strjoin_free(*lineptr, buffer);
            res += mx_strlen(buffer);
            return res;
        }
        if (bytes < 0) return -1;
        *lineptr = mx_strjoin_free(*lineptr, buffer);
        res += bytes;
    }
    free(buffer);
    return res;
}
