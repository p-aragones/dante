/*
** EPITECH PROJECT, 2021
** solver
** File description:
** children
*/

#include "solver.h"

#include "stdio.h"

cell_t *append_children(int x, int y, cell_t *node, cell_t ***grid)
{
    cell_t *new_node = malloc(sizeof(cell_t));

    if (node->pos->x + x > node->end->x || node->pos->y + y > node->end->y ||
    node->pos->x + x < 0 || node->pos->y + y < 0)
        return (NULL);
    if (grid[node->pos->y + y][node->pos->x + x]->walkable == 0)
        return (NULL);
    new_node = grid[node->pos->y + y][node->pos->x + x];
    return (new_node);
}

int in_list(cell_t *child, list_t *list)
{
    list_t *temp = list;

    while (temp) {
        if (temp->cell->pos == child->pos)
            return (1);
        temp = temp->next;
    }
    return (0);
}

list_t *get_neighbours(cell_t *node, cell_t ***grid, list_t *closed_list)
{
    list_t *children = NULL;
    cell_t *new_child = NULL;

    new_child = append_children(UP, node, grid);
    if (new_child != NULL && in_list(new_child, closed_list) == 0)
        children = add_end(children, new_child, NULL);
    new_child = append_children(DOWN, node, grid);
    if (new_child != NULL && in_list(new_child, closed_list) == 0)
        children = add_end(children, new_child, NULL);
    new_child = append_children(LEFT, node, grid);
    if (new_child != NULL && in_list(new_child, closed_list) == 0)
        children = add_end(children, new_child, NULL);
    new_child = append_children(RIGHT, node, grid);
    if (new_child != NULL && in_list(new_child, closed_list) == 0)
        children = add_end(children, new_child, NULL);
    return (children);
}

list_t *get_children(list_t *open_list, list_t *closed_list,
cell_t *current_node, cell_t ***grid)
{
    list_t *children = get_neighbours(current_node, grid, closed_list);
    list_t *child = children;
    list_t *o = open_list;
    list_t *c = closed_list;
    int status = 0;

    child = skip_child(o, c, child, &status);
    while (child) {
        while (status != 0) {
            child = skip_child(o, c, child, &status);
        }
        printf("current node, x: %d y: %d\n", current_node->pos->x, current_node->pos->y);
        printf("child cell: x: %d y: %d\n", child->cell->pos->x, child->cell->pos->y);
        open_list = add_end(open_list, child->cell, current_node);
        return (open_list);
    }
}