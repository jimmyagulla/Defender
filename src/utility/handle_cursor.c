/*
** EPITECH PROJECT, 2021
** defender
** File description:
** cursor
*/

#include "defender.h"

void create_cursor(all_t *all)
{
    all->cursor[0].gcursor = malloc(sizeof(game_object_t) * 1);
    game_object_t cursor = {0, 0, {cross(1, all, 'w'), cross(1, all, 'h')}, 0,
    {cross(0, all, 'w'), cross(0, all, 'h')}, 0, 0, {0, 0, 30, 48}, {0,
    {0}, 0}};
    init_game_object(&cursor, "asset/cursor/cursors_sprites.png");
    all->cursor[0].gcursor[0] = cursor;
    sfRenderWindow_setMouseCursorVisible(all->window, false);
}

void draw_cursor(all_t *all)
{
    sfSprite_setPosition(all->cursor->gcursor[0].sprite, (sfVector2f)
    {sfMouse_getPositionRenderWindow(all->window).x,
    sfMouse_getPositionRenderWindow(all->window).y});
    sfRenderWindow_drawSprite(all->window, all->cursor->gcursor[0].sprite,
    NULL);
}