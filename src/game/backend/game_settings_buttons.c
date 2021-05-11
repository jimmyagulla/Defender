/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** game_settings_buttons
*/

#include "defender.h"

void resume_button(all_t *all, sfEvent event)
{
    sfVector2i mvector = sfMouse_getPositionRenderWindow(all->window);
    float resume_butx = cross(769, all, 'w');
    float resume_buty = cross(350, all, 'h');

    if (resume_butx <= mvector.x && mvector.x
    <= resume_butx + cross(215, all, 'w') && resume_buty
    <= mvector.y && mvector.y <= resume_buty + cross(72, all, 'h')) {
        if (event.type == sfEvtMouseButtonPressed && sfMouse_isButtonPressed
        (sfMouseLeft))
            all->game->show_settings = !all->game->show_settings;
        sfSprite_setScale(all->game[1].game_obj[1].sprite,
        (sfVector2f){cross(1.1, all, 'w'), cross(1.1, all, 'h')});
        sfSprite_setPosition(all->game[1].game_obj[1].sprite,
        (sfVector2f){cross(754, all, 'w'), cross(340, all, 'h')});
    } else {
        sfSprite_setPosition(all->game[1].game_obj[1].sprite,
        (sfVector2f){cross(769, all, 'w'), cross(350, all, 'h')});
        sfSprite_setScale(all->game[1].game_obj[1].sprite,
        (sfVector2f){cross(1, all, 'w'), cross(1, all, 'h')});
    }
}

void change_to_settings(all_t *all, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed && sfMouse_isButtonPressed
    (sfMouseLeft)) {
        all->status = option;
        all->pre_status = game;
        option_loop(all);
    }
}

void option_gbutton(all_t *all, sfEvent event)
{
    sfVector2i mvector = sfMouse_getPositionRenderWindow(all->window);
    float resume_butx = cross(769, all, 'w');
    float resume_buty = cross(450, all, 'h');

    if (resume_butx <= mvector.x && mvector.x
    <= resume_butx + cross(215, all, 'w') && resume_buty
    <= mvector.y && mvector.y <= resume_buty + cross(72, all, 'h')) {
        change_to_settings(all, event);
        sfSprite_setScale(all->game[1].game_obj[2].sprite,
        (sfVector2f){cross(1.1, all, 'w'), cross(1.1, all, 'h')});
        sfSprite_setPosition(all->game[1].game_obj[2].sprite,
        (sfVector2f){cross(754, all, 'w'), cross(440, all, 'h')});
    } else {
        sfSprite_setPosition(all->game[1].game_obj[2].sprite,
        (sfVector2f){cross(769, all, 'w'), cross(450, all, 'h')});
        sfSprite_setScale(all->game[1].game_obj[2].sprite,
        (sfVector2f){cross(1, all, 'w'), cross(1, all, 'h')});
    }
}

void quit_gbutton(all_t *all, sfEvent event)
{
    sfVector2i mvector = sfMouse_getPositionRenderWindow(all->window);
    float resume_butx = cross(769, all, 'w');
    float resume_buty = cross(650, all, 'h');

    if (resume_butx <= mvector.x && mvector.x
    <= resume_butx + cross(215, all, 'w') && resume_buty
    <= mvector.y && mvector.y <= resume_buty + cross(72, all, 'h')) {
        if (event.type == sfEvtMouseButtonPressed && sfMouse_isButtonPressed
    (sfMouseLeft))
            all->status = quit_game;
        sfSprite_setScale(all->game[1].game_obj[4].sprite,
        (sfVector2f){cross(1.1, all, 'w'), cross(1.1, all, 'h')});
        sfSprite_setPosition(all->game[1].game_obj[4].sprite,
        (sfVector2f){cross(754, all, 'w'), cross(640, all, 'h')});
    } else {
        sfSprite_setPosition(all->game[1].game_obj[4].sprite,
        (sfVector2f){cross(769, all, 'w'), cross(650, all, 'h')});
        sfSprite_setScale(all->game[1].game_obj[4].sprite,
        (sfVector2f){cross(1, all, 'w'), cross(1, all, 'h')});
    }
}

void menu_button(all_t *all, sfEvent event)
{
    sfVector2i mvector = sfMouse_getPositionRenderWindow(all->window);
    float resume_butx = cross(769, all, 'w');
    float resume_buty = cross(550, all, 'h');

    if (resume_butx <= mvector.x && mvector.x
    <= resume_butx + cross(215, all, 'w') && resume_buty
    <= mvector.y && mvector.y <= resume_buty + cross(72, all, 'h')) {
        if (event.type == sfEvtMouseButtonPressed &&
        sfMouse_isButtonPressed(sfMouseLeft))
            all->status = menu;
        sfSprite_setScale(all->game[1].game_obj[3].sprite,
        (sfVector2f){cross(1.1, all, 'w'), cross(1.1, all, 'h')});
        sfSprite_setPosition(all->game[1].game_obj[3].sprite,
        (sfVector2f){cross(754, all, 'w'), cross(540, all, 'h')});
    } else {
        sfSprite_setPosition(all->game[1].game_obj[3].sprite,
        (sfVector2f){cross(769, all, 'w'), cross(550, all, 'h')});
        sfSprite_setScale(all->game[1].game_obj[3].sprite,
        (sfVector2f){cross(1, all, 'w'), cross(1, all, 'h')});
    }
}