/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-diogo.faria-martins
** File description:
** tutorial_events
*/

#include "defender.h"

void tutorial_button(all_t *all)
{
    int menuposx = cross(1820, all, 'w');
    int menuposy = cross(980, all, 'h');
    sfVector2i mvector = sfMouse_getPositionRenderWindow(all->window);

    if (menuposx <= mvector.x && mvector.x <= menuposx + cross(360, all, 'w')
    && menuposy <= mvector.y && mvector.y <= menuposy + cross(120, all, 'h')) {
            sfSprite_setPosition(all->menu[0].settings[10].sprite,
            (sfVector2f){cross(1820, all, 'w'), cross(980, all, 'h')});
            sfSprite_setScale(all->menu[0].settings[10].sprite,
            (sfVector2f){cross(0.7, all, 'w'), cross(0.7, all, 'h')});
    } else {
            sfSprite_setScale(all->menu[0].settings[10].sprite,
            (sfVector2f){cross(0.6, all, 'w'), cross(0.6, all, 'h')});
            sfSprite_setPosition(all->menu[0].settings[10].sprite,
            (sfVector2f){cross(1820, all, 'w'), cross(980, all, 'h')});
    }
}

void menu_mouse_tutorial(all_t *all, sfEvent event)
{
    int menuposx = cross(1820, all, 'w');
    int menuposy = cross(980, all, 'h');
    sfVector2i mvector = sfMouse_getPositionRenderWindow(all->window);

    tutorial_button(all);
    if (menuposx <= mvector.x && mvector.x <= menuposx + cross(360, all, 'w')
    && menuposy <= mvector.y && mvector.y <= menuposy + cross(120, all, 'h')
    && event.type == sfEvtMouseButtonPressed
    && sfMouse_isButtonPressed(sfMouseLeft)) {
        sfMusic_destroy(all->click_sound);
        all->click_sound =
        sfMusic_createFromFile("asset/menu/sounds/buttonclick.ogg");
        sfMusic_setVolume(all->click_sound, all->menu->sfx_vol);
        play_clicksound(all);
        all->status = tutorial;
        tutorial_loop(all);
    }
}