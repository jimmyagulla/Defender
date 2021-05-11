/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-diogo.faria-martins
** File description:
** hanlde_game_buttons
*/

#include "defender.h"

void scale_gplay_button(all_t *all, sfVector2i mvector)
{
    int menuposx = cross(1700, all, 'w');
    int menuposy = cross(965, all, 'h');

    if (menuposx <= mvector.x && mvector.x <= menuposx + cross(196, all, 'w')
    && menuposy <= mvector.y && mvector.y <= menuposy + cross(120, all, 'h')) {
            sfSprite_setPosition(all->game[0].game_obj[3].sprite,
            (sfVector2f){cross(1696, all, 'w'), cross(968, all, 'h')});
            sfSprite_setScale(all->game[0].game_obj[3].sprite,
            (sfVector2f){cross(0.26, all, 'w'), cross(0.35, all, 'h')});
    } else {
            sfSprite_setScale(all->game[0].game_obj[3].sprite,
            (sfVector2f){cross(0.25, all, 'w'), cross(0.3, all, 'h')});
            sfSprite_setPosition(all->game[0].game_obj[3].sprite,
            (sfVector2f){cross(1700, all, 'w'), cross(968, all, 'h')});
    }
}

void play_button_mouse(all_t *all, sfEvent event, sfVector2i mvector)
{
    int menupos_onex = cross(1700, all, 'w');
    int menupos_oney = cross(965, all, 'h');

    scale_gplay_button(all, mvector);
    if (sfMouse_isButtonPressed(sfMouseLeft) == true && event.type
    == sfEvtMouseButtonPressed && sfMouse_isButtonPressed
    (sfMouseLeft))
            if (menupos_onex <= mvector.x
            && mvector.x <= menupos_onex + cross(196, all, 'w')
            && menupos_oney <= mvector.y
            && mvector.y <= menupos_oney + cross(120, all, 'h')) {
                play_clicksound(all);
                restart_wave(all);
            }
}

void scale_gaccelerate_button(all_t *all, sfVector2i mvector)
{
    int menuposx = cross(1700, all, 'w');
    int menuposy = cross(862, all, 'h');

    if ((menuposx <= mvector.x && mvector.x <= menuposx + cross(196, all, 'w')
    && menuposy <= mvector.y && mvector.y <= menuposy + cross(60, all, 'h')) ||
    all->game->game_speed == 2) {
        sfSprite_setPosition(all->game[0].game_obj[4].sprite,
        (sfVector2f){cross(1693, all, 'w'), cross(862, all, 'h')});
        sfSprite_setScale(all->game[0].game_obj[4].sprite,
        (sfVector2f){cross(0.70, all, 'w'), cross(0.9, all, 'h')});
    } else if (all->game->game_speed == 1) {
            sfSprite_setScale(all->game[0].game_obj[4].sprite,
            (sfVector2f){cross(0.65, all, 'w'), cross(0.8, all, 'h')});
            sfSprite_setPosition(all->game[0].game_obj[4].sprite,
            (sfVector2f){cross(1700, all, 'w'), cross(862, all, 'h')});
    }
}

void accelerate_button_mouse(all_t *all, sfEvent event, sfVector2i mvector)
{
    int menupos_onex = cross(1700, all, 'w');
    int menupos_oney = cross(862, all, 'h');

    scale_gaccelerate_button(all, mvector);
    if (sfMouse_isButtonPressed(sfMouseLeft) == true && (event.type ==
    sfEvtMouseButtonPressed && sfMouse_isButtonPressed(sfMouseLeft)))
            if (menupos_onex <= mvector.x
            && mvector.x <= menupos_onex + cross(196, all, 'w')
            && menupos_oney <= mvector.y
            && mvector.y <= menupos_oney + cross(60, all, 'h')) {
                play_clicksound(all);
                all->game->game_speed = (all->game->game_speed == 1) ? 2 : 1;
            }
}