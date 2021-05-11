/*
** EPITECH PROJECT, 2021
** defender
** File description:
** draw circle range
*/

#include "defender.h"

void draw_tower_range(all_t *all, tower_object_t tower, sfVector2i mvector)
{
    sfCircleShape_setOrigin(all->game->circle_range,
    (sfVector2f){cross(tower.range + cross(10, all, 'w'), all, 'w'),
    cross(tower.range - cross(5, all, 'w'), all, 'h')});
    sfCircleShape_setPosition(all->game->circle_range,
    (sfVector2f){mvector.x + cross(16, all, 'w'),
    mvector.y + cross(17, all, 'h')});
    sfCircleShape_setRadius(all->game->circle_range,
    cross(tower.range, all, 'w'));
    sfRenderWindow_drawCircleShape(all->window,
    all->game->circle_range, NULL);
}