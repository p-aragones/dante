/*
** EPITECH PROJECT, 2021
** check args
** File description:
** checker
*/

#include "generator.h"

int check_null(char **argv)
{
    if (strlen(argv[1]) == 1 && argv[1][0] == '0')
        return (84);
    if (strlen(argv[2]) == 1 && argv[2][0] == '0')
        return (84);
    if (atoi(argv[1]) == 1 || atoi(argv[2]) == 1)
        return (84);
    return (0);
}

int check_args(int argc, char **argv)
{
    int i = 0;

    if (argc != 3 && argc != 4)
        return (84);
    while (argv[1][i] != '\0') {
        if (argv[1][i] < '0' || argv[1][i] > '9')
            return (84);
        i++;
    }
    i = 0;
    while (argv[2][i] != '\0') {
        if (argv[2][i] < '0' || argv[2][i] > '9')
            return (84);
        i++;
    }
    return (check_null(argv));
}