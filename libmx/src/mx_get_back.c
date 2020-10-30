#include "libmx.h"

t_list *mx_get_back(t_list *list) {
    while (list->next) list = list->next;
    return list;
}
