/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** handling windows
*/

#include "defender.h"

void init_game(all_t *all)
{
    init_var(all);
    create_cursor(all);
    fps_display(all);
    all->menu->menu_sound = sfMusic_createFromFile
    ("./asset/menu/sounds/party-time-bloons-td-6.ogg");
    all->click_sound = sfMusic_createFromFile
    ("./asset/menu/sounds/buttonclick.ogg");
    sfMusic_setVolume(all->menu->menu_sound, 14);
    sfMusic_setLoop(all->menu->menu_sound, sfTrue);
    sfMusic_play(all->menu->menu_sound);
}

int all_status(all_t *all)
{
    if (all->status == game_over)
        gameover_loop(all);
    if (all->status == menu) {
        menu_loop(all);
        destroy_menu_assets(all);
    }
    if (all->status == option) {
        option_loop(all);
        destroy_options_assets(all);
    }
    if (all->status == game) {
        game_loop(all);
    }
    if (all->status == quit_game) {
        sfMusic_destroy(all->menu->menu_sound);
        sfMusic_destroy(all->click_sound);
        return (-1);
    }
    return (0);
}

void main_loop(all_t *all)
{
    init_game(all);
    while (sfRenderWindow_isOpen(all->window)) {
        if (all_status(all) == -1)
            return;
    }
    sfRenderWindow_destroy(all->window);
    sfMusic_destroy(all->menu->menu_sound);
    sfMusic_destroy(all->click_sound);
}