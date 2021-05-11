/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-diogo.faria-martins
** File description:
** handle_alarm_tower
*/

#include "defender.h"

void init_alarm_tower(all_t *all)
{
    all->game->grab_tower = true;
    all->game[3].tower[all->game->tower_nb - 1].price = 60;
    all->game[3].tower[all->game->tower_nb - 1].upgrade_status = 1;
    all->game[3].tower[all->game->tower_nb - 1].upgrade_price = 100;
    all->game[3].tower[all->game->tower_nb - 1].tower_type = SLOW;
    all->game[3].tower[all->game->tower_nb - 1].range = 180;
    all->game[3].tower[all->game->tower_nb - 1].damage = 5;
    all->game[3].tower[all->game->tower_nb - 1].total_cost = 60;
    all->game[3].tower[all->game->tower_nb - 1].attack_speed = 2.5;
}

void alarm_tower(all_t *all, sfEvent event)
{
    sfVector2i mvector = sfMouse_getPositionRenderWindow(all->window);
    float ice_butx = cross(1690, all, 'w');
    float ice_buty = cross(570, all, 'h');

    if (ice_butx <= mvector.x && mvector.x
    <= ice_butx + cross(215, all, 'w') && ice_buty
    <= mvector.y && mvector.y <= ice_buty + cross(72, all, 'h')) {
        if (event.type == sfEvtMouseButtonPressed && sfMouse_isButtonPressed
        (sfMouseLeft) && all->game->gold_coins >= 60) {
            all->game->tower_nb++;
            tower_object_t ice = {122, 0, {cross(0.78, all, 'w'),
            cross(0.78, all, 'h')}, 0, 0, 0, 0, 0, 0, 0, 0, {mvector.x,
            mvector.y}, 0, 0, {0, 40, 98, 133}, {0, {0}, 0}};
            init_tower_object(&ice, "asset/game/ice.png");
            all->game[3].tower[all->game->tower_nb - 1] = ice;
            init_alarm_tower(all);
        }
    }
}