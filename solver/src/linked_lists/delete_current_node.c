/*
** EPITECH PROJECT, 2021
** B-CPE-200-BAR-2-1-dante-pol.aragones
** File description:
** delete_current_node
*/

#include "solver.h"

list_t *delete_current_node(list_t *list, cell_t *node)
{
    list_t *temp = list;

    if (list->next == NULL)
        return (NULL);
    while (list && list->next) {
        if (list->cell->pos->x == node->pos->x &&
        list->cell->pos->y == node->pos->y && list->next->next != NULL) {
            list->next = list->next->next;
            list = temp;
            return (list);
        } else if (list->cell->pos->x == node->pos->x &&
        list->cell->pos->y == node->pos->y && list->next->next == NULL) {
            list->next = NULL;
            list = temp;
            return (list);
        }
        list = list->next;
    }
    list = temp;
    return (list);
}