/*
** EPITECH PROJECT, 2021
** linked_functions
** File description:
** linked_functions
*/

#include "solver.h"

list_t *delete_node(list_t *list, int index)
{
    list_t *temp = list;
    int i = 0;

    while (temp->next != NULL) {
        if (i + 1 == index) {
            temp->next = temp->next->next;
            return (list);
        }
        temp = temp->next;
        i++;
    }
    return (list);
}

list_t *create_node(cell_t *cell)
{
    list_t *node = malloc(sizeof(list_t));

    if (node == NULL)
        return (NULL);
    node->cell = malloc(sizeof(cell_t));
    node->cell->pos = create_point(0, 0);
    node->cell->c = cell->c;
    node->cell->end = cell->end;
    node->cell->g = cell->g;
    node->cell->pos->x = cell->pos->x;
    node->cell->pos->y = cell->pos->y;
    node->cell->walkable = cell->walkable;
    node->cell->f = cell->f;
    node->cell->parent = cell->parent;
    node->next = NULL;
    return (node);
}

list_t *add_start(list_t *head, cell_t *cell)
{
    list_t *list = create_node(cell);

    if (list == NULL)
        return (NULL);
    list->cell->parent = NULL;
    list->next = head;
    return (list);
}

list_t *add_end(list_t *head, cell_t *cell, cell_t *parent)
{
    list_t *list = create_node(cell);
    list_t *temp = head;

    if (list == NULL)
        return (NULL);
    if (head == NULL)
        return (list);
    list->cell->parent = parent;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = list;
    return (head);
}

list_t *add_node(list_t *head, cell_t *cell)
{
    list_t *temp = head;

    head = create_node(cell);
    if (head == NULL)
        return (NULL);
    if (head == NULL)
        return (head);
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head;
}