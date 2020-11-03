#include "pathfinder.h"

void mx_search(vertex ***vertexes, t_list *checked, vertex *required, t_list **res_paths);

bool mx_cmp_path_length(void *stack1, void *stack2) {
    return mx_path_length(stack1) > mx_path_length(stack2);
}

// needs NULL-terminated matrix
t_list *mx_breadth_search(vertex ***vertexes, vertex *initial, vertex *required) {
    t_list *checked = NULL;
    mx_push_front(&checked, initial);
    t_list *paths = NULL;
    mx_search(vertexes, checked, required, &paths);
    t_list *shortest, *prev = NULL, *buf = paths;
    int shortest_len;
    mx_sort_list(buf, mx_cmp_path_length);
    shortest_len = mx_path_length(buf->data);
    while (buf) {
        t_list *curr_stack = (t_list *)(buf->data);
        if (mx_path_length(curr_stack) != shortest_len) {
            if (prev) prev->next = NULL;
            mx_clear_list(&buf);
            break;
        }
        prev = buf;
        buf = buf->next;
    }
    return paths;
}

void mx_search(vertex ***vertexes, t_list *checked, vertex *required, t_list **res_paths) {
    if ((vertex *)(checked->data) == required) {
        mx_push_front(res_paths, checked);
        return;
    }
    vertex **line = vertexes[mx_get_id(vertexes, (vertex *)(checked->data))];
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
