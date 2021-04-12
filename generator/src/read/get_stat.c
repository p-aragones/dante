/*
** EPITECH PROJECT, 2021
** get_stat.c
** File description:
** get the amount of bits in a file
*/

#include "cesar.h"

int get_stat(char *filename)
{
    struct stat sb;

    if (stat(filename, &sb) == -1) {
        return (84);
    }
    return (sb.st_size);
}
