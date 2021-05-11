/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-diogo.faria-martins
** File description:
** destroy_assets
*/

#include "defender.h"

void create_tutorial_sprites(all_t *all)
{
    game_object_t tutorial = {0, 0, {cross(0.5, all, 'w'),
    cross(0.5, all, 'h')}, 0, {cross(1820, all, 'w'), cross(980, all, 'h')
    }, 0, 0, {0, 0, 140, 140}, {0, {0}, 0}};
    init_game_object(&tutorial, "asset/menu/buttons/tuto.png");
    all->menu[0].settings[10] = tutorial;
    game_object_t tutorbackground = {0, 0, {cross(1, all, 'w'),
    cross(1, all, 'h')}, 0, {cross(0, all, 'w'), cross(0, all, 'h')
    }, 0, 0, {0, 0, 1920, 1080}, {0, {0}, 0}};
    init_game_object(&tutorbackground, "asset/menu/backgrounds/tutorial.png");
    all->menu[0].settings[11] = tutorbackground;
}

void destroy_menu_assets(all_t *all)
{
    (void) all;
    return;
}

void destroy_options_assets(all_t *all)
{
    for (int i = 0; i <=  4; i++) {
        sfSprite_destroy(all->menu[1].settings[i].sprite);
        sfTexture_destroy(all->menu[1].settings[i].texture);
        sfClock_destroy(all->menu[1].settings[i].clock.clock);
    }
}