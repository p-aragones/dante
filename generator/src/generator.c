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

    while (i++ < 4) {
        if (r == 0 || r == 4)
            if (c[1] < x - 2 && maze[c[0]][c[1] + 2] == 'e')
                return (r);
        if (r == 1 || r == 5)
            if (c[0] < y - 2 && maze[c[0] + 2][c[1]] == 'e')
                return (r);
        if (r == 2 || r == 6)
            if (c[1] > 1 && maze[c[0]][c[1] - 2] == 'e')
                return (r);
        if (r == 3)
            if (c[0] > 1 && maze[c[0] - 2][c[1]] == 'e')
                return (r);
        r++;
    }
    return (-1);
}

void allocate(char **maze, int **c, int i, int m)
{
    if (m == 0) {
        maze[c[i][0]][c[i][1] + 1] = '*';
        c[i + 1][1] = c[i][1] + 2;
        c[i + 1][0] = c[i][0];
    }
    if (m == 1) {
        maze[c[i][0] + 1][c[i][1]] = '*';
        c[i + 1][0] = c[i][0] + 2;
        c[i + 1][1] = c[i][1];
    }
    if (m == 2) {
        maze[c[i][0]][c[i][1] - 1] = '*';
        c[i + 1][1] = c[i][1] - 2;
        c[i + 1][0] = c[i][0];
    }
    if (m == 3) {
        maze[c[i][0] - 1][c[i][1]] = '*';
        c[i + 1][0] = c[i][0] - 2;
        c[i + 1][1] = c[i][1];
    }
}

char **create_maze(char **maze, int x, int y, int **c)
{
    int m = 0;
    int i = 0;

    c[0] = malloc(sizeof(int) * 2);
    c[0][0] = 0;
    c[0][1] = 0;
    while (i != 0 || m != -1) {
        c[i + 1] = malloc(sizeof(int) * 2);
        m = get_move(maze, c[i], x, y);
        if (m >= 0 && m <= 3) {
            maze[c[i][0]][c[i][1]] = '*';
            allocate(maze, c, i, m);
        }
        if (m == -1) {
            maze[c[i][0]][c[i][1]] = '*';
            i = i - 2;
        }
        i++;
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
    int **c = malloc(sizeof(int *) * (x * y));
    int i = 0;
    int p = 0;

    while (i < y) {
        maze[i] = malloc(sizeof(char) * x);
        p = 0;
        while (p < x) {
            maze[i][p] = square(maze[i][p], i, p);
            p++;
        }
        i++;
    }
    maze[i - 1][p - 1] = 'e';
    maze[i - 1][p - 2] = 'e';
    maze = create_maze(maze, x, y, c);
    return (exp_map(maze, x, y));
}