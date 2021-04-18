/*
** EPITECH PROJECT, 2021
** B-CPE-200-BAR-2-1-dante-pol.aragones
** File description:
** print_array
*/

#include "utils.h"

void print_array(char **array)
{
    int i = 0;

    while (array[i]) {
        my_putstr(array[i]);
        if (array[i + 1])
            my_putchar('\n');
        i++;
    }
}