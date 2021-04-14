/*
** EPITECH PROJECT, 2021
** genarator main
** File description:
** main funcs
*/

#include "generator.h"

char create_cell(char **maze, int y, int i, int c)
{
    int b = rand() % 3;

    if (b == 2)
        maze[i][c] = 'X';
    else
        maze[i][c] = '*';
    return (maze[i][c]);
}

char **create_maze(char **maze, int x, int y)
{
    int i = 0;
    int c = 0;

    while (i < y) {
        c = 0;
        while (c < x) {
            maze[i][c] = create_cell(maze, y, i, c);
            c++;
        }
        i++;
    }
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
            maze[i][c] = 'e';
            c++;
        }
        i++;
    }
    maze = create_maze(maze, x, y);
    i = exp_map(maze, x, y);
    return (i);
}