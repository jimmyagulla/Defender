/*
** EPITECH PROJECT, 2021
** defender
** File description:
** display upgrade boards
*/

#include "defender.h"

void display_level_two_board_two(all_t *all)
{
    if (all->game[3].tower[all->game->tower_id].tower_type == ARCHER) {
        all->game[0].game_obj[9].rect = (sfIntRect){0, 139, 283, 467};
        sfSprite_setTextureRect(all->game[0].game_obj[9].sprite,
        all->game[0].game_obj[9].rect);
        sfRenderWindow_drawSprite(all->window, all->game[0].game_obj[9].sprite
        , NULL);
    }
    if (all->game[3].tower[all->game->tower_id].tower_type == RED) {
        all->game[0].game_obj[9].rect = (sfIntRect){858, 139, 280, 467};
        sfSprite_setTextureRect(all->game[0].game_obj[9].sprite,
        all->game[0].game_obj[9].rect);
        sfRenderWindow_drawSprite(all->window, all->game[0].game_obj[9].sprite,
        NULL);
    }
}

void display_level_two_board(all_t *all)
{
    if (all->game[3].tower[all->game->tower_id].tower_type == CANON) {
        all->game[0].game_obj[9].rect = (sfIntRect){575, 139, 280, 467};
        sfSprite_setTextureRect(all->game[0].game_obj[9].sprite,
        all->game[0].game_obj[9].rect);
        sfRenderWindow_drawSprite(all->window, all->game[0].game_obj[9].sprite
        , NULL);
    }
    if (all->game[3].tower[all->game->tower_id].tower_type == SLOW) {
        all->game[0].game_obj[9].rect = (sfIntRect){288, 139, 280, 467};
        sfSprite_setTextureRect(all->game[0].game_obj[9].sprite,
        all->game[0].game_obj[9].rect);
        sfRenderWindow_drawSprite(all->window, all->game[0].game_obj[9].sprite
        , NULL);
    }
    display_level_two_board_two(all);
}