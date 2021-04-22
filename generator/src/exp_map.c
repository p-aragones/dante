/*
** EPITECH PROJECT, 2021
** export map
** File description:
** maze
*/

#include "generator.h"

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

char **imperfect(char **maze, int x, int y, int n)
{
    int i = 0;
    int c = 0;

    if (n == 1)
        return (maze);
    while (i < (y - 1)) {
        maze[i][0] = '*';
        i++;
    }
    while (c < x) {
        maze[i][c] = '*';
        c++;
    }
    return (maze);
}

char *arr_to_str(char **maze, int x, int y, int n)
{
    char *map = malloc(sizeof(char) * (((x + 1) * y) + 1));
    int i = 0;
    int e = 0;
    int c = 0;

    maze = imperfect(maze, x, y, n);
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

int exp_map(char **maze, int x, int y, int n)
{
    char *map = arr_to_str(maze, x, y, n);
    int i = 0;

    while (map[i] != '\0') {
        if (map[i] == 'e')
            map[i] = '*';
        i++;
    }
    printf("%s", map);
    return (0);
}