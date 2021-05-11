/*
** EPITECH PROJECT, 2021
** defender
** File description:
** display upgrade board
*/

#include "defender.h"

void display_level_three_board_two(all_t *all)
{
    if (all->game[3].tower[all->game->tower_id].tower_type == ARCHER) {
        all->game[0].game_obj[10].rect = (sfIntRect){0, 139, 283, 467};
        sfSprite_setTextureRect(all->game[0].game_obj[10].sprite,
        all->game[0].game_obj[10].rect);
        sfRenderWindow_drawSprite(all->window, all->game[0].game_obj[10].sprite
        , NULL);
    }
    if (all->game[3].tower[all->game->tower_id].tower_type == RED) {
        all->game[0].game_obj[10].rect = (sfIntRect){858, 139, 280, 467};
        sfSprite_setTextureRect(all->game[0].game_obj[10].sprite,
        all->game[0].game_obj[10].rect);
        sfRenderWindow_drawSprite(all->window, all->game[0].game_obj[10].sprite,
        NULL);
    }
}

void display_level_three_board(all_t *all)
{
    if (all->game[3].tower[all->game->tower_id].tower_type == CANON) {
        all->game[0].game_obj[10].rect = (sfIntRect){575, 139, 280, 467};
        sfSprite_setTextureRect(all->game[0].game_obj[10].sprite,
        all->game[0].game_obj[10].rect);
        sfRenderWindow_drawSprite(all->window, all->game[0].game_obj[10].sprite
        , NULL);
    }
    if (all->game[3].tower[all->game->tower_id].tower_type == SLOW) {
        all->game[0].game_obj[10].rect = (sfIntRect){288, 139, 280, 467};
        sfSprite_setTextureRect(all->game[0].game_obj[10].sprite,
        all->game[0].game_obj[10].rect);
        sfRenderWindow_drawSprite(all->window, all->game[0].game_obj[10].sprite
        , NULL);
    }
    display_level_three_board_two(all);
}

void display_level_one_board_two(all_t *all)
{
    if (all->game[3].tower[all->game->tower_id].tower_type == ARCHER) {
        all->game[0].game_obj[8].rect = (sfIntRect){0, 139, 283, 467};
        sfSprite_setTextureRect(all->game[0].game_obj[8].sprite,
        all->game[0].game_obj[8].rect);
        sfRenderWindow_drawSprite(all->window, all->game[0].game_obj[8].sprite
        , NULL);
    }
    if (all->game[3].tower[all->game->tower_id].tower_type == RED) {
        all->game[0].game_obj[8].rect = (sfIntRect){858, 139, 280, 467};
        sfSprite_setTextureRect(all->game[0].game_obj[8].sprite,
        all->game[0].game_obj[8].rect);
        sfRenderWindow_drawSprite(all->window, all->game[0].game_obj[8].sprite,
        NULL);
    }
}

void display_level_one_board(all_t *all)
{
    if (all->game[3].tower[all->game->tower_id].tower_type == CANON) {
        all->game[0].game_obj[8].rect = (sfIntRect){575, 139, 280, 467};
        sfSprite_setTextureRect(all->game[0].game_obj[8].sprite,
        all->game[0].game_obj[8].rect);
        sfRenderWindow_drawSprite(all->window, all->game[0].game_obj[8].sprite
        , NULL);
    }
    if (all->game[3].tower[all->game->tower_id].tower_type == SLOW) {
        all->game[0].game_obj[8].rect = (sfIntRect){288, 139, 280, 467};
        sfSprite_setTextureRect(all->game[0].game_obj[8].sprite,
        all->game[0].game_obj[8].rect);
        sfRenderWindow_drawSprite(all->window, all->game[0].game_obj[8].sprite
        , NULL);
    }
    display_level_one_board_two(all);
}

void display_tower_upgrd_window(all_t *all)
{
    if (all->game->display_upgrd == true) {
        if (all->game[3].tower[all->game->tower_id].upgrade_status == 1) {
            display_level_one_board(all);
        }
        if (all->game[3].tower[all->game->tower_id].upgrade_status == 2) {
            display_level_two_board(all);
        }
        if (all->game[3].tower[all->game->tower_id].upgrade_status == 3) {
            display_level_three_board(all);
        }
    }
}