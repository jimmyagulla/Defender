/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** print string
*/

#include <unistd.h>

void my_putchar(char c);

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != 0) {
        my_putchar(str[i]);
        i++;
    }
    return;
}