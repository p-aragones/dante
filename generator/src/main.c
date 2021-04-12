/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main function
*/

#include "../include/cesar.h"

int main(int argc, char **argv)
{
    if (check_args(argc, argv) == 84)
        return (84);
    return (switch_flag(argv));
    
}
