#include "libmx.h"

void mx_pop_front(t_list **head) {
    if (head == NULL || *head == NULL) return;
    // if ((*head)->data) free((*head)->data);
    t_list *next = (*head)->next;
    free(*head);
    *head = next;
}
