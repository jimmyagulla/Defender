/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-diogo.faria-martins
** File description:
** create_mapchooser_sprites
*/

#include "defender.h"

void create_map_sprites(all_t *all)
{
    game_object_t mapone = {0, 0, {cross(0.2, all, 'w'), cross(0.2, all, 'h')
    }, 0, {cross(256, all, 'w'), cross(530, all, 'h')}, 0, 0, {0, 0, 1920,
    1080}, {0, {0}, 0}};
    init_game_object(&mapone, "asset/game/maps/map_one.png");
    all->mapchooser[0].game_obj[1] = mapone;
    game_object_t maptwo = {0, 0, {cross(0.2, all, 'w'), cross(0.2, all, 'h')
    }, 0, {cross(768, all, 'w'), cross(530, all, 'h')}, 0, 0, {0, 0, 1920,
    1080}, {0, {0}, 0}};
    init_game_object(&maptwo, "asset/game/maps/bricks_map.png");
    all->mapchooser[0].game_obj[2] = maptwo;
    game_object_t mapthree = {0, 0, {cross(0.2, all, 'w'), cross(0.2, all, 'h')
    }, 0, {cross(1280, all, 'w'), cross(530, all, 'h')}, 0, 0, {0, 0, 1920,
    1080}, {0, {0}, 0}};
    init_game_object(&mapthree, "asset/game/maps/map_two.png");
    all->mapchooser[0].game_obj[3] = mapthree;
}

void create_mapchooser_sprites_two(all_t *all)
{
    game_object_t defl = {0, 0, {cross(0.2, all, 'w'), cross(0.2, all, 'h')
    }, 0, {cross(860, all, 'w'), cross(730, all, 'h')}, 0, 0,
    {0, 0, 406, 345}, {0, {0}, 0}};
    init_game_object(&defl, "asset/game/arrow.png");
    all->mapchooser[0].game_obj[5] = defl;
    game_object_t defr = {0, 0, {cross(0.2, all, 'w'), cross(0.2,
    all, 'h')}, 0, {cross(950, all, 'w'), cross(730, all, 'h')},
    0, 0, {406, 0, 536, 345}, {0, {0}, 0}};
    init_game_object(&defr, "asset/game/arrow.png");
    all->mapchooser[0].game_obj[6] = defr;
}

void create_mapchooser_sprites(all_t *all)
{
    all->mapchooser[0].game_obj = malloc(sizeof(game_object_t) * 7);
    game_object_t nickname = {0, 0, {cross(1, all, 'w'), cross(1, all, 'h')
    }, 0, {cross(0, all, 'w'), cross(0, all, 'h')}, 0, 0, {0, 0, 1920,
    1080}, {0, {0}, 0}};
    init_game_object(&nickname, "asset/game/enternickname.png");
    all->mapchooser[0].game_obj[0] = nickname;
    create_map_sprites(all);
    game_object_t interface = {0, 0, {cross(1, all, 'w'), cross(1, all, 'h')
    }, 0, {cross(0, all, 'w'), cross(0, all, 'h')}, 0, 0, {0, 0, 1920, 1080},
    {0, {0}, 0}};
    init_game_object(&interface, "asset/game/selectmap_screenbg.png");
    all->mapchooser[0].game_obj[4] = interface;
    create_mapchooser_sprites_two(all);
}