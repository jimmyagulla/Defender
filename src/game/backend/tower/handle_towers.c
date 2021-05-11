/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** handle towers
*/

#include "defender.h"

bool handle_tower_upgrades(all_t *all)
{
    sfVector2i mvector = sfMouse_getPositionRenderWindow(all->window);

    for (int i = 0; i < all->game->tower_nb; i++) {
        if (mvector.x >= all->game[3].tower[i].pos.x &&
        mvector.x <= all->game[3].tower[i].pos.x + cross
        (100, all, 'w') && all->game[3].tower[i].pos.y  <=
        mvector.y - 5 && mvector.y <= all->game[3].tower[i].pos.y
        + cross(100, all, 'h')) {
            all->game->tower_id = i;
            return (true);
        }
    }
    return (false);
}

void set_tower_positions(all_t *all, sfVector2i mvector)
{
    for (int i = 0; i <= all->game->tower_nb - 1; i++) {
        if (i == all->game->tower_nb - 1 && all->game->grab_tower == true) {
            draw_tower_range(all, all->game[3].tower[i], mvector);
            sfSprite_setPosition(all->game[3].tower[i].sprite,
            (sfVector2f){mvector.x - cross(30, all, 'w'),
            mvector.y - cross(20, all, 'h')});
        }
        sfRenderWindow_drawSprite(all->window,
        all->game[3].tower[i].sprite, NULL);
    }
}

void handle_towers(all_t *all, sfEvent event, sfVector2i mvector)
{
    red_tower(all, event);
    canon_tower(all, event);
    alarm_tower(all, event);
    archer_tower(all, event);
    handle_towers_placements(all, mvector);
    if (sfMouse_isButtonPressed(sfMouseLeft) == true && event.type
    == sfEvtMouseButtonPressed && sfMouse_isButtonPressed
    (sfMouseLeft)) {
        if (all->game->display_upgrd == true &&
        handle_upgrades_event(all, event) == 1)
            return;
        all->game->display_upgrd = handle_tower_upgrades(all);
    }
}