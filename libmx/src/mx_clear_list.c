#include "libmx.h"

void mx_clear_list(t_list **list) {
    if (!*list) return; 
    t_list *temp;
    while (*list) {
        temp = (*list)->next;
        free(*list);
        *list = temp;
    }
}
