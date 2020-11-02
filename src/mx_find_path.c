#include "pathfinder.h"
#include "stdio.h"

int mx_get_id(vertex ***vertexes, vertex *curr);
vertex *mx_next_vertex(vertex ***vertexes, t_list *paths, t_list *fail_paths, t_list *stack);
// void mx_shrink_stack(vertex ***vertexes, t_list **stack, char *colors);
void mx_shrink_stack(vertex ***vertexes, t_list *paths, t_list *fail_paths, t_list **stack);
bool mx_is_unique_with_vertex(t_list *paths, t_list *fail_paths, t_list *stack, vertex *next);

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
    mx_breadth_search(arr_v, mx_get_vertex(vertexes, "fifth"), mx_get_vertex(vertexes, "first"));
    // mx_path_to(arr_v, mx_get_vertex(vertexes, "fifth"), mx_get_vertex(vertexes, "first"));
}

t_list **mx_path_to(vertex ***vertexes, vertex *v1, vertex *v2) {
    if (!vertexes || !*vertexes || !v1 || !v2) return NULL;
    int size = 0;
    for (; vertexes[size]; size++);

    // char *colors = mx_strnew(size);
    int id1 = 0, id2 = 0;

    for (; vertexes[id1][0] != v1 && id1 <= size; id1++);
    for (; vertexes[id2][0] != v2 && id2 <= size; id2++);

    if (id1 == size || id2 == size) {
        return NULL;
    }

    t_list *paths = NULL, *fail_paths = NULL, *stack = NULL;
    mx_push_back(&stack, v1);
    
    while (stack) {
        vertex *next = mx_next_vertex(vertexes, paths, fail_paths, stack);
        printf("pointer to next: %p\n", (void *)next);
        if (next) {
            mx_push_back(&stack, next);
            if (next == v2) {
                mx_push_back(&paths, stack);
                stack = mx_list_cpy((t_list *)(mx_get_back(paths)->data));

                
                printf("stack amount: %i\n", mx_list_size(paths));
                //////////////////////////////////
                t_list *buf = stack;
                printf(">---< NEW STACK >---<\n");
                while (buf) {
                    printf("N_A_M_E: %s\n", ((vertex *)(buf->data))->name);
                    buf = buf->next;
                }
                //////////////////////////////////
                mx_shrink_stack(vertexes, paths, fail_paths, &stack);
                
                printf("|||| YEEEAH MAN ||||\n");
                continue;
            }
        } else if (!next && mx_is_unique_with_vertex(paths, fail_paths, stack, next)) {
            mx_push_back(&fail_paths, stack);
            stack = mx_list_cpy((t_list *)(mx_get_back(fail_paths)->data));
            mx_shrink_stack(vertexes, paths, fail_paths, &stack);
        } else {
            mx_shrink_stack(vertexes, paths, fail_paths, &stack);
        }
    }
    printf("fail paths: %i\n", mx_list_size(fail_paths));
    for (int i = 0; fail_paths; i++) {
        stack = (t_list *)(fail_paths->data);
        printf("fail stack #%i:\n", i);
        while (stack) {
            printf("N_A_M_E_: %s\n", ((vertex *)(stack->data))->name);
            stack = stack->next;
        }
        fail_paths = fail_paths->next;
    }
    printf("paths: %i\n", mx_list_size(paths));
    for (int i = 0; paths; i++) {
        stack = (t_list *)(paths->data);
        printf("stack #%i:\n", i);
        while (stack) {
            printf("N_A_M_E_: %s\n", ((vertex *)(stack->data))->name);
            stack = stack->next;
        }
        paths = paths->next;
    }

    return NULL;
}

vertex *mx_next_vertex(vertex ***vertexes, t_list *paths, t_list *fail_paths, t_list *stack) {
    printf("mx_next_vertex\n");
    t_list *_paths = paths;
    t_list *_stack;
    for (int i = 0; _paths; i++) {
        _stack = (t_list *)(_paths->data);
        printf("stack #%i\n", i);
        while (_stack) {
            printf("%s ", ((vertex *)(_stack->data))->name);
            _stack = _stack->next;
        }
        printf("\n");
        _paths = _paths->next;
    }
    t_list *edges = ((vertex *)(mx_get_back(stack)->data))->bridges;
    while (edges) {
        int id = mx_get_id(vertexes, ((edge *)(edges->data))->opposite);
        printf("\tedges->opposite->ID: %i\n", id);
        if (mx_is_unique_with_vertex(paths, fail_paths, stack, vertexes[id][0]) 
            && !mx_has_vertex_address(stack, vertexes[id][0])) {
            // sleep(1);
            return vertexes[id][0];
        }
        edges = edges->next;
    }
    return NULL;
}

