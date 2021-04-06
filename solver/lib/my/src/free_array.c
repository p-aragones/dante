/*
** EPITECH PROJECT, 2021
** B-CPE-200-BAR-2-1-dante-pol.aragones
** File description:
** free_array
*/

#include "utils.h"

void free_array(char **array)
{
    int i = 0;

    while (array[i]) {
        free (array[i]);
        i++;
    }
    free (array);
}