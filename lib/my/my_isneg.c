/*
** EPITECH PROJECT, 2020
** MY_PRINT_ALPHA
** File description:
** print alphabet minuscule ordre croissant en une ligne
*/

void my_putchar(char c);

int  my_isneg(int n)
{
    if (n < 0) {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
}