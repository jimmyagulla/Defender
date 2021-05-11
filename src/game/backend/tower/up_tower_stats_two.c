/*
** EPITECH PROJECT, 2021
** defender
** File description:
** up stats
*/

#include "defender.h"

void upgrade_canon_lvlthree(all_t *all)
{
    all->game[3].tower[all->game->tower_id].upgrade_price = 1000000;
    all->game[3].tower[all->game->tower_id].range = 230;
    all->game[3].tower[all->game->tower_id].damage = 30;
    all->game[3].tower[all->game->tower_id].total_cost = 270;
    all->game[3].tower[all->game->tower_id].attack_speed = 2.5;
}

void upgrade_ice_lvlthree(all_t *all)
{
    all->game[3].tower[all->game->tower_id].upgrade_price = 100000;
    all->game[3].tower[all->game->tower_id].range = 200;
    all->game[3].tower[all->game->tower_id].damage = 20;
    all->game[3].tower[all->game->tower_id].total_cost = 360;
    all->game[3].tower[all->game->tower_id].attack_speed = 1.5;
}

void upgrade_red_lvlthree(all_t *all)
{
    all->game[3].tower[all->game->tower_id].upgrade_price = 100000;
    all->game[3].tower[all->game->tower_id].range = 270;
    all->game[3].tower[all->game->tower_id].damage = 8;
    all->game[3].tower[all->game->tower_id].total_cost = 300;
    all->game[3].tower[all->game->tower_id].attack_speed = 0.35;
}

void upgrade_archer_lvlthree(all_t *all)
{
    all->game[3].tower[all->game->tower_id].upgrade_price = 80;
    all->game[3].tower[all->game->tower_id].range = 360;
    all->game[3].tower[all->game->tower_id].damage = 12;
    all->game[3].tower[all->game->tower_id].total_cost = 170;
    all->game[3].tower[all->game->tower_id].attack_speed = 0.32;
}