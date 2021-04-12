/*
** EPITECH PROJECT, 2021
** linked_functions
** File description:
** linked_functions
*/

#include "solver.h"

list_t *delete_node(list_t *list, int *index)
{
    list_t *temp = list;
    int i = 0;

    while (temp->next != NULL) {
        if (i + 1 == *index) {
            temp->next = temp->next->next;
            return (list);
        }
        temp = temp->next;
        i++;
    }
    return (list);
}

list_t *create_node(char c, point_t *end, point_t *pos)
{
    list_t *node = malloc(sizeof(list_t));

    if (node == NULL)
        return (NULL);
    if (c != 'X')
        node->walkable = 1;
    node->c = c;
    node->f = calculate_f(pos->x, pos->y, end->x, end->y);
    node->pos = create_point(pos->x, pos->y);
    node->next = NULL;
    return (node);
}

list_t *add_start(list_t *head, char c, point_t *end, point_t *pos)
{
    list_t *list = create_node(c, end, pos);

    if (list == NULL)
        return (NULL);
    list->next = head;
    return (list);
}

list_t *add_end(list_t *head, char c, point_t *end, point_t *pos)
{
    list_t *list = create_node(c, end, pos);
    list_t *temp = head;

    if (list == NULL)
        return (NULL);
    if (head == NULL)
        return (list);
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = list;
    return (head);
}

list_t *add_node(list_t *head, char c, point_t *end, point_t *pos)
{
    list_t *temp = head;

    head = create_node(c, end, pos);
    if (head == NULL)
        return (NULL);
    if (head == NULL)
        return (head);
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head;
}