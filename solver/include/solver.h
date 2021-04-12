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
    struct list_s next;
} list_t;

char *read_file(char *);
int map_handling(char **);

int solver(char *);

int list_len(list_t *);

#endif /* !SOLVER_H_ */
