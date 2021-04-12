/*
** EPITECH PROJECT, 2021
** get_content.c
** File description:
** function to read a file
*/

#include "cesar.h"

char *get_content(char *filename)
{
    int fd = open(filename, O_RDONLY);
    int size = get_stat(filename);
    char *buffer = NULL;

    if (filename == NULL || fd == -1 || size == 0 || size == 84)
        return (NULL);
    buffer = malloc(sizeof(char) * (size + 1));
    if (buffer == NULL || read(fd, buffer, size) == -1
        || close(fd) == -1)
        return (NULL);
    buffer[size] = '\0';
    close(fd);
    return (buffer);
}
