#include "libmx.h"

void _swap_list_nodes(t_list *p1, t_list *p2) {
    long temp = (long)p1->data;
    p1->data = p2->data;
    p2->data = (void *)temp;
}
// selection sort
t_list *mx_sort_list(t_list *head, bool (*cmp)(void *a, void *b)) {
    if (head == NULL || cmp == NULL) return head;
    t_list *start = head;
    t_list *traverse;
    t_list *min;
    while (start->next) {
        min = start;
        traverse = start->next;
        while (traverse) {
            if ((*cmp)(min->data, traverse->data)) min = traverse;
            traverse = traverse->next;
        }                              /* Find minimum element from array */
        _swap_list_nodes(start, min);  // Put minimum element on starting location
        start = start->next;
    }
    return head;
}
