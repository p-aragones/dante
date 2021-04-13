/*
** EPITECH PROJECT, 2021
** B-CPE-200-BAR-2-1-dante-pol.aragones
** File description:
** solver
*/

#ifndef SOLVER_H_
#define SOLVER_H_

#include "utils.h"

// [x, y]
#define UP 0, 1
#define DOWN 0, -1
#define LEFT -1, 0
#define RIGHT 1, 0

typedef struct point_s {
    int x;
    int y;
} point_t;

typedef struct cell_s {
    char c;
    int walkable;
    int f;
    int g;
    point_t *pos;
    point_t *end;
    struct cell_s *parent;
} cell_t;

typedef struct list_s {
    cell_t *cell;
    struct list_s *next;
} list_t;

char *read_file(char *);
int map_handling(char **);
cell_t ***cell_map(char **, point_t *);
point_t *find_end(char **);

int calculate_f(int, int, int, int);
int calculate_g(int, int);
void get_better_f(list_t *, list_t *);
void get_children(list_t *, list_t *, cell_t *, cell_t ***);
char **a_star(char **, cell_t ***, point_t *);
int solver(char *);

point_t *create_point(int, int);
list_t *create_node(cell_t *);
list_t *add_start(list_t *, cell_t *);
list_t *add_end(list_t *, cell_t *, cell_t *);
list_t *add_node(list_t *, cell_t *);
list_t *delete_node(list_t *, int);
int list_len(list_t *);

#endif /* !SOLVER_H_ */
