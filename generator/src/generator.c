/*
** EPITECH PROJECT, 2021
** genarator main
** File description:
** main funcs
*/

#include "generator.h"

int generator(int x, int y)
{
    char **maze = malloc(sizeof(char *) * y);
    int i = 0;
    int c = 0;

    while (i < y) {
        maze[i] = malloc(sizeof(char) * x);
        c = 0;
        while (c < x) {
            maze[i][c] = '*';
            c++;
        }
        i++;
    }
    i = exp_map(maze, x, y);
    return (i);
}