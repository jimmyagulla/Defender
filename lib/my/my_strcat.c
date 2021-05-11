/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** concatenate two strings
*/

#include "my.h"

char *my_strcat(char *dest, const char *src)
{
    int i = 0;
    int n = 0;
    char *clone = dest;
    dest = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));

    for (i = 0; clone[i]; i++) {
        dest[i] = clone[i];
    }
    for (int s = 0; src[s] != '\0'; s++) {
        dest[i] = src[s];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}