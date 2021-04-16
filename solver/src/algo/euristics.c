/*
** EPITECH PROJECT, 2021
** B-CPE-200-BAR-2-1-dante-pol.aragones
** File description:
** euristics
*/

#include <math.h>
#include <stdlib.h>

int calculate_g(int x, int y)
{
    return (x + y);
}

int calculate_h(int x, int y, int x_end, int y_end)
{
    return (abs(x_end - x + y_end - y));
}

int calculate_f(int x, int y, int x_end, int y_end)
{
    return (calculate_g(x, y) + calculate_h(x, y, x_end, y_end));
}