/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** get mobs directions
*/

#include "defender.h"

void get_monsters_directions_two(all_t *all, int i)
{
    if (all->game->map_arr[(int)all->game[2].mobs[i].pos.y]
    [(int)all->game[2].mobs[i].pos.x] == 'U') {
        all->game[2].mobs[i].karim = UP;
    }
    if (all->game->map_arr[(int)all->game[2].mobs[i].pos.y]
        [(int)all->game[2].mobs[i].pos.x] == 'C') {
            all->game[2].mobs[i].health = 0;
            if (all->game[2].mobs[i].health <= 0)
                all->game[2].mobs[i].reached_castle = true;
    }
}

void get_monsters_directions(all_t *all)
{
    for (int i = 0; i < all->game->mb_counter; i++) {
        if (all->game[2].mobs[i].pos.x > 97 || all->game[2].mobs[i].pos.x < 0
        || all->game[2].mobs[i].pos.y < 0 || all->game[2].mobs[i].pos.y > 39) {
            return;
        }
        if (all->game->map_arr[(int)all->game[2].mobs[i].pos.y]
        [(int)all->game[2].mobs[i].pos.x] == 'D') {
            all->game[2].mobs[i].karim = DOWN;
        }
        if (all->game->map_arr[(int)all->game[2].mobs[i].pos.y]
        [(int)all->game[2].mobs[i].pos.x] == 'L') {
            all->game[2].mobs[i].karim = LEFT;
        }
        if (all->game->map_arr[(int)all->game[2].mobs[i].pos.y]
        [(int)all->game[2].mobs[i].pos.x] == 'R') {
            all->game[2].mobs[i].karim = RIGHT;
        }
        get_monsters_directions_two(all, i);
    }
}