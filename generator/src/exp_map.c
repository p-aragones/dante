/*
** EPITECH PROJECT, 2021
** export map
** File description:
** maze
*/

#include "generator.h"

char *arr_to_str(char **maze, int x, int y)
{
    char *map = malloc(sizeof(char) * ((x + 1) * y));
    int i = 0;
    int e = 0;
    int c = 0;

    while (i < y) {
        c = 0;
        while (c < x) {
            map[e] = maze[i][c];
            e++;
            c++;
        }
        if (i != (y - 1)) {
            map[e] = '\n';
            e++;
        }
        i++;
    }
    return (map);
}

int exp_map(char **maze, int x, int y)
{
    char *map = arr_to_str(maze, x, y);

    printf("%s\n", map);
    return (0);
}