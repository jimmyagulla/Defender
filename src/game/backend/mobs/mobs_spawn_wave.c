/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** move_monsters
*/

#include "defender.h"

int mobs_per_waves(all_t *all, int wave)
{
    int counter = 0;

    counter = wave * all->game->difficulty * 3;
    return (counter);
}

void map_size(all_t *all)
{
    int longest_x = 0;
    int longest_y = 0;

    for (int y = 0; all->game->map_arr[y] != NULL; y++) {
        for (int x = 0; all->game->map_arr[y][x] != 0; x++) {
            if (y > longest_y)
                longest_y = y;
            if (x > longest_x)
                longest_x = x;
            all->game->map_cols = longest_x;
            all->game->map_lines = longest_y;
        }
    }
}