void mx_shrink_stack(vertex ***vertexes, t_list *paths, t_list *fail_paths, t_list **stack) {
    if (stack == NULL || *stack == NULL) return;
    mx_pop_back(stack);
    while (*stack) {
        // getting line edges top stack element
        // if (mx_next_vertex(vertexes, stack, colors)) return;
        vertex **line = vertexes[mx_get_id(vertexes, (vertex *)(mx_get_back(*stack)->data))];
        for (int i = 1; line[i]; i++)
            if (mx_is_unique_with_vertex(paths, fail_paths, *stack, line[i])
                && mx_has_vertex_address(*stack, line[i])) {
                return; 
            }
        mx_pop_back(stack);
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


bool mx_is_unique_with_vertex(t_list *paths, t_list *fail_paths, t_list *stack, vertex *next) {
    bool unique = false;
    t_list *stack_free = mx_list_cpy(stack);
    mx_push_back(&stack_free, next);
    t_list *check_list, *stack_dup, *paths2 = paths;
    while (paths) {
        check_list = (t_list *)(paths->data);
        stack_dup = stack;
        unique = false;
        while (check_list && stack_dup && !unique) {
            if (((vertex *)(stack_dup->data))->name != ((vertex *)(check_list->data))->name)
                unique = true;
            stack_dup = stack_dup->next;
            check_list = check_list->next;
        }
        if (unique)
            break;
        paths = paths->next;
    }
    paths = paths2;
    if (unique)
    while (paths) {
        check_list = (t_list *)(fail_paths->data);
        stack_dup = stack;
        unique = false;
        while (check_list && stack_dup && !unique) {
            if (((vertex *)(stack_dup->data))->name != ((vertex *)(check_list->data))->name)
                unique = true;
            stack_dup = stack_dup->next;
            check_list = check_list->next;
        }
        if (!unique)
            break;
        paths = paths->next;
    }
    mx_clear_list(&stack_free);
    return unique;
}


// bool mx_is_unique_with_vertex(t_list *paths, t_list *fail_paths, t_list *stack, vertex *next) {
//     printf("mx_unique_with_vertex\n");
//     printf("stack:\n");
//     t_list *buf = stack;
//     while (buf) {
//         printf("\tstack->name: %s\n", ((vertex *)(buf->data))->name);
//         buf = buf->next;
//     }
//     if (!paths) return true;
//     bool is_unique;
//     t_list *stack_to_free = mx_list_cpy(stack);
//     mx_push_back(&stack_to_free, next);
//     t_list *primal_paths = paths;
//     while (paths) {
//         t_list *temp_pa = (t_list *)(paths->data);
//         t_list *temp_st = stack_to_free;
//         is_unique = false;
//         while (temp_pa && temp_st && !is_unique) {
//             if (mx_strcmp(((vertex *)(temp_pa->data))->name, ((vertex *)(temp_st->data))->name))
//                 is_unique = true;
//             temp_pa = temp_pa->next;
//             temp_st = temp_st->next;
//         }
//         if (!is_unique)
//             break;
//         paths = paths->next;
//     }
//     paths = primal_paths;
//     if (is_unique)
//     while (paths) {
//         t_list *temp_pa = (t_list *)(fail_paths->data);
//         t_list *temp_st = stack_to_free;
//         is_unique = false;
//         while (temp_pa && temp_st && !is_unique) {
//             if (mx_strcmp(((vertex *)(temp_pa->data))->name, ((vertex *)(temp_st->data))->name) 
//                 || (!temp_st->next && temp_pa->next))
//                 is_unique = true;
//             temp_pa = temp_pa->next;
//             temp_st = temp_st->next;
//         }
//         if (!is_unique)
//             break;
//         paths = paths->next;
//     }
//     mx_clear_list(&stack_to_free);
//     char *return_str = is_unique ? "TRUE" : "FALSE";
//     printf("\t\tRETURN: >>%s<< aka %i\n", return_str, is_unique);
//     return is_unique;
// }
