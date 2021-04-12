/*
** EPITECH PROJECT, 2021
** switch_flag.c
** File description:
** function to switch flag
*/

#include "cesar.h"

int check_flag(char *flag)
{
    if (strcmp(flag, "-f") == 0)
        return (1);
    else
        return (2);
}
