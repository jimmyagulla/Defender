/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** handling settings buttons functions
*/

#include "defender.h"

void handle_button_one(all_t *all, sfEvent event)
{
    float button_onex = cross(720, all, 'w');
    float button_oney = cross(717, all, 'h');
    sfVector2i mvector = sfMouse_getPositionRenderWindow(all->window);

    if (event.type == sfEvtMouseButtonPressed && sfMouse_isButtonPressed
    (sfMouseLeft))
        if (button_onex <= mvector.x
        && mvector.x <= button_onex + cross(150, all, 'w') && button_oney
        <= mvector.y && mvector.y <= button_oney + cross(65, all, 'h')) {
            play_clicksound(all);
            sfRenderWindow_destroy(all->window);
            all->window = create_window(all, 1920, 1080,
            (sfUint32)sfFullscreen);
            all->width = 1920;
            all->height = 1080;
            all->resize_status = resize;
        }
}

void handle_button_two(all_t *all, sfEvent event)
{
    float button_twox = cross(885, all, 'w');
    float button_twoy = cross(717, all, 'h');
    sfVector2i mvector = sfMouse_getPositionRenderWindow(all->window);

    if (event.type == sfEvtMouseButtonPressed && sfMouse_isButtonPressed
    (sfMouseLeft))
        if (button_twox <= mvector.x
        && mvector.x <= button_twox + cross(148, all, 'w') && button_twoy
        <= mvector.y && mvector.y <= button_twoy + cross(65, all, 'h')) {
            play_clicksound(all);
            sfRenderWindow_destroy(all->window);
            all->window = create_window(all, 1440, 900,
            (sfUint32)sfDefaultStyle);
            all->width = 1440;
            all->height = 900;
            all->menu->resizenb = resize_two;
            all->resize_status = resize;
        }
}

void handle_button_three(all_t *all, sfEvent event)
{
    float button_threex = cross(1045, all, 'w');
    float button_threey = cross(717, all, 'h');
    sfVector2i mvector = sfMouse_getPositionRenderWindow(all->window);

    if (event.type == sfEvtMouseButtonPressed && sfMouse_isButtonPressed
    (sfMouseLeft))
        if (button_threex <= mvector.x
        && mvector.x <= button_threex + cross(155, all, 'w') && button_threey
        <= mvector.y && mvector.y <= button_threey + cross(65, all, 'h')) {
            play_clicksound(all);
            sfRenderWindow_destroy(all->window);
            all->window = create_window(all, 1024, 768,
            (sfUint32)sfDefaultStyle);
            all->width = 1024;
            all->height = 768;
            all->menu->resizenb = resize_three;
            all->resize_status = resize;
        }
}