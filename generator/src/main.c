/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main function
*/

#include "generator.h"

int main(int argc, char **argv)
{
    int x = 0;

    if (check_args(argc, argv) == 84)
        return (84);
    if (argc == 4)
        x = 1;
    return (generator(atoi(argv[1]), atoi(argv[2]), x));
}