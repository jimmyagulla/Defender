/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** handle towers upgrades
*/

#include "defender.h"

void upgrade_tower_lvl_twoo(all_t *all)
{
    if (all->game[3].tower[all->game->tower_id].tower_type == ARCHER) {
        all->game[3].tower[all->game->tower_id].rect =
        (sfIntRect){247, 135, 144, 179};
        sfSprite_setPosition(all->game[3].tower[all->game->tower_id].sprite,
        (sfVector2f){all->game[3].tower[all->game->tower_id].pos.x,
        all->game[3].tower[all->game->tower_id].pos.y + cross(5, all, 'h')});
        upgrade_archer_lvltwo(all);
    }
    if (all->game[3].tower[all->game->tower_id].tower_type == RED) {
        all->game[3].tower[all->game->tower_id].rect = (sfIntRect){250, 4, 140,
        245};
        sfSprite_setPosition(all->game[3].tower[all->game->tower_id].sprite,
        (sfVector2f){all->game[3].tower[all->game->tower_id].pos.x,
        all->game[3].tower[all->game->tower_id].pos.y - cross(50, all, 'h')});
        upgrade_red_lvltwo(all);
    }
}

void upgrade_tower_lvltwo(all_t *all)
{
    if (all->game[3].tower[all->game->tower_id].tower_type == CANON) {
        all->game[3].tower[all->game->tower_id].rect = (sfIntRect){143, 32, 92,
        96};
        upgrade_canon_lvltwo(all);
    }
    if (all->game[3].tower[all->game->tower_id].tower_type == SLOW) {
        all->game[3].tower[all->game->tower_id].rect = (sfIntRect){130, 29, 96,
        150};
        sfSprite_setPosition(all->game[3].tower[all->game->tower_id].sprite,
        (sfVector2f){all->game[3].tower[all->game->tower_id].pos.x + cross(5,
        all, 'w'), all->game[3].tower[all->game->tower_id].pos.y - cross(3,
        all, 'h')});
        upgrade_ice_lvltwo(all);
    }
    upgrade_tower_lvl_twoo(all);
}

void upgrade_tower_lvlthreee(all_t *all)
{
    if (all->game[3].tower[all->game->tower_id].tower_type == ARCHER) {
        all->game[3].tower[all->game->tower_id].rect =
        (sfIntRect){404, 111, 146, 202};
        sfSprite_setPosition(all->game[3].tower[all->game->tower_id].sprite,
        (sfVector2f){all->game[3].tower[all->game->tower_id].pos.x - cross(2,
        all, 'w'),
        all->game[3].tower[all->game->tower_id].pos.y});
        upgrade_archer_lvlthree(all);
    }
    if (all->game[3].tower[all->game->tower_id].tower_type == RED) {
        all->game[3].tower[all->game->tower_id].rect =
        (sfIntRect){439, 15, 140, 245};
        sfSprite_setPosition(all->game[3].tower[all->game->tower_id].sprite,
        (sfVector2f){all->game[3].tower[all->game->tower_id].pos.x,
        all->game[3].tower[all->game->tower_id].pos.y - cross(47, all, 'h')});
        upgrade_red_lvlthree(all);
    }
}

void upgrade_tower_lvlthree(all_t *all)
{
    if (all->game[3].tower[all->game->tower_id].tower_type == CANON) {
        all->game[3].tower[all->game->tower_id].rect =
        (sfIntRect){274, 2, 130, 125};
        sfSprite_setPosition(all->game[3].tower[all->game->tower_id].sprite,
        (sfVector2f){all->game[3].tower[all->game->tower_id].pos.x - cross(10,
        all, 'w'),
        all->game[3].tower[all->game->tower_id].pos.y - cross(14, all, 'h')});
        upgrade_canon_lvlthree(all);
    }
    if (all->game[3].tower[all->game->tower_id].tower_type == SLOW) {
        all->game[3].tower[all->game->tower_id].rect =
        (sfIntRect){250, 0, 103, 177};
        sfSprite_setPosition(all->game[3].tower[all->game->tower_id].sprite,
        (sfVector2f){all->game[3].tower[all->game->tower_id].pos.x + cross(5,
        all, 'w'),
        all->game[3].tower[all->game->tower_id].pos.y - cross(16, all, 'h')});
        upgrade_ice_lvlthree(all);
    }
    upgrade_tower_lvlthreee(all);
}

void change_tower_rect(all_t *all)
{
    if (all->game[3].tower[all->game->tower_id].upgrade_status == 2)
        upgrade_tower_lvltwo(all);
    if (all->game[3].tower[all->game->tower_id].upgrade_status == 3)
        upgrade_tower_lvlthree(all);
    sfSprite_setTextureRect(all->game[3].tower[all->game->tower_id].sprite,
    all->game[3].tower[all->game->tower_id].rect);
}