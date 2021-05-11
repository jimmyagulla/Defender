/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** menu_buttons
*/

#include "defender.h"

void play_button(all_t *all)
{
    int menuposx = cross(760, all, 'w');
    int menuposy = cross(335, all, 'h');
    sfVector2i mvector = sfMouse_getPositionRenderWindow(all->window);

    if (menuposx <= mvector.x && mvector.x <= menuposx + cross(360, all, 'w')
    && menuposy <= mvector.y && mvector.y <= menuposy + cross(120, all, 'h')) {
            sfSprite_setPosition(all->menu[0].settings[7].sprite,
            (sfVector2f){cross(730, all, 'w'), cross(315, all, 'h')});
            sfSprite_setScale(all->menu[0].settings[7].sprite,
            (sfVector2f){cross(0.7, all, 'w'), cross(0.7, all, 'h')});
    } else {
            sfSprite_setScale(all->menu[0].settings[7].sprite,
            (sfVector2f){cross(0.6, all, 'w'), cross(0.6, all, 'h')});
            sfSprite_setPosition(all->menu[0].settings[7].sprite,
            (sfVector2f){cross(760, all, 'w'), cross(335, all, 'h')});
    }
}

void option_button(all_t *all)
{
    int menuposx = cross(760, all, 'w');
    int menuposy = cross(470, all, 'h');
    sfVector2i mvector = sfMouse_getPositionRenderWindow(all->window);

    if (menuposx <= mvector.x && mvector.x <= menuposx + cross(360, all, 'w')
    && menuposy <= mvector.y && mvector.y <= menuposy + cross(120, all, 'h')) {
        sfSprite_setPosition(all->menu[0].settings[8].sprite,
        (sfVector2f){cross(730, all, 'w'), cross(465, all, 'h')});
        sfSprite_setScale(all->menu[0].settings[8].sprite,
        (sfVector2f){cross(0.7, all, 'w'), cross(0.7, all, 'h')});
    } else {
        sfSprite_setScale(all->menu[0].settings[8].sprite,
        (sfVector2f){cross(0.6, all, 'w'), cross(0.6, all, 'h')});
        sfSprite_setPosition(all->menu[0].settings[8].sprite,
        (sfVector2f){cross(760, all, 'w'), cross(480, all, 'h')});
    }
}

void quit_button(all_t *all)
{
    int menuposx = cross(760, all, 'w');
    int menuposy = cross(620, all, 'h');
    sfVector2i mvector = sfMouse_getPositionRenderWindow(all->window);

    if (menuposx <= mvector.x && mvector.x <= menuposx + cross(360, all, 'w')
    && menuposy <= mvector.y && mvector.y <= menuposy + cross(120, all, 'h')) {
        sfSprite_setPosition(all->menu[0].settings[9].sprite,
        (sfVector2f){cross(730, all, 'w'), cross(620, all, 'h')});
        sfSprite_setScale(all->menu[0].settings[9].sprite,
        (sfVector2f){cross(0.7, all, 'w'), cross(0.7, all, 'h')});
    } else {
        sfSprite_setScale(all->menu[0].settings[9].sprite,
        (sfVector2f){cross(0.6, all, 'w'), cross(0.6, all, 'h')});
        sfSprite_setPosition(all->menu[0].settings[9].sprite,
        (sfVector2f){cross(760, all, 'w'), cross(620, all, 'h')});
    }
}

void return_button_event(all_t *all)
{
    sfVector2i mvector = sfMouse_getPositionRenderWindow(all->window);
    float return_butx = cross(155, all, 'w');
    float return_buty = cross(120, all, 'h');

    if (return_butx <= mvector.x && mvector.x
    <= return_butx + cross(215, all, 'w') && return_buty
    <= mvector.y && mvector.y <= return_buty + cross(72, all, 'h')) {
        sfSprite_setScale(all->menu[1].settings[4].sprite,
        (sfVector2f){cross(1.1, all, 'w'), cross(1.1, all, 'h')});
        sfSprite_setPosition(all->menu[1].settings[4].sprite,
        (sfVector2f){cross(145, all, 'w'), cross(120, all, 'h')});
    } else {
        sfSprite_setPosition(all->menu[1].settings[4].sprite,
        (sfVector2f){cross(155, all, 'w'), cross(120, all, 'h')});
        sfSprite_setScale(all->menu[1].settings[4].sprite,
        (sfVector2f){cross(1, all, 'w'), cross(1, all, 'h')});
    }
}