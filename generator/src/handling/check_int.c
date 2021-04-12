/*
** EPITECH PROJECT, 2021
** check_int.c
** File description:
** function to check if string is a number
*/

#include "cesar.h"

int is_int(char c)
{
    if (c >= '0' && c <= '9')
        return (0);
    else if (c == '-')
        return (0);
    return (84);
}

int check_int(char *number)
{
    int x = 0;

    while (number[x] != '\0') {
        if (is_int(number[x]) != 0)
            return (84);
        if (number[x] == '-' && x != 0)
            return (84);
        x++;
    }
    return (0);
}
