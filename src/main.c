#include "pathfinder.h"

// #define test

#ifdef test
#include "stdio.h"

// int main() {
    // t_list *list = NULL;
    // for (int i = 0; i < 5; i++)
    //     mx_push_back(&list, mx_strjoin("fuck", mx_itoa(i)));
    // t_list *list2 = mx_list_cpy(list);
    // int size2 = mx_list_size(list2);
    // for (int i = 0; i < size2; i++) {
    //     printf("%s\n", (char *)(list2->data));
    //     list2 = list2->next;
    // }
// }
#endif

#ifndef test
int main(int argc, char *argv[]) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(-1);
    }
    int fd;
    if ((fd = open(argv[1], O_RDONLY)) == -1) {
        mx_printerr("error: file [");
        mx_printerr(argv[1]);
        mx_printerr("] does not exist\n");
        close(fd);
        exit(-1);
    }
    char *buffer = mx_strnew(1);
    int buf_int = read(fd, buffer, 1);
    close(fd);
    if (buf_int == 0 || buf_int == -1) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" is empty\n");
        free(buffer);
        exit(-1);
    }
    t_list *vertexes = NULL;
    long total_length = 0;
    char **is1_is2_len = (char **)malloc(sizeof(char *) * 4);
    for (int i = 0; i < 4; i++) is1_is2_len[i] = NULL;
    char *line = NULL, *temp = NULL;
    int amount_of_islands = 0;
    fd = open(argv[1], O_RDONLY);
    mx_read_line(&line, 1, '\n', fd);
    if (!mx_is_int(line) || (amount_of_islands = mx_atoi(line)) < 0) {
        mx_printerr("error: line 1 is not valid\n");
        free(buffer);
        mx_del_strarr(&is1_is2_len);
        if (line) free(line);
        close(fd);
        exit(-1);
    }
    buf_int = 2;
    // parse file to graph
    while (mx_read_line(&line, 1, '\n', fd) >= 0) {
        temp = line;
        is1_is2_len[0] = mx_strndup(temp, mx_get_char_index(temp, '-'));
        temp = line + mx_strlen(is1_is2_len[0]) + 1;
        is1_is2_len[1] = mx_strndup(temp, mx_get_char_index(temp, ','));
        temp = line + mx_strlen(is1_is2_len[0]) + mx_strlen(is1_is2_len[1]) + 2;
        is1_is2_len[2] = mx_strndup(temp, mx_get_char_index(temp, '\n'));
        if (mx_get_char_index(line, '-') < 0 || mx_get_char_index(line, ',') < 0
            || !mx_is_correct_name(is1_is2_len[0]) || !mx_is_correct_name(is1_is2_len[1]) || !mx_is_pos_num(is1_is2_len[2])) {
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(buf_int));
            mx_printerr(" is not valid\n");
            if (buffer) free(buffer);
            mx_del_strarr(&is1_is2_len);
            if (line) free(line);
            close(fd);
            exit(-1);
        }
        mx_strdel(&line);
        for (int i = 0; i < 2; i++) {
            if (!mx_has_vertex_name(vertexes, is1_is2_len[i])) {
                mx_push_back(&vertexes, mx_new_vertex(is1_is2_len[i]));
                amount_of_islands--;
            }
        }
        if (mx_has_edge(vertexes, is1_is2_len[0], is1_is2_len[1])) {
            mx_printerr("error: duplicate bridges\n");
            if (buffer) free(buffer);
            mx_del_strarr(&is1_is2_len);
            if (line) free(line);
            mx_free_graph(&vertexes);
            close(fd);
            exit(-1);
        } else {
            mx_add_edge(vertexes, is1_is2_len[0], is1_is2_len[1], mx_atoi(is1_is2_len[2]));
        }
        total_length += mx_atoi(is1_is2_len[2]);
        if (total_length > INT32_MAX || !mx_is_int(is1_is2_len[2])) {
            mx_printerr("error: sum of bridges lengths is too big\n");
            if (buffer) free(buffer);
            mx_del_strarr(&is1_is2_len);
            if (line) free(line);
            mx_free_graph(&vertexes);
            close(fd);
            exit(-1);
        }
        buf_int++;
    }
    if (amount_of_islands != 0) {
        mx_printerr("error: invalid number of islands\n");
        if (buffer) free(buffer);
        mx_del_strarr(&is1_is2_len);
        if (line) free(line);
        mx_free_graph(&vertexes);
        close(fd);
        exit(-1);
    }
    // mx_show_graph(vertexes);
    t_list *paths = mx_find_paths(vertexes);
    mx_show_paths(paths);
    if (buffer) free(buffer);
    mx_del_strarr(&is1_is2_len);
    if (line) free(line);
    mx_free_graph(&vertexes);
    close(fd);
}
#endif
