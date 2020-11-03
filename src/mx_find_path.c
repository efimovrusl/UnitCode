#include "pathfinder.h"

t_list *mx_find_paths(t_list *vertexes) {
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
    t_list *routes = NULL;
    for (int i = 0; arr_v[i]; i++) {
        for (int k = i + 1; arr_v[k]; k++) {
            if (routes)
                mx_get_back(routes)->next = mx_breadth_search(arr_v, arr_v[i][0], arr_v[k][0]);
            else
                routes = mx_breadth_search(arr_v, arr_v[i][0], arr_v[k][0]);
        }
    }
    return routes;
}

void mx_show_paths(t_list *routes) {
    while (routes) {
        t_list *stack = (t_list *)routes->data;
        t_list *copy = mx_list_cpy(stack);
        for (int i = 0; i < 40; i++) mx_printchar('=');
        mx_printstr("\nPath: ");
        mx_printstr(((vertex *)mx_get_back(stack)->data)->name);
        mx_printstr(" -> ");
        mx_printstr(((vertex *)stack->data)->name);
        mx_printstr("\nRoute: ");
        while (stack) {
            mx_printstr(((vertex *)mx_get_back(stack)->data)->name);
            if (stack->next) mx_printstr(" -> ");
            mx_pop_back(&stack);
        }
        stack = copy;
        int len = mx_path_length(stack);
        mx_printstr("\nDistance: ");
        if (mx_list_size(stack) == 2) {
            mx_printint(len);
            mx_printstr("\n");
        } else {
            while (stack && stack->next) {
                t_list *edges = (t_list *)((vertex *)mx_get_back(stack)->data)->bridges;
                mx_pop_back(&stack);
                while (edges) {
                    if (((edge *)(edges->data))->opposite == mx_get_back(stack)->data) {
                        mx_printint(((edge *)(edges->data))->weight);
                        if (stack->next) mx_printstr(" + ");
                        break;
                    }
                    edges = edges->next;
                }
            }
            mx_printstr(" = ");
            mx_printint(len);
            mx_printstr("\n");
        }
        for (int i = 0; i < 40; i++) mx_printchar('=');
        mx_printchar('\n');
        routes = routes->next;
    }
}

int mx_get_id(vertex ***vertexes, vertex *curr) {
    if (curr == NULL)
        return -1;
    int id = 0; 
    while (vertexes && vertexes[id] && vertexes[id][0] != curr)
        id++;
    return (vertexes && vertexes[id] && vertexes[id][0]) ? id : -1;
}

int mx_path_length(t_list *stack) {
    int length = 0;
    while (stack && stack->next) {
        t_list *edges = (t_list *)((vertex *)stack->data)->bridges;\
        while (edges) {
            if (((edge *)(edges->data))->opposite == stack->next->data) {
                length += ((edge *)(edges->data))->weight;
                break;
            }
            edges = edges->next;
        }
        stack = stack->next;
    }
    return length;
}
