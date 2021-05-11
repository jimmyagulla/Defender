/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** Compare the ascii lenght of the strings
*/

#include <unistd.h>
#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int index = 0;
    int lenght = 0;

    if (my_strlen(s1) > my_strlen(s2))
        lenght = my_strlen(s1);
    lenght = my_strlen(s2);
    while (index < lenght && s1[index] == s2[index])
        index++;
    if ((s1[index] == 0 && s2[index] == 0))
        return (0);
    if (s1[index] > s2[index])
        return (s1[index] - s2[index]);
    if (s1[index] < s2[index])
        return (s2[index] - s1[index]);
    return (0);
}