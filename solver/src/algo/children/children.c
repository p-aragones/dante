/*
** EPITECH PROJECT, 2021
** solver
** File description:
** children
*/

#include "solver.h"

cell_t *append_children(int x, int y, cell_t *node, cell_t ***grid)
{
    cell_t *new_node = NULL;

    if (node->pos->x + x > node->end->x || node->pos->y + y > node->end->y ||
    node->pos->x + x > 0 || node->pos->y + y > 0)
        return (NULL);
    if (grid[node->pos->y + y][node->pos->x + x]->walkable == 0)
        return (NULL);
    new_node = grid[node->pos->y + y][node->pos->x + x];
    return (new_node);
}

int not_closed(cell_t *child, list_t *closed_list)
{
    list_t *temp = closed_list;

    while (temp) {
        if (temp->cell->pos == child->pos)
            return (0);
        temp = temp->next;
    }
    return (1);
}

list_t *get_neighbours(cell_t *node, cell_t ***grid, list_t *closed_list)
{
    list_t *children = NULL;
    cell_t *new_child = NULL;

    new_child = append_children(UP, node, grid);
    if (new_child != NULL && not_closed(new_child, closed_list) == 1)
        add_end(children, new_child, children->cell->parent);
    new_child = append_children(DOWN, node, grid);
    if (new_child != NULL && not_closed(new_child, closed_list) == 1)
        add_end(children, new_child, children->cell->parent);
    new_child = append_children(LEFT, node, grid);
    if (new_child != NULL && not_closed(new_child, closed_list) == 1)
        add_end(children, new_child, children->cell->parent);
    new_child = append_children(RIGHT, node, grid);
    if (new_child != NULL && not_closed(new_child, closed_list) == 1)
        add_end(children, new_child, children->cell->parent);
    return (children);
}

void get_children(list_t *open_list, list_t *closed_list,
cell_t *current_node, cell_t ***grid)
{
    list_t *children = get_neighbours(current_node, grid, closed_list);
    list_t *child = children;
    list_t *l = open_list;

    while (child) {
        while (child && not_closed(child->cell, closed_list) == 0)
            child = child->next;
        while (l) {
            while (child->cell == l->cell && child->cell->g > l->cell->g)
                l = l->next;
        }
        add_end(open_list, child->cell, child->cell->parent);
    }
}