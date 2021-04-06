/*
** EPITECH PROJECT, 2021
** B-CPE-200-BAR-2-1-dante-pol.aragones
** File description:
** map error handling
*/

#include "solver.h"

int check_len(char **map)
{
    int i = 0;
    int len = my_strlen(map[0]);

    while (map[i]) {
        if (my_strlen(map[i]) != len)
            return (84);
        i++;
    }
    return (0);
}

int check_valid(char *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] != 'X' && str[i] != '*')
            return (84);
        i++;
    }
    return (0);
}

int check_chars(char **map)
{
    int i = 0;

    while (map[i]) {
        if (check_valid(map[i]) != 0)
            return (84);
        i++;
    }
}

int map_handling(char **map)
{
    if (check_len(map) != 0)
        return (84);
    if (check_chars(map) != 0)
        return (84);
    return (0);
}