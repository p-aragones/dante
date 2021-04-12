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

cell_t *create_cell(char c, int y, int x)
{
    cell_t *cell = malloc(sizeof(cell_t));

    if (cell == NULL)
        return (NULL);
    return (cell);
}

cell_t ***cell_map(char **map)
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
            cells[i][j] = create_cell(map[i][j], i, j);
            j++;
        }
        cells[i][j] = create_cell('\0', i, j);
        j = 0;
        i++;
    }
    cells[i] = NULL;
    return (cells);
}