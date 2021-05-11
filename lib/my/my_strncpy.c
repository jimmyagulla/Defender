/*
** EPITECH PROJECT, 2020
** my_strcpy.c
** File description:
** disply string's chacters
*/

int my_strlen(char const *str);

char *my_strncpy(char *dest, char *src, int n)
{
    int i = 0;

    while (n > 0) {
            dest[i] = src[i];
            if (src[i] == 0) {
                return (dest);
            }
            i++;
            n--;
    }
    if (n > my_strlen(src))
        dest[i] = '\0';
    return (dest);
}