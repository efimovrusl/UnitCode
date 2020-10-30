#include "pathfinder.h"
#include "stdio.h"

int mx_get_id(vertex ***vertexes, vertex *curr);
vertex *mx_next_vertex(vertex ***vertexes, t_list *curr, char *colors);
void mx_shrink_stack(vertex ***vertexes, t_list **stack, char *colors);

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
    mx_path_to(arr_v, mx_get_vertex(vertexes, "first"), mx_get_vertex(vertexes, "fifth"));
}

t_list **mx_path_to(vertex ***vertexes, vertex *v1, vertex *v2) {
    if (!vertexes || !*vertexes || !v1 || !v2) return NULL;
    int size = 0;
    for (; vertexes[size]; size++);

    char *colors = mx_strnew(size);
    int id1 = 0, id2 = 0;

    for (; vertexes[id1][0] != v1 && id1 <= size; id1++);
    for (; vertexes[id2][0] != v2 && id2 <= size; id2++);

    if (id1 == size || id2 == size) {
        free(colors);
        return NULL;
    }

    t_list *paths = NULL, *stack = NULL;
    mx_push_back(&stack, v1);
    colors[mx_get_id(vertexes, v1)] = gray;
    /*while (true) {
        vertex *buffer = mx_next_vertex(vertexes, stack, colors);
        printf("fuck! buffer->name: %p\n", (void *)buffer);

        if (buffer == v2) {
            printf("\tfuck1!\n");
            mx_push_back(&stack, buffer);
            printf("pushed: %s\n", buffer->name);
            mx_push_back(&paths, stack);
            
            stack = mx_list_cpy((t_list *)mx_get_back(paths)->data);
            
            mx_shrink_stack(vertexes, &stack, colors);
            //////////
            printf("color:\n");
            for (int i = 0; vertexes[i]; i++)
                printf("%i ", (int)colors[i]);
            printf("\n");
            printf("copied list:\n");
            int size_ = mx_list_size(stack);
            t_list *buf_list = stack;
            for (int i = 0; i < size_ ; i++) {
                printf("\t%s\n", ((vertex *)(buf_list->data))->name);
                buf_list = buf_list->next;
            }
            //////////
        } else if (buffer) {
            printf("\tfuck2!\n");

            mx_push_back(&stack, buffer);
            colors[mx_get_id(vertexes, v2)] = white;
        } else if ((vertex *)(mx_get_back(stack)->data) == v2) {
            printf("\tfuck3!\n");

            mx_push_back(&paths, stack);
            stack = NULL;
        } else if (stack) {
            printf("\tfuck4!\n");

            mx_shrink_stack(vertexes, &stack, colors);
            colors[mx_get_id(vertexes, v2)] = white;
        } else if (stack == NULL) {
            printf("\tfuck5!\n");

            mx_clear_list(&stack);
            break;
        } else {
            mx_printerr("Lol this should have never happened :D Check \"mx_path_to()\"\n");
            break;
        }
    }*/
    return NULL;
}
// changes color so CAN'T be called twice with the same output result
vertex *mx_next_vertex(vertex ***vertexes, t_list *stack, char *colors) {
    t_list *edges = ((vertex *)(mx_get_back(stack)->data))->bridges;
    while (edges) {
        printf("colors: ");
        for (int i = 0; vertexes[i]; i++)
            printf("%i ", (int)colors[i]);
        printf("\n");
        int id = mx_get_id(vertexes, ((edge *)(edges->data))->opposite);
        printf("edges->opposite->ID: %i\n", id);
        if (id == -1) {
            continue;
        }
        if (colors[id] == white) {
            colors[id] = gray;
            return vertexes[id][0];
        }
        edges = edges->next;
    }
    return NULL;
}

void mx_shrink_stack(vertex ***vertexes, t_list **stack, char *colors) {
    if (stack == NULL || *stack == NULL) return;
    mx_pop_back(stack);
    while (*stack) {
        vertex **line = vertexes[mx_get_id(vertexes, (vertex *)(mx_get_back(*stack)->data))];
        for (int i = 1; line[i]; i++)
            if (colors[mx_get_id(vertexes, line[i])] == white)
                return;
            
        mx_pop_back(stack);
    }
}

int mx_get_id(vertex ***vertexes, vertex *curr) {
    printf("\t  get_id name: %s!!!\n", curr->name);
    if (curr == NULL)
        return -1;
    int id = 0;
    while (vertexes && vertexes[id] && vertexes[id][0] != curr)
        id++;
    return (vertexes && vertexes[id] && vertexes[id][0]) ? id : -1;
}
