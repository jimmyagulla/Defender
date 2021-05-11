/*
** EPITECH PROJECT, 2021
** defender
** File description:
** display boards
*/

#include "defender.h"

void display_upgrade(all_t *all)
{
    if (all->game->display_upgrd == true) {
        draw_tower_range(all, all->game[3].tower[all->game->tower_id],
        (sfVector2i){all->game[3].tower[all->game->tower_id].pos.x +
        cross(30, all, 'w'),
        all->game[3].tower[all->game->tower_id].pos.y + cross(22, all, 'h')});
    }
}

void start_wave(all_t *all)
{
    if (all->game->startwave == true) {
        all->game->mb_counter = mobs_per_waves(all, all->game->wave);
        init_monsters(all);
        get_path_pos(all);
        tower_hit_mobs(all);
    }
}