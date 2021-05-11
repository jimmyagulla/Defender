/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-diogo.faria-martins
** File description:
** handle_towers_attack
*/

#include "defender.h"

void handle_tower_clocks(all_t *all)
{
    for (int i = 0; i < all->game->tower_nb; i++) {
        all->game[3].tower[i].clock.time =
        sfClock_getElapsedTime(all->game[3].tower[i].clock.clock);
        all->game[3].tower[i].clock.seconds =
        all->game[3].tower[i].clock.time.microseconds / 1000000;
    }
}

int can_tower_attack(tower_object_t tower, all_t *all)
{
    if (tower.clock.seconds > 1 * tower.attack_speed /
    (all->game->game_speed + 0.5)) {
        return (1);
    }
    return (0);
}

void handle_attack(all_t *all, int i)
{
    if (can_tower_attack(all->game[3].tower[i], all) == 1) {
        if (hit_bot_right(all, i) == 1)
            return;
        if (hit_bot_left(all, i) == 1)
            return;
        if (hit_top_right(all, i))
            return;
        if (hit_top_left(all, i) == 1)
            return;
        sfClock_restart(all->game[3].tower[i].clock.clock);
        all->game[3].tower[i].clock.seconds = 0;
    }
}

void tower_hit_mobs(all_t *all)
{
    if (all->game->tower_nb > 0)
        handle_tower_clocks(all);
    for (int i = 0; i < all->game->tower_nb; i++) {
        handle_attack(all, i);
    }
}