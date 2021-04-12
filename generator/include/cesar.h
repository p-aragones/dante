/*
** EPITECH PROJECT, 2021
** stumper2.h
** File description:
** stumper include file
*/

#ifndef CESAR_H_
#define CESAR_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *get_content(char *);
int get_stat(char *);
int cesar(char *, int);

int check_int(char *);
int check_args(int, char **);

int switch_flag(char **);
int check_flag(char *);

#endif
