/*
** EPITECH PROJECT, 2020
** my_revstr.c
** File description:
** disply strings characters à l'envers
*/

char *my_revstr(char *str)
{
    char temp[] = "weshl:jnrtdfjgolifjdsoi";
    int i = 0;
    int n = 0;
    int m = 0;

    while (str[i] != 0)
        i++;
    i--;

    for (int i; i >= 0; i = i - 1) {
        temp[n] = str[i];
        n++;
    }
    temp[n] = '\0';
    for (int m = 0; temp[m] != 0; str[m] = temp[m])
        m = m + 1;
    str[m] = temp[m];
    return (str);
}