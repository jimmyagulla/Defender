/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** place towers
*/

#include "defender.h"

void place_towers_on_map(all_t *all, sfVector2i mvector)
{
    for (int t = 0; t <= 3; t++) {
        all->game->tower_arr[(int)((mvector.y) / cross(27.87, all, 'h')) - t]
        [(int)((mvector.x) / cross(17.39, all, 'w'))] = 'T';
        all->game->tower_arr[(int)((mvector.y) / cross(27.87, all, 'h')) + t]
        [(int)((mvector.x) / cross(17.39, all, 'w'))] = 'T';
        all->game->tower_arr[(int)((mvector.y) / cross(27.87, all, 'h'))]
        [(int)((mvector.x) / cross(17.39, all, 'w')) + 1] = 'T';
        all->game->tower_arr[(int)((mvector.y) / cross(27.87, all, 'h'))]
        [(int)((mvector.x) / cross(17.39, all, 'w')) - 1] = 'T';
        all->game->tower_arr[(int)((mvector.y) / cross(27.87, all, 'h')) + 1]
        [(int)((mvector.x) / cross(17.39, all, 'w')) + 1] = 'T';
        all->game->tower_arr[(int)((mvector.y) / cross(27.87, all, 'h')) - 1]
        [(int)((mvector.x) / cross(17.39, all, 'w')) - 1] = 'T';
    }
    all->game[3].tower[all->game->tower_nb - 1].pos =
    (sfVector2f){mvector.x - cross(30, all, 'w'),
    mvector.y - cross(20, all, 'h')};
}

void handle_towers_placements(all_t *all, sfVector2i mvector)
{
    if (all->game->grab_tower == true && sfMouse_isButtonPressed(sfMouseLeft)
    == false && (int)((mvector.y) / cross(27.87, all, 'h')) > 2 &&
    all->game->tower_arr[(int)((mvector.y) / cross(27.87, all, 'h')) - 2]
    [(int)((mvector.x) / cross(17.39, all, 'w'))] == '.' &&
    all->game->tower_arr[(int)((mvector.y) / cross(27.87, all, 'h'))]
    [(int)((mvector.x) / cross(17.39, all, 'w'))] == '.' &&
    all->game->tower_arr[(int)((mvector.y) / cross(27.87, all, 'h'))]
    [(int)((mvector.x) / cross(17.39, all, 'w')) - 3] == '.' &&
    all->game->tower_arr[(int)((mvector.y) / cross(27.87, all, 'h'))]
    [(int)((mvector.x) / cross(17.39, all, 'w')) + 2] == '.' &&
    mvector.x < cross(1610, all, 'w')) {
        place_towers_on_map(all, mvector);
        sfSprite_setPosition(all->game[3].tower[all->game->tower_nb - 1].sprite
        , (sfVector2f){all->game[3].tower[all->game->tower_nb - 1].pos.x,
        all->game[3].tower[all->game->tower_nb - 1].pos.y});
        all->game->gold_coins -=
        all->game[3].tower[all->game->tower_nb -1].price;
        all->game->grab_tower = false;
    }
}