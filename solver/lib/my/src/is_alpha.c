/*
** EPITECH PROJECT, 2020
** is_alpha
** File description:
** check if char is a letter / Pol Aragones
*/

int is_alpha(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return (1);
    else
        return (0);
}
