#include "pathfinder.h"
// #include "stdio.h"
vertex *mx_new_vertex(char *name) {
    vertex *_new = (vertex *)malloc(sizeof(vertex));
    _new->bridges = NULL;
    _new->name = mx_strdup(name);
    return _new;
}

void mx_add_edge(t_list *vertexes, char *name1, char *name2, int weight) {
    t_list *temp1 = vertexes, *temp2 = vertexes;
    while (temp1) {
        if (mx_strcmp(((vertex *)(temp1->data))->name, name1) == 0) break;
        temp1 = temp1->next;
    }
    while (temp2) {
        if (mx_strcmp(((vertex *)(temp2->data))->name, name2) == 0) break;
        temp2 = temp2->next;
    }
    if (temp1 && temp2) {
        // write(1, "edge added!\n", 13);
        edge *_new1 = (edge *)malloc(sizeof(edge));
        edge *_new2 = (edge *)malloc(sizeof(edge));
        // printf("\ttemp1 %p\n", temp1->data);
        // printf("\ttemp2 %p\n", temp2->data);
        _new1->opposite = temp2->data;
        _new2->opposite = temp1->data;
        _new1->weight = weight;
        _new2->weight = weight;
        mx_push_back(&(((vertex *)temp1->data)->bridges), _new1);
        mx_push_back(&(((vertex *)temp2->data)->bridges), _new2);
    }
}

void mx_free_graph(t_list **vertexes) {
    if (!vertexes || !*vertexes) return;
    t_list *temp = *vertexes;
    while (temp) {
        mx_clear_list(&((vertex *)(temp->data))->bridges);
        temp = temp->next;
    }
    mx_clear_list(vertexes);
}

void mx_show_graph(t_list *vertexes) {
    mx_printstr("graph:\n");
    while (vertexes) {
        t_list *edges = (t_list *)((vertex *)(vertexes->data))->bridges;
        mx_printstr("\t");
        mx_printstr(((vertex *)(vertexes->data))->name);
        mx_printstr(" edges to:\n");
        while (edges) {
            mx_printstr("\t\t");
            mx_printstr(((edge *)(edges->data))->opposite->name);
            mx_printstr("\n");
            edges = edges->next;
        }
        vertexes = vertexes->next;
    }
}
