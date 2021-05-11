/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-diogo.faria-martins
** File description:
** handle_mapchooser_maps_events
*/

#include "defender.h"

void click_mapone_event(all_t *all, sfEvent event)
{
    sfVector2i mvector = sfMouse_getPositionRenderWindow(all->window);
    float resume_butx = cross(256, all, 'w');
    float resume_buty = cross(519, all, 'h');

    if (resume_butx <= mvector.x && mvector.x
    <= resume_butx + cross(381, all, 'w') && resume_buty
    <= mvector.y && mvector.y <= resume_buty + cross(216, all, 'h')) {
        click_mapone_scale_event(all, event);
    } else if (all->mapchooser->choice != 1) {
        sfRectangleShape_setScale(all->mapchooser->one, (sfVector2f)
        {cross(1, all, 'w'), cross(1, all, 'h')});
        sfRectangleShape_setFillColor(all->mapchooser->one,
        all->mapchooser->red);
        sfSprite_setScale(all->mapchooser[0].game_obj[1].sprite,
        (sfVector2f){cross(0.2, all, 'w'), cross(0.2, all, 'h')});
    }
}

void click_mapthree_scale_event(all_t *all, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed && sfMouse_isButtonPressed
    (sfMouseLeft)) {
        all->mapchooser->choice = 3;
        sfRectangleShape_setFillColor(all->mapchooser->three,
        all->mapchooser->green);
    }
    sfSprite_setScale(all->mapchooser[0].game_obj[3].sprite,
    (sfVector2f){cross(0.21, all, 'w'), cross(0.21, all, 'h')});
    sfRectangleShape_setScale(all->mapchooser->three, (sfVector2f)
    {cross(1.05, all, 'w'), cross(1.05, all, 'h')});
}

void click_mapthree_event(all_t *all, sfEvent event)
{
    sfVector2i mvector = sfMouse_getPositionRenderWindow(all->window);
    float resume_butx = cross(1280, all, 'w');
    float resume_buty = cross(519, all, 'h');

    if (resume_butx <= mvector.x && mvector.x
    <= resume_butx + cross(381, all, 'w') && resume_buty
    <= mvector.y && mvector.y <= resume_buty + cross(216, all, 'h')) {
        click_mapthree_scale_event(all, event);
    } else if (all->mapchooser->choice != 3) {
        sfRectangleShape_setScale(all->mapchooser->three, (sfVector2f)
        {cross(1, all, 'w'), cross(1, all, 'h')});
        sfRectangleShape_setFillColor(all->mapchooser->three,
        all->mapchooser->red);
        sfSprite_setScale(all->mapchooser[0].game_obj[3].sprite,
        (sfVector2f){cross(0.2, all, 'w'), cross(0.2, all, 'h')});
    }
}

void click_maptwo_scale_event(all_t *all, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed && sfMouse_isButtonPressed
    (sfMouseLeft)) {
        sfRectangleShape_setFillColor(all->mapchooser->two,
        all->mapchooser->green);
        all->mapchooser->choice = 2;
    }
    sfSprite_setScale(all->mapchooser[0].game_obj[2].sprite,
    (sfVector2f){cross(0.21, all, 'w'), cross(0.21, all, 'h')});
    sfRectangleShape_setScale(all->mapchooser->two, (sfVector2f)
    {cross(1.05, all, 'w'), cross(1.05, all, 'h')});
}

void click_maptwo_event(all_t *all, sfEvent event)
{
    sfVector2i mvector = sfMouse_getPositionRenderWindow(all->window);
    float resume_butx = cross(768, all, 'w');
    float resume_buty = cross(519, all, 'h');

    if (resume_butx <= mvector.x && mvector.x
    <= resume_butx + cross(381, all, 'w') && resume_buty
    <= mvector.y && mvector.y <= resume_buty + cross(216, all, 'h')) {
        click_maptwo_scale_event(all, event);
    } else if (all->mapchooser->choice != 2) {
        sfRectangleShape_setFillColor(all->mapchooser->two,
        all->mapchooser->red);
        sfRectangleShape_setScale(all->mapchooser->two, (sfVector2f)
        {cross(1, all, 'w'), cross(1, all, 'h')});
        sfSprite_setScale(all->mapchooser[0].game_obj[2].sprite,
        (sfVector2f){cross(0.2, all, 'w'), cross(0.2, all, 'h')});
    }
}