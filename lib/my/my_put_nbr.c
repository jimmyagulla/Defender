/*
** EPITECH PROJECT, 2020
** Day03Task07
** File description:
** displays the number given as a parameter
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        my_putchar('-');
        my_putchar('2');
        nb = nb + 2000000000;
        nb = -1 * nb;
    }
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    else
        my_putchar(nb + 48);
    return (0);
}