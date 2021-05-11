/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** create_settings_sprites
*/

#include "defender.h"

void create_settings_sprites_two(all_t *all)
{
    game_object_t slider_three = {0, 0, {cross(1, all, 'w'), cross(1, all, 'h')
    }, 0, {cross(all->menu->fps_posx, all, 'w'),
    cross(589, all, 'h')}, 0, 0, {0, 0, 24, 49}, {
    0, {0}, 0}};
    game_object_t resume = {0, 0, {cross(0.7, all, 'w'), cross(0.7, all, 'h')},
    0, {cross(155, all, 'w'), cross(120, all, 'h')}, 0, 0, {0, 0, 390, 88}, {0,
    {0}, 0}};
    init_game_object(&slider_three, "asset/menu/buttons/slider.png");
    init_game_object(&resume, "asset/menu/buttons/back.png");
    all->menu[1].settings[3] = slider_three;
    all->menu[1].settings[4] = resume;
}

void create_settings_sprites(all_t *all)
{
    all->menu[1].settings = malloc(sizeof(game_object_t) * 8);
    game_object_t background = {0, 0, {cross(1, all, 'w'), cross(1, all, 'h')},
    0, {cross(0, all, 'w'), cross(0, all, 'h')}, 0, 0, {0, 0, 1920, 1080}, {0,
    {0}, 0}};
    game_object_t slider_one = {0, 0, {cross(1, all, 'w'), cross(1, all, 'h')},
    0, {cross(all->menu->sfx_posx, all, 'w'),
    cross(280, all, 'h')}, 0, 0, {0, 0, 24, 49}, {0, {0}, 0}};
    game_object_t slider_two = {0, 0, {cross(1, all, 'w'), cross(1, all, 'h')},
    0, {cross(all->menu->music_posx, all, 'w'),
    cross(433, all, 'h')}, 0, 0, {0, 0, 24, 49}, {0, {0}, 0}};
    if (all->pre_status == game) {
        init_game_object(&background, "asset/menu/buttons/game_option.png");
    } else
        init_game_object(&background, "asset/menu/buttons/option.png");
    init_game_object(&slider_one, "asset/menu/buttons/slider.png");
    init_game_object(&slider_two, "asset/menu/buttons/slider.png");
    all->menu[1].settings[0] = background;
    all->menu[1].settings[1] = slider_one;
    all->menu[1].settings[2] = slider_two;
    create_settings_sprites_two(all);
}