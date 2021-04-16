/*
** EPITECH PROJECT, 2021
** solver
** File description:
** a star algorithm file with the main funciton
*/

#include "solver.h"

point_t *create_point(int x, int y)
{
    point_t *point = malloc(sizeof(point_t));

    if (point == NULL)
        return (NULL);
    point->x = x;
    point->y = y;
    return (point);
}

point_t *find_end(char **map)
{
    point_t *end = NULL;
    int i = 0;
    int j = 0;

    while (map[i]) {
        j = 0;
        while (map[i][j]) {
            j++;
        }
        i++;
    }
    end = create_point(j - 1, i - 1);
    return (end);
}

char **end_found(char **map, cell_t *node, cell_t ***grid)
{
    my_putstr("found\n");
    while (node->pos->x != 0 && node->pos->y != 0) {
        //printf("node: x: %d y: %d\n", node->pos->x, node->pos->y);
        map[node->pos->y][node->pos->x] = 'o';
        if (node->parent)
            node = node->parent;
    }
    print_array(map);
    return (map);
}

char **a_star(char **map, cell_t ***grid, point_t *end)
{
    list_t *open_list = NULL;
    list_t *closed_list = NULL;
    cell_t *node = NULL;
    int i = 0;

    open_list = add_start(open_list, grid[0][0]);
    while (list_len(open_list) > 0) {
        node = lower_f(open_list);
        if (end->x == node->pos->x && end->y == node->pos->y)
            map = end_found(map, node, grid);
        open_list = get_children(open_list, closed_list, node, grid);
        closed_list = add_start(closed_list, node);
        open_list = delete_current_node(open_list, node);
        i++;
    }
    return (map);
}