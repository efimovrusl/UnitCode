#include "pathfinder.h"

vertex *mx_get_vertex(t_list *vertexes, char *name) {
    if (vertexes == NULL || name == NULL || !mx_has_vertex_name(vertexes, name)) return NULL;
    while (vertexes) {
        if (mx_strcmp(((vertex *)vertexes->data)->name, name) == 0)
            return vertexes->data;
        vertexes = vertexes->next;
    }
        
    return NULL;
}
