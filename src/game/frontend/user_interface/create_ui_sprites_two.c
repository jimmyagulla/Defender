/*
** EPITECH PROJECT, 2021
** defender
** File description:
** creates ui
*/

#include "defender.h"

void create_pause_sprites_two(all_t *all)
{
    game_object_t option = {0, 0, {cross(1, all, 'w'), cross(1, all, 'h')}, 0,
    {cross(400, all, 'w'), cross(495, all, 'h')}, 0, 0, {0, 0, 390, 88}, {0,
    {0}, 0}};
    init_game_object(&option, "./asset/game/settings/menu.png");
    all->game[1].game_obj[3] = option;
    game_object_t menu = {0, 0, {cross(1, all, 'w'), cross(1, all, 'h')}, 0,
    {cross(400, all, 'w'), cross(595, all, 'h')}, 0, 0, {0, 0, 390, 88}, {0,
    {0}, 0}};
    init_game_object(&menu, "./asset/game/settings/quit.png");
    all->game[1].game_obj[4] = menu;
}

void create_prices(all_t *all)
{
    all->game->tower_prices = sfText_create();

    sfText_setFont(all->game->tower_prices, sfFont_createFromFile
    ("./asset/letters/FFF_Tusj.ttf"));
    sfText_setCharacterSize(all->game->tower_prices, cross(45, all, 'w'));
    sfText_setString(all->game->tower_prices,
    " 70$\n\n\n 40$\n\n\n 60$\n\n120$");
    sfText_setColor(all->game->tower_prices, sfWhite);
    sfText_setPosition(all->game->tower_prices, (sfVector2f)
    {cross(1790, all, 'w'), cross(305, all, 'h')});
}