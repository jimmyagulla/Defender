/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** handle_options
*/

#include "defender.h"

int verify_pre_status(all_t *all)
{
    if (all->game->show_settings == true)
        return (-1);
    else
        all->status = all->pre_status;
    return (0);
}

int handle_resume_button(all_t *all, sfEvent event)
{
    sfVector2i mvector = sfMouse_getPositionRenderWindow(all->window);
    float return_butx = cross(155, all, 'w');
    float return_buty = cross(120, all, 'h');

    if (return_butx <= mvector.x && mvector.x <=
    return_butx + cross(215, all, 'w') && return_buty
    <= mvector.y && mvector.y <= return_buty +
    cross(72, all, 'h')) {
        if (event.type == sfEvtMouseButtonPressed &&
            sfMouse_isButtonPressed
            (sfMouseLeft)) {
            play_clicksound(all);
            return (verify_pre_status(all));
        }
    }
    return (0);
}

int option_mouse(all_t *all, sfEvent event)
{
    if (all->pre_status != game) {
        handle_button_one(all, event);
        handle_button_two(all, event);
        handle_button_three(all, event);
    }
    handle_slider_one(all);
    handle_slider_two(all);
    handle_slider_three(all);
    if (handle_resume_button(all, event) == -1) {
        all->status = game;
        return (-1);
    }
    return (0);
}

void draw_options_sprites(all_t *all)
{
    sfRenderWindow_drawSprite(all->window, all->menu[1]
    .settings[0].sprite, NULL);
    sfRenderWindow_drawSprite(all->window, all->menu[1]
    .settings[1].sprite, NULL);
    sfRenderWindow_drawSprite(all->window, all->menu[1]
    .settings[2].sprite, NULL);
    sfRenderWindow_drawSprite(all->window, all->menu[1]
    .settings[3].sprite, NULL);
    sfRenderWindow_drawSprite(all->window, all->menu[1]
    .settings[4].sprite, NULL);
    draw_cursor(all);
    draw_fps(all);
}

void option_loop(all_t *all)
{
    create_settings_sprites(all);
    all->menu->sfx_vol = calc_sfx(all);
    all->menu->mus_vol = calc_volume(all);
    all->menu->fps = calc_fps(all);
    play_clicksound(all);
    while (all->status == option) {
        sfRenderWindow_clear(all->window, sfBlack);
        sfMusic_setVolume(all->menu->menu_sound, all->menu->mus_vol);
        if (handle_menu_event(all) == -1)
            return;
        return_button_event(all);
        rezize_sprites(all);
        handle_cursor_hand_option(all);
        draw_options_sprites(all);
        sfRenderWindow_display(all->window);
    }
}