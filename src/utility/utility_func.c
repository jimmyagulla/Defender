/*
** EPITECH PROJECT, 2021
** defender
** File description:
** utility
*/

#include "defender.h"

float angle(int id, int i, all_t *all)
{
    double diff_x = (all->game[3].tower[id].pos.x -
    all->game[2].mobs[i].pos.x * cross(17.39, all, 'w'));
    double diff_y =  (all->game[3].tower[id].pos.y -
    all->game[2].mobs[i].pos.y * cross(27.87, all, 'h'));
    float angle = atan2f(diff_y, diff_x) * (180.0 / M_PI) - 180;
    return (angle);
}