/*
** EPITECH PROJECT, 2021
** check_args.c
** File description:
** function to check the arguments
*/

#include "cesar.h"

int check_args(int argc, char **argv)
{
    if (argc != 4 || check_int(argv[3]) == 84)
        return (84);
    else if ((strcmp(argv[1], "-f") != 0 && strcmp(argv[1], "-s") != 0))
        return (84);
    return (0);
}
