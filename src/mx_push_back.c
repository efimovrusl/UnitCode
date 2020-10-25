#include "libmx.h"

void mx_push_back(t_list **list, void *data) {
    if (list == NULL) return;
    t_list *new;
    if ((new = mx_create_node(data))) {
        if (*list) {
            t_list *temp = *list;
            while (temp->next) temp = temp->next;
            temp->next = new;
        } else {
            *list = new;
        }
    }
}
