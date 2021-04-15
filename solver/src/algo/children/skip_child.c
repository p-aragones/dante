/*
** EPITECH PROJECT, 2021
** B-CPE-200-BAR-2-1-dante-pol.aragones
** File description:
** skip_child
*/

#include "solver.h"

list_t *skip_child(list_t *open_list, list_t *closed_list, list_t *children,
int *status)
{
    if (children && in_list(children->cell, closed_list) == 1) {
        children = children->next;
        *status = -1;
        return (children);
    }
    if (children->cell->walkable == 0) {
        children = children->next;
        *status = -1;
        return (children);
    }
    if (children && in_list(children->cell, open_list) == 1) {
        if (children->cell->f > open_list->cell->f) {
            children = children->next;
            *status = -1;
            return (children);
        }
    }
    *status = 0;
    return (children);
}