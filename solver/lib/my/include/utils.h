/*
** EPITECH PROJECT, 2020
** utils
** File description:
** header file
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int compare_strings(char const *, char const *, int);
int my_count_two(char const *);
int count_long_string(char *, int);

void my_putchar(char);
int my_putstr(char *);
int my_put_nbr(int);

char *my_strdup(char *);
int my_strlen(char *);
int my_strcmp(char const *, char const *);

char *my_strcat(char *, char *);

int my_str_isalpha(char *);
int my_str_isnum(char *);

int my_getnbr(char const *);

char *my_malloc(int);

int check_char(char, char *);
int w_count(char *, char *);
int word_length(char *, int, char *);

char **my_split(char *, char *);
#endif
