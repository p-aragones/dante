/*
** EPITECH PROJECT, 2021
** split functions
** File description:
** functions to support my_split / Pol Aragones
*/

#include "utils.h"

int check_char(char c, char *chars)
{
    int i = 0;

    while (chars[i] != '\0') {
        if (c == chars[i] || c == '\0')
            return (0);
        i++;
    }
    return (1);
}

int w_count(char *str, char *cmp)
{
    int i = 0;
    int w = 0;

    if (str == NULL)
        return (-1);
    while (str[i] != '\0') {
        if (check_char(str[i], cmp) == 1 && check_char(str[i + 1], cmp) == 0)
            w++;
        i++;
    }
    return (w);
}

int word_length(char *str, int i, char *compare)
{
    int length = 0;

    while (check_char(str[i], compare) == 1) {
        i++;
        length++;
    }
    return (length);
}