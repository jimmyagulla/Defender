/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** init_waves
*/

#include "defender.h"

void diff_spawns(all_t *all, int i)
{
    if (all->game->map_buff[0] == 'A') {
        all->game[2].mobs[i].pos.x += i;
        all->game[2].mobs[i].karim = LEFT;
        return;
    }
    if (all->game->map_buff[0] == 'B') {
        all->game[2].mobs[i].pos.y -= i;
        all->game[2].mobs[i].karim = DOWN;
        return;
    }
    if (all->game->map_buff[0] == 'C') {
        all->game[2].mobs[i].pos.x -= i;
        all->game[2].mobs[i].karim = RIGHT;
        return;
    }
    all->game[2].mobs[i].pos.x += i;
    all->game[2].mobs[i].karim = LEFT;
}

void init_monsters_coods(all_t *all)
{
    int arr = 0;

    if (all->game->spawn_mb == true) {
        for (int i = 0; i < all->game->mb_counter; i++) {
            arr = get_randoms(0, all->game->nb_spawn_points - 1, 1);
            all->game[2].mobs[i].pos.x = all->game->spawn_points[arr][0];
            all->game[2].mobs[i].pos.y = all->game->spawn_points[arr][1];
            diff_spawns(all, i);
        }
        all->game->spawn_mb = false;
    }
}

void init_monsters_lifebar(all_t *all)
{
    for (int i = 0; i < all->game->mb_counter; i++) {
        game_object_t lifebar_e = {0, 0, {cross(0.06, all, 'w'),
        cross(0.09, all, 'h')}, 0,
        {cross(all->game[2].mobs[i].pos.x, all, 'w'),
        cross(all->game[2].mobs[i].pos.y - 15, all, 'h')},
        0, 0, {0, 0, 1442, 200}, {0, {0}, 0}};
        init_game_object(&lifebar_e, "./asset/game/empty_lifebar.png");
        all->game[4].game_obj[i] = lifebar_e;
        game_object_t lifebar_full = {0, 0, {cross(0.06, all, 'w'),
        cross(0.09, all, 'h')}, 0, {cross(760, all, 'w'),
        cross(315, all, 'h')}, 0, 0, {100, 0, 1149, 82}, {0, {0}, 0}};
        init_game_object(&lifebar_full, "./asset/game/red_bar.png");
        all->game[4].game_obj[i + all->game->mb_counter] = lifebar_full;
    }
}

void restart_wave(all_t *all)
{
    if (all->game->reached_castle +
    all->game->death_counter >= all->game->mb_counter) {
        all->game->wave += 1;
        all->game->clone_mb_reached = 0;
        all->game->reached_castle = 0;
        all->game->death_counter = 0;
        all->game->mb_counter = mobs_per_waves(all, all->game->wave);
        all->game->draw_mb = true;
        all->game->spawn_mb = true;
        all->game->startwave = true;
        all->game->wavefinished = false;
    }
}

void init_monsters(all_t *all)
{
    if (all->game->draw_mb == true) {
        all->game->mb_counter = mobs_per_waves(all, all->game->wave);
        all->game[2].mobs = malloc(sizeof(mobs_object_t)
        * all->game->mb_counter + 1);
        all->game[4].game_obj = malloc(sizeof(game_object_t)
        * all->game->mb_counter * 2 + 1);
        for (int i = 0; i < all->game->mb_counter; i++) {
            mobs_object_t goblins = {0, 0, {cross(2, all, 'w'),
            cross(2, all, 'h')}, 0, 0, 0, false,
            {cross(22400, all, 'w'), cross(22400, all, 'h')}, 0, 0,
            {294, 64, 30, 32}, {0, {0}, 0}, {0, {0}, 0}, 0};
            init_mobs_object(&goblins, "./asset/game/enemies.png");
            all->game[2].mobs[i] = goblins;
            all->game[2].mobs[i].health =
            75 + all->game->difficulty * all->game->wave + 5;
        }
        init_monsters_lifebar(all);
        all->game->draw_mb = false;
    }
    init_monsters_coods(all);
}