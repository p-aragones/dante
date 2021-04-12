/*
** EPITECH PROJECT, 2021
** cesar.c
** File description:
** cesar algorythm
*/

#include "cesar.h"

char loop_min(char mes)
{
    mes = mes - 1;
    if (mes == -1)
        mes = 25;
    return (mes);
}

char loop_more(char mes)
{
    mes = mes + 1;
    if (mes == 26)
        mes = 0;
    return (mes);
}

char get_new(char mes, int num)
{
    int i = num;

    while (i != 0) {
        if (num < 0) {
            mes = loop_min(mes);
            i++;
        } else {
            mes = loop_more(mes);
            i--;
        }
    }
    return (mes);
}

char *convert(char *mes, int num)
{
    int i = 0;

    while (mes[i] != '\0') {
        if (mes[i] > 64 && mes[i] < 91)
            mes[i] = get_new(mes[i] - 65, num) + 65;
        if (mes[i] > 96 && mes[i] < 123)
            mes[i] = get_new(mes[i] - 97, num) + 97;
        i++;
    }
    return (mes);
}

int cesar(char *mes, int num)
{
    int fd = open("crypt", O_CREAT | O_WRONLY, 00444);
    size_t bit = 0;

    if (fd == -1)
        return (84);
    mes = convert(mes, num);
    bit = strlen(mes);
    write(fd, mes, bit);
    return (0);
}
