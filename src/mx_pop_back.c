#include "libmx.h"

void mx_pop_back(t_list **head) {
    if (head == NULL || *head == NULL) return;
    t_list *temp = *head;
    t_list *prev = NULL;
    while (temp->next) {
        prev = temp;
        temp = temp->next;
    }
    // if (temp->data) free(temp->data);
    free(temp);
    if (prev) prev->next = NULL;
    else *head = NULL;
}
