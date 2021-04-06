/*
** EPITECH PROJECT, 2021
** my_split
** File description:
** cut string by given chars as second string / Pol Aragones
*/

#include "utils.h"

char **my_split(char *str, char *cmp)
{
    char **result = malloc(sizeof(char *) * (w_count(str, cmp) + 1));
    int i_str = 0;
    int i_arr = 0;
    int i_arr_str = 0;

    if (result == NULL || str == NULL)
        return (NULL);
    while (i_arr < w_count(str, cmp)) {
        while (check_char(str[i_str], cmp) == 0)
            i_str++;
        result[i_arr] = my_malloc(word_length(str, i_str, cmp) + 1);
        while (check_char(str[i_str], cmp) == 1) {
            result[i_arr][i_arr_str++] = str[i_str];
            i_str++;
        }
        i_arr_str = 0;
        i_arr++;
    }
    result[i_arr] = NULL;
    return (result);
}