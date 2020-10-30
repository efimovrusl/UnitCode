#include "libmx.h"

t_list *mx_list_cpy(t_list *list) {
    t_list *_new = NULL;
    while (list) {
        mx_push_back(&_new, list->data);
        list = list->next;
    }
    return _new;
}
