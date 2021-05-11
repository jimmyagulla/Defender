/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** handle_events
*/

#include "defender.h"

void handle_game_event(all_t *all)
{
    sfEvent event;
    sfVector2i mvector = sfMouse_getPositionRenderWindow(all->window);

    if (all->game->once == true) {
        all->game[3].tower = malloc(sizeof(game_object_t) * 1000);
        all->game->once = false;
    }
    while (sfRenderWindow_pollEvent(all->window, &event)) {
        handle_escape_key(all, event);
        show_settings(all, event);
        handle_fps_events(all, event);
        if (all->game->show_settings == false) {
            handle_towers(all, event, mvector);
            accelerate_button_mouse(all, event, mvector);
            play_button_mouse(all, event, mvector);
        }
    }
}

int handle_menu_event(all_t *all)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(all->window, &event)) {
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
            all->status = quit;
            sfRenderWindow_close(all->window);
        }
        handle_fps_events(all, event);
        if (all->status == menu)
            menu_mouse(all, event);
        if (all->status == option)
            if (option_mouse(all, event) == -1)
                return (-1);
    }
    return (0);
}