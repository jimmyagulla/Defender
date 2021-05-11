/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-diogo.faria-martins
** File description:
** create_gameover_sprites
*/

#include "defender.h"

void create_gameover_sound(all_t *all)
{
    all->gameover->gameover_sound =
    sfMusic_createFromFile("asset/menu/sounds/gameover_sound.ogg");
    sfMusic_setVolume(all->gameover->gameover_sound, all->menu->mus_vol + 50);
    sfMusic_play(all->gameover->gameover_sound);
}

void create_gameover_sprites(all_t *all)
{
    all->gameover[0].game_obj = malloc(sizeof(game_object_t) * 5);
    game_object_t gameover = {0, 0, {cross(0.7, all, 'w'), cross(0.7, all, 'h')
    }, 0, {cross(560, all, 'w'), cross(200, all, 'h')}, 0, 0, {0, 0, 836,
    1042}, {0, {0}, 0}};
    init_game_object(&gameover, "asset/game/gameover_board.png");
    all->gameover[0].game_obj[0] = gameover;
    game_object_t restart_button = {0, 0, {cross(1.2, all, 'w'), cross(1.2,
    all, 'h')}, 0, {cross(725, all, 'w'), cross(565, all, 'h')}, 0, 0, {0,
    0, 1920, 1080}, {0, {0}, 0}};
    init_game_object(&restart_button, "asset/game/restart.png");
    all->gameover[0].game_obj[1] = restart_button;
    game_object_t menu_button = {0, 0, {cross(1.2, all, 'w'), cross(1.2, all,
    'h')}, 0, {cross(725, all, 'w'), cross(665, all, 'h')}, 0, 0, {0, 0, 1920,
    1080}, {0, {0}, 0}};
    init_game_object(&menu_button, "asset/game/settings/menu.png");
    all->gameover[0].game_obj[2] = menu_button;
    create_gameover_sound(all);
}