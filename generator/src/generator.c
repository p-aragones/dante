/*
** EPITECH PROJECT, 2021
** genarator main
** File description:
** main funcs
*/

#include "generator.h"

int get_move(char **maze, int *c, int x, int y)
{
    int r = rand() % 4;
    int i = 0;

    while (i < 4) {
        if (r == 0) {
            if (c[1] < x - 2 && maze[c[0]][c[1] + 2] != 'X')
                return (r);
        }
        if (r == 1) {
            if (c[0] < y - 2 && maze[c[0] + 2][c[1]] != 'X')
                return (r);
        }
        if (r == 2) {
            if (c[1] > 1 && maze[c[0]][c[1] - 2] != 'X')
                return (r);
        }
        if (r == 3) {
            if (c[0] > 1 && maze[c[0] - 2][c[1]] != 'X')
                return (r);
        }
        r++;
        if (r == 4)
            r = 0;
        i++;
    }
    return (-1);
}

char **create_maze(char **maze, int x, int y)
{
    int *c = malloc(sizeof(int) * 2);
    int *p = malloc(sizeof(int) * 2);
    int m = 5;

    c[0] = 0;
    c[1] = 0;
    while (c[0] != y - 1 || c[1] != x - 1) {
        m = get_move(maze, c, x, y);
        if (m == 0) {
            maze[c[0]][c[1]] = ' ';
            maze[c[0]][c[1] + 1] = ' ';
            p = c;
            c[1] = c[1] + 2;
        }
        if (m == 1) {
            maze[c[0]][c[1]] = ' ';
            maze[c[0] + 1][c[1]] = ' ';
            p = c;
            c[0] = c[0] + 2;
        }
        if (m == 2) {
            maze[c[0]][c[1]] = ' ';
            maze[c[0]][c[1] - 1] = ' ';
            p = c;
            c[1] = c[1] - 2;
        }
        if (m == 3) {
            maze[c[0]][c[1]] = ' ';
            maze[c[0] - 1][c[1]] = ' ';
            p = c;
            c[0] = c[0] - 2;
        }
    }
    return (maze);
}

char square(char maze, int i, int c)
{
    maze = 'e';
    if (i % 2 != 0)
        maze = 'X';
    else if (c % 2 != 0)
        maze = 'X';
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
            maze[i][c] = square(maze[i][c], i, c);
            c++;
        }
        i++;
    }
    maze[i - 1][c - 1] = '*';
    maze[i - 1][c - 2] = '*';
    maze = create_maze(maze, x, y);
    i = exp_map(maze, x, y);
    return (i);
}