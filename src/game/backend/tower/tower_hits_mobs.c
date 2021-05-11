/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** tower hitting mobs hehe
*/

#include "defender.h"

void deal_damage(all_t *all, int i, int n)
{
    all->game[2].mobs[n].health -= all->game[3].tower[i].damage;
    if (all->game[3].tower[i].tower_type == SLOW) {
        all->game[2].mobs[n].slow = 1.5;
        draw_ice_particules(all, i);
    }
    if (all->game[3].tower[i].tower_type == ARCHER) {
        draw_archer_particules(all, i, n);
    }
    if (all->game[3].tower[i].tower_type == CANON) {
        draw_canon_particules(all, i, n);
    }
    if (all->game[3].tower[i].tower_type == RED) {
        draw_red_particules(all, i, n);
    }
}

int hit_top_right(all_t *all, int i)
{
    for (int n = 0; n < all->game->mb_counter; n++) {
        if (cross(all->game[3].tower[i].pos.y - all->game[3].tower[i].range,
        all, 'h') <= cross(all->game[2].mobs[n].pos.y * 27.87, all, 'h') &&
        cross(all->game[2].mobs[n].pos.y * 27.87, all, 'h') <= cross(all->game
        [3].tower[i].pos.y, all, 'h') && cross(all->game[3].tower[i].pos.x, all
        , 'w') <= cross(all->game[2].mobs[n].pos.x * 17.39, all, 'w') && cross
        (all->game[2].mobs[n].pos.x * 17.39, all, 'w') <=
        cross(all->game[3].tower[i].pos.x + all->game[3].tower[i].range,
        all, 'w') && all->game[2].mobs[n].health > 0) {
            deal_damage(all, i, n);
            if (all->game[3].tower[i].tower_type != SLOW)
                return (1);
        }
    }
    return (0);
}

int hit_top_left(all_t *all, int i)
{
    for (int n = 0; n < all->game->mb_counter; n++) {
        if (cross(all->game[3].tower[i].pos.y - all->game[3].tower[i].range,
        all, 'h') <= cross(all->game[2].mobs[n].pos.y * 27.87, all, 'h') &&
        cross(all->game[2].mobs[n].pos.y *27.87, all, 'h') <= cross(all->game
        [3].tower[i].pos.y, all, 'h') && cross(all->game[3].tower[i].pos.x -
        all->game[3].tower[i].range, all, 'w') <= cross(all->game
        [2].mobs[n].pos.x * 17.39, all, 'w') &&
        cross(all->game[2].mobs[n].pos.x
        * 17.39, all, 'w') <= cross(all->game[3].tower[i].pos.x, all, 'w') &&
        all->game[2].mobs[n].health > 0) {
            deal_damage(all, i, n);
            if (all->game[3].tower[i].tower_type != SLOW)
                return (1);
        }
    }
    return (0);
}

int hit_bot_right(all_t *all, int i)
{
    for (int n = 0; n < all->game->mb_counter; n++) {
        if (cross(all->game[3].tower[i].pos.y, all, 'h') <= cross(all->game
        [2].mobs[n].pos.y * 27.87, all, 'h') && cross(all->game[2].mobs
        [n].pos.y * 27.87, all, 'h') <= cross(all->game[3].tower[i].pos.y +
        all->game[3].tower[i].range, all, 'h') && cross(all->game[3].tower
        [i].pos.x, all, 'w') <= cross(all->game[2].mobs[n].pos.x * 17.39, all,
        'w') && cross(all->game[2].mobs[n].pos.x * 17.39, all, 'w') <= cross
        (all->game[3].tower[i].pos.x + all->game[3].tower[i].range, all,
        'w') && all->game[2].mobs[n].health > 0) {
            deal_damage(all, i, n);
            if (all->game[3].tower[i].tower_type != SLOW)
                return (1);
        }
    }
    return (0);
}

int hit_bot_left(all_t *all, int i)
{
    for (int n = 0; n < all->game->mb_counter; n++) {
        if (cross(all->game[3].tower[i].pos.y, all, 'h') <= cross(all->game
        [2].mobs[n].pos.y * 27.87, all, 'h') && cross(all->game[2].mobs
        [n].pos.y * 27.87, all, 'h') <= cross(all->game[3].tower[i].pos.y +
        all->game[3].tower[i].range, all, 'h') && cross(all->game[3].tower
        [i].pos.x - all->game[3].tower[i].range, all, 'w') <= cross(all->game
        [2].mobs[n].pos.x * 17.39, all, 'w') && cross(all->game[2].mobs
        [n].pos.x * 17.39, all, 'w') <= cross(all->game[3].tower[i].pos.x, all,
        'w') && all->game[2].mobs[n].health > 0) {
            deal_damage(all, i, n);
            if (all->game[3].tower[i].tower_type != SLOW)
                return (1);
        }
    }
    return (0);
}