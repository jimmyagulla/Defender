/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** handle_args
*/

#include "defender.h"

void h_tuto(int ac, char **av)
{
    (void) ac;
    (void) av;
    my_putstr("Hello everyone, this is a tower defense game.\n\n");
    my_putstr("There is an in-game tutorial if you don't know how to\
play.\n\n");
    my_putstr("After writing your nickname, press Enter to validate.\n");
    my_putstr("To score your best score, you have to enter a nickname.\n");
    my_putstr("In the map selection screen, select your difficulty, your map");
    my_putstr(" and then press Enter to start playing.\n\n");
    my_putstr("Keybind to know :\n- Show fps : A\n");
    my_putstr("- Speed increase/decrease in-game : Space\n");
    my_putstr("- Show menu board : Escape\n\n");
    my_putstr("Have fun!\n\nCreators : Jimmy and Diogo\n");
}

int handle_args(int argc, char **argv)
{
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        h_tuto(argc, argv);
        return (1);
    }
    if (argc != 1)
        return (84);
    return (0);
}