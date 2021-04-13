/*
** EPITECH PROJECT, 2021
** genarator main
** File description:
** main funcs
*/

#include "generator.h"

char **create_maze(char **maze, int x, int y)
{
    return (maze);
}

int generator(int x, int y)
{
    char **maze = malloc(sizeof(char *) * y);
    int i = 0;
    int c = 0;

    while (i < y) {
        maze[i] = malloc(sizeof(char) * x);
        c = 0;
        while (c < x) {
            maze[i][c] = 'B';
            c++;
        }
        i++;
    }
    maze = create_maze(maze, x, y);
    i = exp_map(maze, x, y);
    return (i);
}