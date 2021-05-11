/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-diogo.faria-martins
** File description:
** handle_canon_tower
*/

#include "defender.h"

void init_canon_tower(all_t *all)
{
    all->game->grab_tower = true;
    all->game[3].tower[all->game->tower_nb - 1].price = 120;
    all->game[3].tower[all->game->tower_nb - 1].upgrade_status = 1;
    all->game[3].tower[all->game->tower_nb - 1].upgrade_price = 150;
    all->game[3].tower[all->game->tower_nb - 1].tower_type = CANON;
    all->game[3].tower[all->game->tower_nb - 1].range = 220;
    all->game[3].tower[all->game->tower_nb - 1].damage = 20;
    all->game[3].tower[all->game->tower_nb - 1].total_cost = 120;
    all->game[3].tower[all->game->tower_nb - 1].attack_speed = 3;
}

void canon_tower(all_t *all, sfEvent event)
{
    sfVector2i mvector = sfMouse_getPositionRenderWindow(all->window);
    float canon_butx = cross(1690, all, 'w');
    float canon_buty = cross(690, all, 'h');

    if (canon_butx <= mvector.x && mvector.x
    <= canon_butx + cross(215, all, 'w') && canon_buty
    <= mvector.y && mvector.y <= canon_buty + cross(72, all, 'h')) {
        if (event.type == sfEvtMouseButtonPressed && sfMouse_isButtonPressed
        (sfMouseLeft) && all->game->gold_coins >= 120) {
            all->game->tower_nb++;
            tower_object_t ice = {122, 0, {cross(1, all, 'w'),
            cross(1, all, 'h')}, 0, 0, 0, 0, 0, 0, 0, 0,
            {mvector.x, mvector.y},
            0, 0, {0, 30, 85, 91}, {0, {0}, 0}};
            init_tower_object(&ice, "asset/game/canon.png");
            all->game[3].tower[all->game->tower_nb - 1] = ice;
            init_canon_tower(all);
        }
    }
}