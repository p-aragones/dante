/*
** EPITECH PROJECT, 2021
** stumper2.h
** File description:
** stumper include file
*/

#ifndef CESAR_H_
#define CESAR_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int check_args(int argc, char **argv);
int generator(int x, int y);
int exp_map(char **maze, int x, int y);

#endif
