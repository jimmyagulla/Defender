/*
** EPITECH PROJECT, 2020
** my_strcpy
** File description:
** copy string
*/

char *my_strcpy(char *dest, char const *src)
{
    int turn = 0;

    for (turn; src[turn] != 0; turn++)
        dest[turn] = src[turn];
    dest[turn] = '\0';
    return (dest);
}