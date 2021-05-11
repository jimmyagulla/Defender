/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** handle lifebars
*/

#include "defender.h"

float get_mobs_lifebarlen(mobs_object_t mob, int og_w, all_t *all)
{
    float rect_len = 0;
    float health = mob.health;

    rect_len = (health /
    (75 + all->game->difficulty * all->game->wave + 5)) * og_w;
    return (rect_len);
}