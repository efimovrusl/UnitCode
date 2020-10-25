#include "libmx.h"

t_list *mx_get_by_index(t_list *head, int index) {
    if (head == NULL) return NULL;
    if (index >= mx_list_size(head)) {
        while (head->next)
            head = head->next;
        return head;
    }
    for (int i = 0; i < index; i++)
        head = head->next;
    return head;
}
