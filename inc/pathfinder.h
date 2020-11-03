#pragma once

#include "libmx.h"

struct vertex_s;
struct edge_s;

typedef struct edge_s {
    int weight;
    struct vertex_s *opposite;
} edge;

typedef struct vertex_s {
    char *name;
    t_list *bridges;
} vertex;

enum vertex_color {
    white, gray, black
};

t_list *mx_find_paths(t_list *vertexes);
t_list *mx_breadth_search(vertex ***vertexes, vertex *initial, vertex *required);

vertex *mx_new_vertex(char *name);
vertex *mx_get_vertex(t_list *vertexes, char *name);
void mx_add_edge(t_list *vertexes, char *name1, char *name2, int weight);
void mx_show_graph(t_list *vertexes);
void mx_free_graph(t_list **vertexes);
void mx_show_paths(t_list *paths);

int mx_get_id(vertex ***vertexes, vertex *curr);
int mx_path_length(t_list *vertexes);

bool mx_is_pos_num(char *num);
bool mx_is_int(char *str);
bool mx_is_long(char *str);
bool mx_has_vertex_name(t_list *vertexes, char *name);
bool mx_has_vertex_address(t_list *vertexes, vertex *temp);
bool mx_has_edge(t_list *vertexes, char *vert1, char *vert2);
bool mx_is_correct_name(char *name);
bool mx_is_correct_num(char *name);
