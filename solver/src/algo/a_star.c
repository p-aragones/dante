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
    end = create_point(j, i);
    return (end);
}

void end_found(void)
{
}

char **a_star(char **map, cell_t ***grid, point_t *end)
{
    list_t *open_list = NULL;
    list_t *closed_list = NULL;
    list_t *node = NULL;

    add_start(open_list, grid[0][0]);
    while (list_len(open_list) > 0) {
        node = open_list->cell;
        get_better_f(node, open_list, closed_list);
        add_end(node, node->cell);
        if (end->x == node->cell->pos->x && end->y == node->cell->pos->y)
            end_found();
        get_children(open_list, closed_list, node, grid);
    }
}