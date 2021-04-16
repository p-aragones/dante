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
    list_t *prev = NULL;

    if (list->next == NULL)
        return (NULL);
    while (temp) {
        if (temp->cell->pos->x == node->pos->x &&
        temp->cell->pos->y == node->pos->y) {
            if (!prev)
                return (temp->next);
            prev->next = temp->next;
            return (list);
        }
        if (!temp->next)
            return (list);
        prev = temp;
        temp = temp->next;
    }
    return (list);
}