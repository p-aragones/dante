/*
** EPITECH PROJECT, 2021
** B-CPE-200-BAR-2-1-dante-pol.aragones
** File description:
** main solver file
*/

#include "solver.h"

int solver(char *path)
{
    char *map_string = read_file(path);
    char **map = NULL;
    cell_t ***grid = NULL;

    if (map_string == NULL)
        return (84);
    map = my_split(map_string, "\n");
    free (map_string);
    if (map == NULL)
        return (84);
    if (map_handling(map) != 0)
        return (84);
    grid = cell_map(map);
    if (grid == NULL)
        return (84);
    map = a_star(map, grid);
    print_array(map);
    free_array(map);
    return (0);
}