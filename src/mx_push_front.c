#include "libmx.h"

void mx_push_front(t_list **list, void *data) {
    if (list == NULL) return;
    t_list *new;
    if ((new = mx_create_node(data))) {
        new->next = *list;
        *list = new;
    }
}
