/*
** EPITECH PROJECT, 2021
** switch_flag.c
** File description:
** switch flag for the main
*/

#include "cesar.h"

int switch_flag(char **argv)
{
    if (check_flag(argv[1]) == 1) {
        if (get_content(argv[2]) == NULL)
            return (84);
        return (cesar(get_content(argv[2]), atoi(argv[3])));
    } else
        return (cesar(argv[2], atoi(argv[3])));
}
