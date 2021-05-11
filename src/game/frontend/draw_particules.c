/*
** EPITECH PROJECT, 2021
** defender
** File description:
** draw particules on hit
*/

#include "defender.h"

void draw_ice_particules(all_t *all, int id)
{
    sfCircleShape *fcircle = sfCircleShape_create();
    sfColor blue_ice =  sfColor_fromRGBA(15, 167, 255, 25);
    sfCircleShape_setFillColor(fcircle, blue_ice);
    sfCircleShape_setOrigin(fcircle,
    (sfVector2f){cross(all->game[3].tower[id].range + 10, all, 'w'),
    cross(all->game[3].tower[id].range - 5, all, 'h')});
    sfCircleShape_setRadius(fcircle,
    cross(all->game[3].tower[id].range, all, 'w'));
    sfCircleShape_setPosition(fcircle,
    (sfVector2f){all->game[3].tower[id].pos.x + cross(40, all, 'w'),
    all->game[3].tower[id].pos.y + cross(30, all, 'h')});
    sfCircleShape_setOutlineThickness(fcircle, 1);
    sfCircleShape_setOutlineColor(fcircle, sfBlue);
    sfRenderWindow_drawCircleShape(all->window,
    fcircle, NULL);
}

void draw_canon_particules(all_t *all, int id, int i)
{
    sfRectangleShape *laser = sfRectangleShape_create();
    sfColor color = sfColor_fromRGB(166, 166, 166);
    sfRectangleShape_setFillColor(laser, color);
    sfRectangleShape_rotate(laser, angle(id, i, all));
    sfRectangleShape_setSize(laser,
    (sfVector2f){cross(all->game[3].tower[id].range -
    (all->game[2].mobs->pos.x * 17.39 - all->game[3].tower[id].range) -
    25, all, 'w'), cross(10, all, 'h')});
    sfRectangleShape_setPosition(laser,
    (sfVector2f){all->game[3].tower[id].pos.x + cross(36, all, 'w'),
    all->game[3].tower[id].pos.y});
    sfRenderWindow_drawRectangleShape(all->window, laser, NULL);
}

void draw_red_circle(all_t *all, int i)
{
    sfCircleShape *boom = sfCircleShape_create();
    sfColor color = sfColor_fromRGBA(248, 169, 69, 35);
    sfCircleShape_setFillColor(boom, color);
    sfCircleShape_setPosition(boom, (sfVector2f)
    {all->game[2].mobs[i].pos.x * cross(17.93, all, 'w'),
    all->game[2].mobs[i].pos.y * cross(27.38, all, 'h')});
    sfCircleShape_setOutlineThickness(boom, 1);
    sfCircleShape_setOutlineColor(boom, sfRed);
    sfCircleShape_setRadius(boom,
    cross(20, all, 'w'));
    sfRenderWindow_drawCircleShape(all->window, boom, NULL);
}

void draw_red_particules(all_t *all, int id, int i)
{
    sfRectangleShape *laser = sfRectangleShape_create();
    sfColor color = sfColor_fromRGB(209, 71, 41);
    sfRectangleShape_setFillColor(laser, color);
    if (all->game->map_buff[0] == 'C')
        sfRectangleShape_rotate(laser, angle(id, i, all));
    else
        sfRectangleShape_rotate(laser, angle(id, i, all) - 180);
    sfRectangleShape_setSize(laser,
    (sfVector2f){cross(all->game[3].tower[id].range -
    (all->game[2].mobs->pos.x * 17.39 - all->game[3].tower[id].range) -
    25, all, 'w'), cross(2, all, 'h')});
    sfRectangleShape_setPosition(laser,
    (sfVector2f){all->game[3].tower[id].pos.x + cross(36, all, 'w'),
    all->game[3].tower[id].pos.y});
    sfRenderWindow_drawRectangleShape(all->window, laser, NULL);
    draw_red_circle(all, i);
}

void draw_archer_particules(all_t *all, int id, int i)
{
    sfRectangleShape *laser = sfRectangleShape_create();
    sfColor color = sfColor_fromRGB(0, 0, 0);
    sfRectangleShape_setFillColor(laser, color);
    sfRectangleShape_rotate(laser, angle(id, i, all));
    sfRectangleShape_setSize(laser,
    (sfVector2f){cross(all->game[3].tower[id].range -
    (all->game[2].mobs->pos.x * 17.39 - all->game[3].tower[id].range) -
    25, all, 'w'), cross(1, all, 'h')});
    sfRectangleShape_setPosition(laser,
    (sfVector2f){all->game[3].tower[id].pos.x + cross(36, all, 'w'),
    all->game[3].tower[id].pos.y});
    sfRenderWindow_drawRectangleShape(all->window, laser, NULL);
}