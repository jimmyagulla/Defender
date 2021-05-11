/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** up_tower_stats
*/

#include "defender.h"

void upgrade_canon_lvltwo(all_t *all)
{
    all->game[3].tower[all->game->tower_id].upgrade_price = 300;
    all->game[3].tower[all->game->tower_id].range = 230;
    all->game[3].tower[all->game->tower_id].damage = 20;
    all->game[3].tower[all->game->tower_id].total_cost = 270;
    all->game[3].tower[all->game->tower_id].attack_speed = 2.8;
}

void upgrade_ice_lvltwo(all_t *all)
{
    all->game[3].tower[all->game->tower_id].upgrade_price = 200;
    all->game[3].tower[all->game->tower_id].range = 180;
    all->game[3].tower[all->game->tower_id].damage = 10;
    all->game[3].tower[all->game->tower_id].total_cost = 160;
    all->game[3].tower[all->game->tower_id].attack_speed = 2;
}

void upgrade_red_lvltwo(all_t *all)
{
    all->game[3].tower[all->game->tower_id].upgrade_price = 150;
    all->game[3].tower[all->game->tower_id].range = 255;
    all->game[3].tower[all->game->tower_id].damage = 6;
    all->game[3].tower[all->game->tower_id].total_cost = 150;
    all->game[3].tower[all->game->tower_id].attack_speed = 0.37;
}

void upgrade_archer_lvltwo(all_t *all)
{
    all->game[3].tower[all->game->tower_id].upgrade_price = 80;
    all->game[3].tower[all->game->tower_id].range = 300;
    all->game[3].tower[all->game->tower_id].damage = 8;
    all->game[3].tower[all->game->tower_id].total_cost = 90;
    all->game[3].tower[all->game->tower_id].attack_speed = 0.35;
}