/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-diogo.faria-martins
** File description:
** create_ui_sprites
*/

#include "defender.h"

void create_pause_sprites_one(all_t *all)
{
    all->game[1].game_obj = malloc(sizeof(game_object_t) * 10);
    game_object_t board = {0, 0, {cross(2.6, all, 'w'), cross(3, all, 'h')},
    0, {cross(610, all, 'w'), cross(235, all, 'h')}, 0, 0, {0, 0, 200, 220}, {0
    , {0}, 0}};
    init_game_object(&board, "./asset/game/settings/settings_board.png");
    all->game[1].game_obj[0] = board;
    game_object_t resume = {0, 0, {cross(1, all, 'w'), cross(1, all, 'h')}, 0,
    {cross(400, all, 'w'), cross(475, all, 'h')}, 0, 0, {0, 0, 390, 88}, {0,
    {0}, 0}};
    init_game_object(&resume, "./asset/game/settings/resume.png");
    all->game[1].game_obj[1] = resume;
    game_object_t quit = {0, 0, {cross(1, all, 'w'), cross(1, all, 'h')}, 0,
    {cross(400, all, 'w'), cross(395, all, 'h')}, 0, 0, {0, 0, 390, 88}, {0,
    {0}, 0}};
    init_game_object(&quit, "./asset/game/settings/options.png");
    all->game[1].game_obj[2] = quit;
    create_pause_sprites_two(all);
}

void create_ui_sprites_two(all_t *all)
{
    game_object_t start_button = {0, 0, {cross(0.25, all, 'w'), cross(0.3, all,
    'h')}, 0, {cross(1700, all, 'w'), cross(965, all, 'h')}, 0, 0, {0, 0, 787,
    241}, {0, {0}, 0}};
    init_game_object(&start_button, "asset/game/play_ingame.png");
    all->game[0].game_obj[3] = start_button;

    game_object_t speed_button = {0, 0, {cross(0.65, all, 'w'), cross(0.8, all,
    'h')}, 0, {cross(1700, all, 'w'), cross(862, all, 'h')}, 0, 0, {0, 0, 787,
    241}, {0, {0}, 0}};
    init_game_object(&speed_button, "asset/game/accelerate_button.png");
    all->game[0].game_obj[4] = speed_button;
}

void create_ui_towers(all_t *all)
{
    game_object_t red_tower = {122, 0, {cross(0.6, all, 'w'), cross(0.6, all,
    'h')}, 0, {cross(1690, all, 'w'), cross(310, all, 'h')}, 0, 0, {57, 88,
    130, 158}, {0, {0}, 0}};
    init_game_object(&red_tower, "asset/game/redtower(1).png");
    all->game[0].game_obj[2] = red_tower;
    game_object_t archer_tower = {122, 0, {cross(0.6, all, 'w'), cross(0.6, all,
    'h')}, 0, {cross(1690, all, 'w'), cross(440, all, 'h')}, 0, 0, {88, 129,
    141, 180}, {0, {0}, 0}};
    init_game_object(&archer_tower, "asset/game/archer.png");
    all->game[0].game_obj[5] = archer_tower;
    game_object_t slow_tower = {0, 0, {cross(0.78, all, 'w'), cross(0.78, all,
    'h')}, 0, {cross(1690, all, 'w'), cross(570, all, 'h')}, 0, 0, {0, 40,
    98, 133}, {0, {0}, 0}};
    init_game_object(&slow_tower, "asset/game/ice.png");
    all->game[0].game_obj[6] = slow_tower;
    game_object_t canon_tower = {122, 0, {cross(1, all, 'w'), cross(1, all,
    'h')}, 0, {cross(1690, all, 'w'), cross(690, all, 'h')}, 0, 0, {0, 30,
    85, 91}, {0, {0}, 0}};
    init_game_object(&canon_tower, "asset/game/canon.png");
    all->game[0].game_obj[7] = canon_tower;
}

void create_ui_upgrades(all_t *all)
{
    game_object_t level_one = {122, 0, {cross(1, all, 'w'), cross(1, all,
    'h')}, 0, {cross(1380, all, 'w'), cross(0, all, 'h')}, 0, 0, {575, 139,
    280, 467}, {0, {0}, 0}};
    init_game_object(&level_one, "asset/game/upgrd_level_one.png");
    all->game[0].game_obj[8] = level_one;
    game_object_t level_two = {122, 0, {cross(1, all, 'w'), cross(1, all,
    'h')}, 0, {cross(1380, all, 'w'), cross(0, all, 'h')}, 0, 0, {575, 139,
    280, 467}, {0, {0}, 0}};
    init_game_object(&level_two, "asset/game/ugrd_level_two.png");
    all->game[0].game_obj[9] = level_two;
    game_object_t level_three = {122, 0, {cross(1, all, 'w'), cross(1, all,
    'h')}, 0, {cross(1380, all, 'w'), cross(0, all, 'h')}, 0, 0, {575, 139,
    280, 467}, {0, {0}, 0}};
    init_game_object(&level_three, "asset/game/board_three.png");
    all->game[0].game_obj[10] = level_three;
}

void create_ui_sprites(all_t *all)
{
    game_object_t vertical_bar = {0, 0, {cross(1, all, 'w'), cross(1, all,
    'h')}, 0, {cross(1670, all, 'w'), cross(0, all, 'h')}, 0, 0, {0, 0, 250,
    1080}, {0, {0}, 0}};
    init_game_object(&vertical_bar, "asset/game/vertical.png");
    all->game[0].game_obj[1] = vertical_bar;
    create_ui_upgrades(all);
    create_ui_towers(all);
    create_ui_sprites_two(all);
    create_pause_sprites_one(all);
    create_prices(all);
}