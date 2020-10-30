#include "pathfinder.h"

bool mx_is_correct_name(char *name) {
    bool is_correct = false;
    for (int i = 0; i < mx_strlen(name); i++) {
        if (mx_isalpha(name[i]))
            is_correct = true;
        else
            return false;
    }
    return is_correct;
}

bool mx_is_correct_num(char *name) {
    return mx_is_int(name) && mx_atoi(name) >= 0;
}
