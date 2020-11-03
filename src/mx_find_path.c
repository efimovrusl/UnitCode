#include "pathfinder.h"
#include "stdio.h"

void mx_find_paths(t_list *vertexes) {
    t_list *list_ptr = vertexes;
    vertex ***arr_v = (vertex ***)malloc((mx_list_size(vertexes) + 1) * sizeof(vertex **));
    arr_v[mx_list_size(vertexes)] = NULL;
    for (int i = 0; i < mx_list_size(vertexes); i++) {
        arr_v[i] = (vertex **)malloc((mx_list_size((t_list *)(((vertex *)(list_ptr->data))->bridges->data)) + 2) * sizeof(vertex *));
        arr_v[i][mx_list_size((t_list *)(((vertex *)(list_ptr->data))->bridges->data)) + 1] = NULL;
        arr_v[i][0] = (vertex *)(list_ptr->data);
        t_list *edges = (t_list *)((vertex *)(list_ptr->data))->bridges;
        for (int k = 1; k < mx_list_size((t_list *)((edge *)(list_ptr->data))) + 1 && edges; k++) {
            arr_v[i][k] = (vertex *)((edge *)edges->data)->opposite;
            edges = edges->next;
        }
        list_ptr = list_ptr->next;
    }
    mx_breadth_search(arr_v, mx_get_vertex(vertexes, "first"), mx_get_vertex(vertexes, "fifth"));
    // mx_path_to(arr_v, mx_get_vertex(vertexes, "fifth"), mx_get_vertex(vertexes, "first"));
}

int mx_get_id(vertex ***vertexes, vertex *curr) {
    if (curr == NULL)
        return -1;
    int id = 0; 
    while (vertexes && vertexes[id] && vertexes[id][0] != curr)
        id++;
    return (vertexes && vertexes[id] && vertexes[id][0]) ? id : -1;
}

int mx_path_length(t_list *vertexes) {
    int length = 0;
    while (vertexes && vertexes->next) {
        t_list *edges = (t_list *)((vertex *)vertexes->data)->bridges;
        vertex *next = NULL;
        while (edges) {
            if (((edge *)(edges->data))->opposite == vertexes->next->data) {
                length += ((edge *)(edges->data))->weight;
                break;
            }
            edges = edges->next;
        }
        vertexes = vertexes->next;
    }
    return length;
}
