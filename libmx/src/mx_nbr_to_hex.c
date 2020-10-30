#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    char arr[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    unsigned long buffer = nbr;
    int length = 0;
    while (buffer != 0) length++, buffer /= 16;
    if (length == 0) length++;
    char *hex_num = mx_strnew(length);
    for (int i = length - 1; i >= 0; i--) {
        hex_num[i] = arr[nbr % 16];
        nbr /= 16;
    }
    return hex_num;
}
