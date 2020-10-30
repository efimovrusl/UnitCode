#include "pathfinder.h"
#include "stdio.h"
bool mx_has_vertex(t_list *vertexes, char *name) {
    while (vertexes) {
        if (mx_strcmp(((vertex *)vertexes->data)->name, name) == 0)
            return true;
        vertexes = vertexes->next;
    }
    return false;
}
// fuuuuck
bool mx_has_edge(t_list *vertexes, char *vert1, char *vert2) {
    t_list *temp1 = vertexes, *temp2 = vertexes;
    while (temp1) {
        if (mx_strcmp(((vertex *)temp1->data)->name, vert1) == 0) {
            break;
        }
        temp1 = temp1->next;
    }
    while (temp2) {
        if (mx_strcmp(((vertex *)temp2->data)->name, vert2) == 0) {
            break;
        } 
        temp2 = temp2->next;
    }
    if (temp1 && temp2) {
        t_list *edges = ((vertex *)temp1->data)->bridges;
        while (edges) {
            if ((vertex *)(((edge *)(edges->data))->opposite) == (vertex *)(temp2->data))
                return true;
            edges = edges->next;
        }
    }
    return false;
}
