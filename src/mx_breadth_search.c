#include "pathfinder.h"

void mx_multiply_and_join(t_list **paths, t_list *new_paths);
t_list *mx_search(vertex ***vertexes, t_list *checked, vertex *required);

// needs NULL-terminated matrix
t_list *mx_breadth_search(vertex ***vertexes, vertex *initial, vertex *required) {
    t_list *checked = NULL;
    mx_push_front(&checked, initial);
    printf("let's begin!\n");
    t_list *paths = mx_search(vertexes, checked, required);
    printf("WE FOUND SMTH!\n");
    /**
     * @brief 
     * process paths list
     * return list of shortest paths
     */
    return NULL;
}

t_list *mx_search(vertex ***vertexes, t_list *checked, vertex *required) {
    printf("nice ");
    if ((vertex *)(checked->data) == required) {
        mx_clear_list(&checked);
        printf("WE FOUND PATH!\n");
        return NULL;
    }
    printf("done!\n\t");

    t_list *buffer = checked;
    while (buffer) {
        printf("%s, ", ((vertex *)(buffer->data))->name);
        buffer = buffer->next;
    }
    printf("\n");

    t_list *paths = NULL, *primal_paths = NULL;
    int line_id = mx_get_id(vertexes, (vertex *)(checked->data));
    vertex **line = vertexes[line_id];
    for (int i = 1; line[i]; i++) {
        if (!mx_has_vertex_address(checked, line[i])) {
            printf("\tname: %s\n", line[i]->name);
            t_list *new_checked = mx_list_cpy(checked);
            mx_push_front(&new_checked, line[i]);
            printf("pushed front!\n");
            t_list *res = mx_search(vertexes, new_checked, required);
            mx_multiply_and_join(&paths, res);
            printf("multiplied and joined!\n");
            if (!primal_paths && paths)
                primal_paths = paths;
            paths = paths->next;
        }
    }
    mx_pop_front(&paths);
    return paths;
}

void mx_multiply_and_join(t_list **paths, t_list *new_paths) {
    printf("ARGUMENTS!!!!!!!!!!!!!!!!!!!! %p %p\n", (void *)paths, (void *)new_paths);
    t_list *primal = (t_list *)((*paths)->data);
    while (new_paths) {
        t_list *temp = mx_list_cpy(primal);
        mx_get_back(temp)->next = new_paths;
        mx_push_back(paths, temp);
        new_paths = new_paths->next;
    }
}
