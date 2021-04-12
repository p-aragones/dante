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

char **a_star(char **map)
{
    list_t *open_list = NULL;
    list_t *closed_list = NULL;
    list_t *current_node = NULL;
    point_t *end = find_end;
    point_t *pos = create_point(0, 0);
    int index = 0;

    if (end == NULL, pos == NULL)
        return (NULL);
    add_start(open_list, map[0][0], end, pos);
    while (list_len(open_list) > 0) {
        current_node = open_list;
        index = 0;
        get_better_f(current_node, open_list, &index, closed_list);
        add_end(current_node, map[pos->y][pos->x], end, pos);
        if (end->x == pos->x && end->y == pos->y)
            end_found();
        get_children(open_list, closed_list, map);
    }
}