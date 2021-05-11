/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** gameover_buttons_events
*/

#include "defender.h"

void scale_restart_button(all_t *all, sfVector2i mvector)
{
    int menuposx = cross(725, all, 'w');
    int menuposy = cross(535, all, 'h');

    if (menuposx <= mvector.x && mvector.x <= menuposx +
    cross(265, all, 'w')
    && menuposy + 20 <= mvector.y && mvector.y <= menuposy +
    cross(120, all, 'h')) {
        sfSprite_setScale(all->gameover[0].game_obj[1].sprite,
        (sfVector2f){cross(1.3, all, 'w'), cross(1.3, all, 'h')});
        sfSprite_setPosition(all->gameover[0].game_obj[1].sprite,
        (sfVector2f){cross(715, all, 'w'), cross(555, all, 'h')});
    } else {
        sfSprite_setPosition(all->gameover[0].game_obj[1].sprite,
        (sfVector2f){cross(725, all, 'w'), cross(565, all, 'h')});
        sfSprite_setScale(all->gameover[0].game_obj[1].sprite,
        (sfVector2f){cross(1.2, all, 'w'), cross(1.2, all, 'h')});
    }
}

void restart_button_mouse(all_t *all, sfEvent event, sfVector2i mvector)
{
    int menupos_onex = cross(725, all, 'w');
    int menupos_oney = cross(535, all, 'h');

    scale_restart_button(all, mvector);
    if (sfMouse_isButtonPressed(sfMouseLeft) == true && event.type
    == sfEvtMouseButtonPressed && sfMouse_isButtonPressed
    (sfMouseLeft))
        if (menupos_onex <= mvector.x
        && mvector.x <= menupos_onex + cross(265, all, 'w')
        && menupos_oney <= mvector.y
        && mvector.y + 20 <= menupos_oney + cross(120, all, 'h')) {
            init_game_hehe(all);
            sfMusic_destroy(all->gameover->gameover_sound);
            play_clicksound(all);
            all->status = game;
        }
}

void scale_menu_button(all_t *all, sfVector2i mvector)
{
    int menuposx = cross(725, all, 'w');
    int menuposy = cross(635, all, 'h');

    if (menuposx <= mvector.x && mvector.x <= menuposx +
    cross(265, all, 'w')
    && menuposy + 20 <= mvector.y && mvector.y <= menuposy +
    cross(120, all, 'h')) {
        sfSprite_setScale(all->gameover[0].game_obj[2].sprite,
        (sfVector2f){cross(1.3, all, 'w'), cross(1.3, all, 'h')});
        sfSprite_setPosition(all->gameover[0].game_obj[2].sprite,
        (sfVector2f){cross(715, all, 'w'), cross(655, all, 'h')});
    } else {
        sfSprite_setPosition(all->gameover[0].game_obj[2].sprite,
        (sfVector2f){cross(725, all, 'w'), cross(665, all, 'h')});
        sfSprite_setScale(all->gameover[0].game_obj[2].sprite,
        (sfVector2f){cross(1.2, all, 'w'), cross(1.2, all, 'h')});
    }
}

void menu_button_mouse(all_t *all, sfEvent event, sfVector2i mvector)
{
    int menupos_onex = cross(725, all, 'w');
    int menupos_oney = cross(635, all, 'h');

    scale_menu_button(all, mvector);
    if (sfMouse_isButtonPressed(sfMouseLeft) == true && event.type
    == sfEvtMouseButtonPressed && sfMouse_isButtonPressed
    (sfMouseLeft))
        if (menupos_onex <= mvector.x
        && mvector.x <= menupos_onex + cross(265, all, 'w')
        && menupos_oney <= mvector.y
        && mvector.y + 20 <= menupos_oney + cross(120, all, 'h')) {
            all->status = menu;
            sfMusic_destroy(all->gameover->gameover_sound);
            play_clicksound(all);
        }
}