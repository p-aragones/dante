/*
** EPITECH PROJECT, 2021
** B-CPE-200-BAR-2-1-dante-pol.aragones
** File description:
** get_better_f
*/

#include "solver.h"

list_t *get_better_f(list_t *current_node, list_t *open_list)
{
    list_t *temp = open_list;
    int i = 0;

    while (temp) {
        if (temp->cell->f < current_node->cell->f)
            current_node = temp;
        temp = temp->next;
        i++;
    }
    open_list = delete_node(open_list, i);
    return (open_list);
}