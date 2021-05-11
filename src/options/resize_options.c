/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** options
*/

#include "defender.h"

void rezize_sprites_two(all_t *all)
{
    sfSprite_setPosition(all->menu[1].settings[4].sprite,
    (sfVector2f){cross(155, all, 'w'), cross(120, all, 'h')});
    sfSprite_setPosition(all->menu[1].settings[1].sprite,
    (sfVector2f){cross(all->menu->sfx_posx, all, 'w'), cross(280, all, 'h')});
    sfSprite_setPosition(all->menu[1].settings[2].sprite,
    (sfVector2f){cross(all->menu->music_posx, all, 'w'), cross(433, all, 'h')});
    sfSprite_setPosition(all->menu[1].settings[3].sprite,
    (sfVector2f){cross(all->menu->fps_posx, all, 'w'), cross(589, all, 'h')});
    sfSprite_setScale(all->cursor[0].gcursor[0].sprite,
    (sfVector2f){cross(1, all, 'w'), cross(1, all, 'h')});
    sfRenderWindow_setMouseCursorVisible(all->window, false);
}

void rezize_sprites(all_t *all)
{
    if (all->resize_status == resize) {
        sfSprite_setScale(all->menu[1].settings[0].sprite,
        (sfVector2f){cross(1, all, 'w'), cross(1, all, 'h')});
        sfSprite_setScale(all->menu[1].settings[1].sprite,
        (sfVector2f){cross(1, all, 'w'), cross(1, all, 'h')});
        sfSprite_setScale(all->menu[1].settings[2].sprite,
        (sfVector2f){cross(1, all, 'w'), cross(1, all, 'h')});
        sfSprite_setScale(all->menu[1].settings[3].sprite,
        (sfVector2f){cross(1, all, 'w'), cross(1, all, 'h')});
        sfSprite_setScale(all->menu[1].settings[4].sprite,
        (sfVector2f){cross(0.7, all, 'w'), cross(0.7, all, 'h')});
        rezize_sprites_two(all);
        all->resize_status = resized;
    }
}