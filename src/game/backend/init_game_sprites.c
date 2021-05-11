/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** handle_game_sprites
*/

#include "defender.h"

void create_game_sprites(all_t *all)
{
    char *maps;
    if (all->mapchooser->choice == 3)
        maps = "asset/game/maps/map_two.png";
    if (all->mapchooser->choice == 2)
        maps = "asset/game/maps/bricks_map.png";
    if (all->mapchooser->choice == 1)
        maps = "asset/game/maps/map_one.png";
    if (all->mapchooser->choice == 0)
        maps = "asset/game/maps/map_one.png";
    all->game[0].game_obj = malloc(sizeof(game_object_t) * 11);
    game_object_t map = {1920, 1080, {cross(0.89, all, 'w'),
    cross(1, all, 'h')}, 0,
    {cross(0, all, 'w'), cross(0, all, 'h')}, 0, 0, {0, 0, 1920, 1080},
    {0, {0}, 0}};
    init_game_object(&map, maps);
    all->game[0].game_obj[0] = map;
    all->game->clock_monsters = sfClock_create();
    all->game->seconds_ms = 0;
    create_ui_sprites(all);
}