/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** lenght of string / Pol Aragones
*/

int my_strlen(char *str)
{
    int counter = 0;

    if (str == 0)
        return (84);
    while (str[counter] != '\0')
        counter++;
    return (counter);
}
