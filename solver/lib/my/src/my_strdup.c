/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** create space in memory and put a string there / Pol Aragones
*/

#include <stdlib.h>
#include "utils.h"

char *my_strdup(char *src)
{
    char *dest = NULL;
    int i = 0;

    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (dest == NULL) {
        return (NULL);
    }
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
