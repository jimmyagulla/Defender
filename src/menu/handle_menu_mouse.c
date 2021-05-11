/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** handle_menu_mouse
*/

#include "defender.h"

void menu_mouse_option(all_t *all, sfEvent event)
{
    int menuposx = cross(760, all, 'w');
    int menuposy = cross(470, all, 'h');
    sfVector2i mvector = sfMouse_getPositionRenderWindow(all->window);

    if (menuposx <= mvector.x && mvector.x <= menuposx + cross(360, all, 'w')
    && menuposy <= mvector.y && mvector.y <= menuposy + cross(120, all, 'h')
    && event.type == sfEvtMouseButtonPressed
    && sfMouse_isButtonPressed(sfMouseLeft)) {
        sfMusic_destroy(all->click_sound);
        all->click_sound =
        sfMusic_createFromFile("asset/menu/sounds/buttonclick.ogg");
        sfMusic_setVolume(all->click_sound, all->menu->sfx_vol);
        play_clicksound(all);
        all->status = option;
    }
}

void menu_mouse_two(all_t *all, sfEvent event)
{
    int menupos_onex = cross(760, all, 'w');
    int menupos_oney = cross(335, all, 'h');
    sfVector2i mvector = sfMouse_getPositionRenderWindow(all->window);

    if (sfMouse_isButtonPressed(sfMouseLeft) == true)
        if (event.type == sfEvtMouseButtonPressed && sfMouse_isButtonPressed
        (sfMouseLeft))
            if (menupos_onex <= mvector.x
            && mvector.x <= menupos_onex + cross(360, all, 'w')
            && menupos_oney <= mvector.y
            && mvector.y <= menupos_oney + cross(120, all, 'h')) {
                play_clicksound(all);
                all->status = game;
            }
}

void menu_mouse(all_t *all, sfEvent event)
{
    int menuposx = cross(760, all, 'w');
    int menuposy = cross(620, all, 'h');
    sfVector2i mvector = sfMouse_getPositionRenderWindow(all->window);

    play_button(all);
    quit_button(all);
    menu_mouse_tutorial(all, event);
    option_button(all);
    if (event.type == sfEvtMouseButtonPressed
    && sfMouse_isButtonPressed(sfMouseLeft))
        if (menuposx <= mvector.x && mvector.x <= menuposx
        + cross(360, all, 'w') && menuposy <= mvector.y
        && mvector.y <= menuposy + cross(120, all, 'h')) {
            play_clicksound(all);
            all->status = quit;
            sfRenderWindow_close(all->window);
        }
    menu_mouse_two(all, event);
    menu_mouse_option(all, event);
}