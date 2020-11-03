#include "pathfinder.h"

void mx_search(vertex ***vertexes, t_list *checked, vertex *required, t_list **res_paths);

// needs NULL-terminated matrix
t_list *mx_breadth_search(vertex ***vertexes, vertex *initial, vertex *required) {
    t_list *checked = NULL;
    mx_push_front(&checked, initial);
    t_list *paths = NULL;
    mx_search(vertexes, checked, required, &paths);
    t_list *buf = paths;
    while (buf) {
        t_list *lol = (t_list *)(buf->data);
        printf("path:\n");
        while (lol) {
            printf("%s ", ((vertex *)(lol->data))->name);
            lol = lol->next;
        }
        printf("\n");
        buf = buf->next;
    }
    /**
     * @brief 
     * @https://github.com/efimovrusl list of shortest paths
     */
    return NULL;
}

void mx_search(vertex ***vertexes, t_list *checked, vertex *required, t_list **res_paths) {
    if ((vertex *)(checked->data) == required) {
        mx_push_front(res_paths, checked);
        return;
    }
    t_list *paths = NULL;
    int line_id = mx_get_id(vertexes, (vertex *)(checked->data));
    vertex **line = vertexes[line_id];
    for (int i = 1; (unsigned long)(void *)line[i] > (unsigned long)0xff; i++) {
        if (!mx_has_vertex_address(checked, line[i])) {
            t_list *new_checked = mx_list_cpy(checked);
            mx_push_front(&new_checked, line[i]);
            mx_search(vertexes, new_checked, required, res_paths);
            if ((vertex *)(new_checked->data) != required)
                mx_clear_list(&new_checked);
        }   
    }
}
