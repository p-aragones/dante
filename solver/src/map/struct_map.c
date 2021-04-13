/*
** EPITECH PROJECT, 2021
** B-CPE-200-BAR-2-1-dante-pol.aragones
** File description:
** struct_map
*/

#include "solver.h"

int len_y(char **map)
{
    int i = 0;

    while (map[i]) {
        i++;
    }
    return (i);
}

cell_t *create_cell(char **map, int y, int x, point_t *end)
{
    cell_t *cell = malloc(sizeof(cell_t));

    if (cell == NULL)
        return (NULL);
    cell->c = map[y][x];
    cell->f = calculate_f(x, y, end->x, end->y);
    cell->g = calculate_g(x, y);
    cell->pos = create_point(0, 0);
    cell->pos->x = x;
    cell->pos->y = y;
    cell->end = end;
    if (map[y][x] == 'X')
        cell->walkable = 0;
    else
        cell->walkable = 1;
    return (cell);
}

cell_t ***cell_map(char **map, point_t *end)
{
    cell_t ***cells = malloc(sizeof(cell_t) * (len_y(map) + 1));
    int i = 0;
    int j = 0;

    if (cells == NULL)
        return (NULL);
    while (map[i]) {
        cells[i] = malloc(sizeof(cell_t) * (my_strlen(map[i]) + 1));
        if (cells[i] == NULL)
            return (NULL);
        while (map[i][j]) {
            cells[i][j] = create_cell(map, i, j, end);
            j++;
        }
        j = 0;
        i++;
    }
    cells[i] = NULL;
    return (cells);
}