/*
** EPITECH PROJECT, 2021
** B-CPE-200-BAR-2-1-dante-pol.aragones
** File description:
** list_len
*/

#include "solver.h"

int list_len(list_t *list)
{
    list_t *temp = list;
    int i = 0;

    while (temp) {
        temp = temp->next;
        i++;
    }
    return (i);
}