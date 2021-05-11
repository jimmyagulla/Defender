/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-diogo.faria-martins
** File description:
** tutorial_loop
*/

#include "defender.h"

int handle_tutorial_event(all_t *all)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(all->window, &event)) {
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
            all->status = menu;
        }
    }
    return (0);
}

void tutorial_loop(all_t *all)
{
    while (all->status == tutorial) {
        handle_tutorial_event(all);
        sfRenderWindow_clear(all->window, sfBlack);
        sfRenderWindow_drawSprite(all->window,
        all->menu[0].settings[11].sprite, NULL);
        sfRenderWindow_display(all->window);
    }
}