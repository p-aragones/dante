/*
** EPITECH PROJECT, 2021
** B-CPE-200-BAR-2-1-dante-pol.aragones
** File description:
** lower_f
*/

#include "solver.h"

cell_t *lower_f(list_t *open_list)
{
    list_t *list = open_list;
    cell_t *lower = list->cell;

    list = list->next;
    while (list) {
        if (list->cell->f < lower->f)
            lower = list->cell;
        //printf("lower: x:%d y:%d\n", list->cell->pos->x, list->cell->pos->y);
        list = list->next;
    }
    return (lower);
}