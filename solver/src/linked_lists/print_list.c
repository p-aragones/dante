/*
** EPITECH PROJECT, 2021
** B-CPE-200-BAR-2-1-dante-pol.aragones
** File description:
** print_list
*/

#include "solver.h"

void print_list(list_t *list)
{
    list_t *temp = list;
    int pos = 0;

    printf("-----list-----\n");
    while (temp) {
        printf("%d: x:%d y:%d f:%d\n", pos, temp->cell->pos->x,
        temp->cell->pos->y, temp->cell->f);
        temp = temp->next;
        pos++;
    }
}