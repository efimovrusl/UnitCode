#include "libmx.h"

int mx_sqrt(int x) {
    if (x < 0) return 0;
    int counter = 0;
    while (x > counter * counter) {
        counter++;
        if (counter == 46341) return 0;
        if (counter * counter == x) return counter;
    }
    return 0;
}
