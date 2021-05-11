/*
** EPITECH PROJECT, 2020
** my_strncmp
** File description:
** ouai la rue la vraie
*/

#include <unistd.h>

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] != 0 && s2[i] != 0 && n != 0) {
        i++;
        n--;
    }
    if (s1[i] - s2[i] > 0)
        write (1, "1", 1);
    if (s1[i] - s2[i] < 0)
        write (1, "-1", 2);
    if (s1[i] - s2[i] == 0)
        write (1, "0", 1);
    return (0);
}