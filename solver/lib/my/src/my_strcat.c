/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** put two strings together / Pol Aragones
*/

#include "utils.h"

char *my_strcat(char *dest, char *src)
{
    int i = my_strlen(dest);
    int j = 0;

    while (src[j] != '\0') {
        dest[i + j] = src[j];
        j++;
    }
    dest[i + j] = '\0';
    return (dest);
}
