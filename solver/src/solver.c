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

    if (map_string == NULL)
        return (84);
    map = my_split(map_string, "\n");
    if (map == NULL)
        return (84);
    print_array(map);
    return (0);
}