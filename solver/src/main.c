/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** remake of tcsh
*/

#include "solver.h"

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    return (solver(av[1]));
}