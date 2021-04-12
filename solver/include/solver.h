/*
** EPITECH PROJECT, 2021
** B-CPE-200-BAR-2-1-dante-pol.aragones
** File description:
** solver
*/

#ifndef SOLVER_H_
#define SOLVER_H_

#include "utils.h"

typedef struct list_s {
    char c;
    int walkable;
    int f;
    point_t *pos;
    struct list_s next;
} list_t;

typedef struct point_s {
    int x;
    int y;
} point_t;

char *read_file(char *);
int map_handling(char **);

int calculate_f(int, int, int, int);
void get_better_f(list_t *, list_t *, int *, list_t *);
int solver(char *);

point_t *create_point(int, int);
list_t *create_node(char, point_t *, point_t *);
list_t *add_start(list_t *, char, point_t *, point_t *);
list_t *add_end(list_t *, char, point_t *, point_t *);
list_t *add_node(list_t *, char, point_t *, point_t *);
list_t *delete_node(list_t *, int *);
int list_len(list_t *);

#endif /* !SOLVER_H_ */
