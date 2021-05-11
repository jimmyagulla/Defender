/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** main of the project
*/

#include "defender.h"

int main(int ac, char **av)
{
    all_t all;

    if ((handle_args(ac, av)) == 1)
        return (0);
    if (handle_args(ac, av) == 84)
        return (84);
    main_loop(&all);
    return (0);
}