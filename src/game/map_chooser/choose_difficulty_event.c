/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-diogo.faria-martins
** File description:
** choose_difficulty_event
*/

#include "defender.h"

void init_sftext_difficulty(all_t *all)
{
    all->mapchooser->difficulty = sfText_create();
    sfText_setCharacterSize(all->mapchooser->difficulty, cross(70, all, 'w'));
    sfText_setFont(all->mapchooser->difficulty, all->mapchooser->nickfont);
    sfText_setColor(all->mapchooser->difficulty, sfWhite);
    sfText_setPosition(all->mapchooser->difficulty, (sfVector2f){cross
    (940, all, 'w'), cross(620, all, 'h')});
    all->mapchooser->diff_txt = sfText_create();
    sfText_setCharacterSize(all->mapchooser->diff_txt, cross(85, all, 'w'));
    sfText_setFont(all->mapchooser->diff_txt,
    sfFont_createFromFile("asset/letters/scribish.ttf"));
    sfText_setColor(all->mapchooser->diff_txt, sfWhite);
    sfText_setString(all->mapchooser->diff_txt, "Difficulty :");
    sfText_setPosition(all->mapchooser->diff_txt, (sfVector2f){cross
    (700, all, 'w'), cross(500, all, 'h')});
}

void click_difficultyl_scale_event(all_t *all, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed && sfMouse_isButtonPressed
    (sfMouseLeft) && all->game->difficulty > 1) {
        all->game->difficulty -= 1;
    }
    sfSprite_setScale(all->mapchooser[0].game_obj[5].sprite,
    (sfVector2f){cross(0.21, all, 'w'), cross(0.21, all, 'h')});
    sfRectangleShape_setScale(all->mapchooser->two, (sfVector2f)
    {cross(1.05, all, 'w'), cross(1.05, all, 'h')});
}

void click_difficultyl_event(all_t *all, sfEvent event)
{
    sfVector2i mvector = sfMouse_getPositionRenderWindow(all->window);
    float resume_butx = cross(860, all, 'w');
    float resume_buty = cross(719, all, 'h');

    if (resume_butx <= mvector.x && mvector.x
    <= resume_butx + cross(73, all, 'w') && resume_buty
    <= mvector.y && mvector.y <= resume_buty + cross(55, all, 'h')) {
        click_difficultyl_scale_event(all, event);
    } else {
        sfSprite_setScale(all->mapchooser[0].game_obj[5].sprite,
        (sfVector2f){cross(0.2, all, 'w'), cross(0.2, all, 'h')});
    }
}

void click_difficultyr_scale_event(all_t *all, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed && sfMouse_isButtonPressed
    (sfMouseLeft) && all->game->difficulty < 3) {
        all->game->difficulty += 1;
    }
    sfSprite_setScale(all->mapchooser[0].game_obj[6].sprite,
    (sfVector2f){cross(0.21, all, 'w'), cross(0.21, all, 'h')});
    sfRectangleShape_setScale(all->mapchooser->two, (sfVector2f)
    {cross(1.05, all, 'w'), cross(1.05, all, 'h')});
}

void click_difficultyr_event(all_t *all, sfEvent event)
{
    sfVector2i mvector = sfMouse_getPositionRenderWindow(all->window);
    float resume_butx = cross(980, all, 'w');
    float resume_buty = cross(719, all, 'h');

    if (resume_butx <= mvector.x && mvector.x
    <= resume_butx + cross(73, all, 'w') && resume_buty
    <= mvector.y && mvector.y <= resume_buty + cross(55, all, 'h')) {
        click_difficultyr_scale_event(all, event);
    } else {
        sfSprite_setScale(all->mapchooser[0].game_obj[6].sprite,
        (sfVector2f){cross(0.2, all, 'w'), cross(0.2, all, 'h')});
    }
}