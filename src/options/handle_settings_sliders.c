/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** handling settings buttons functions
*/

#include "defender.h"

void handle_slider_one(all_t *all)
{
    sfVector2i mvector = sfMouse_getPositionRenderWindow(all->window);
    float menuposx = cross(850, all, 'w');
    float menuposy = cross(280, all, 'h');

    if (sfMouse_isButtonPressed(sfMouseLeft) == true &&
    menuposx + cross(20, all, 'w') <= mvector.x
    && mvector.x <= menuposx + cross(320, all, 'w') && menuposy <= mvector.y
    && mvector.y <= menuposy + cross(45, all, 'h')) {
        mvector = sfMouse_getPositionRenderWindow(all->window);
        if (mvector.x  < menuposx + cross(720, all, 'w')
        && mvector.x > menuposx + cross(40, all, 'w') ) {
            play_clicksound(all);
            sfSprite_setPosition(all->menu[1].settings[1].sprite,
            (sfVector2f){mvector.x - 10, menuposy});
            all->menu->sfx_posx = mvector.x;
            all->menu->sfx_vol = calc_sfx(all);
            sfMusic_setVolume(all->click_sound, all->menu->sfx_vol);
        }
    }
}

void handle_slider_two(all_t *all)
{
    sfVector2i mvector = sfMouse_getPositionRenderWindow(all->window);
    float menupos_twox = cross(850, all, 'w');
    float menupos_twoy = cross(433, all, 'h');

    if (sfMouse_isButtonPressed(sfMouseLeft) == true && menupos_twox +
    cross(20, all, 'w') <= mvector.x && mvector.x
    <= menupos_twox + cross(320, all, 'w') && menupos_twoy <= mvector.y &&
    mvector.y <= menupos_twoy + cross(45, all, 'h')) {
        mvector = sfMouse_getPositionRenderWindow(all->window);
        if (mvector.x  < menupos_twox + cross(720, all, 'w')
        && mvector.x > menupos_twox + cross(40, all, 'w')) {
            play_clicksound(all);
            sfSprite_setPosition(all->menu[1].settings[2].sprite,
            (sfVector2f){mvector.x - 10, menupos_twoy});
            all->menu->music_posx = mvector.x;
            all->menu->mus_vol = calc_volume(all);
            sfMusic_setVolume(all->menu->menu_sound, all->menu->mus_vol);
        }
    }
}

void handle_slider_three(all_t *all)
{
    sfVector2i mvector = sfMouse_getPositionRenderWindow(all->window);
    float menupos_trex = cross(850, all, 'w');
    float menupos_trey = cross(589, all, 'h');

    if (sfMouse_isButtonPressed(sfMouseLeft) == true && menupos_trex +
    cross(20, all, 'w') <= mvector.x && mvector.x
    <= menupos_trex + cross(320, all, 'w') && menupos_trey <= mvector.y &&
    mvector.y <= menupos_trey + cross(45, all, 'h')) {
        mvector = sfMouse_getPositionRenderWindow(all->window);
        if (mvector.x  < menupos_trex + cross(720, all, 'w')
        && mvector.x > menupos_trex + cross(40, all, 'w')) {
            play_clicksound(all);
            sfSprite_setPosition(all->menu[1].settings[3].sprite,
            (sfVector2f){mvector.x - 10, menupos_trey});
            all->menu->fps_posx = mvector.x;
            all->menu->fps = calc_fps(all);
            sfRenderWindow_setFramerateLimit(all->window, all->menu->fps);
        }
    }
}