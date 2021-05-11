/*
** EPITECH PROJECT, 2020
** my_strncat
** File description:
** concatenate two strings
*/

char *my_strncat(char *dest, const char *src, int nb)
{
    int i = 0;
    int n = 0;

    while (dest[n] != 0)
        n++;
    while (i < nb && src[i] != '\0') {
        dest[n] = src[i];
        i++;
        n++;
    }
    dest[n + i] = '\0';
    return (dest);
}