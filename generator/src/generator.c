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
            if (c[1] < x - 2 && maze[c[0]][c[1] + 2] != '*')
                return (r);
        }
        if (r == 1) {
            if (c[0] < y - 2 && maze[c[0] + 2][c[1]] != '*')
                return (r);
        }
        if (r == 2) {
            if (c[1] > 1 && maze[c[0]][c[1] - 2] != '*')
                return (r);
        }
        if (r == 3) {
            if (c[0] > 1 && maze[c[0] - 2][c[1]] != '*')
                return (r);
        }
        r++;
        if (r == 4)
            r = 0;
        i++;
    }
    return (-1);
}

char **create_maze(char **maze, int x, int y, int **c)
{
    int m = 5;
    int i = 0;

    while (m != -1) {
        m = get_move(maze, c, x, y);
        if (m == 0) {
            maze[c[i][0]][c[i][1]] = '*';
            maze[c[i][0]][c[i][1] + 1] = '*';
            c[i][1] = c[i][1] + 2;
        }
        if (m == 1) {
            maze[c[i][0]][c[i][1]] = '*';
            maze[c[i][0] + 1][c[i][1]] = '*';
            c[i][0] = c[i][0] + 2;
        }
        if (m == 2) {
            maze[c[i][0]][c[i][1]] = '*';
            maze[c[i][0]][c[i][1] - 1] = '*';
            c[i][1] = c[i][1] - 2;
        }
        if (m == 3) {
            maze[c[i][0]][c[i][1]] = '*';
            maze[c[i][0] - 1][c[i][1]] = '*';
            c[i][0] = c[i][0] - 2;
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
    maze[i - 1][c - 1] = 'e';
    maze[i - 1][c - 2] = 'e';
    maze = create_maze(maze, x, y, p);
    return (exp_map(maze, x, y));
}