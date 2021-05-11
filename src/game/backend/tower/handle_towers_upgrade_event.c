/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-diogo.faria-martins
** File description:
** handle_towers_upgrade
*/

#include "defender.h"

void handle_upgrades_evt_two(all_t *all, float button_upx,
float button_upy, sfVector2i mvector)
{
    if (button_upx <= mvector.x
    && mvector.x <= button_upx + cross(211, all, 'w') && button_upy
    <= mvector.y && mvector.y <= button_upy + cross(62, all, 'h') &&
    all->game->gold_coins >=
    all->game[3].tower[all->game->tower_id].upgrade_price) {
        all->game->display_upgrd = true;
        if (all->game[3].tower[all->game->tower_id].upgrade_status < 3) {
            all->game[3].tower[all->game->tower_id].upgrade_status += 1;
            all->game->gold_coins -=
            all->game[3].tower[all->game->tower_id].upgrade_price;
            change_tower_rect(all);
        }
    }
}

int handle_upgrades_event(all_t *all, sfEvent event)
{
    float button_onex = cross(1387, all, 'w');
    float button_oney = cross(0, all, 'h');
    float button_upx = cross(1417, all, 'w');
    float button_upy = cross(360, all, 'h');
    sfVector2i mvector = sfMouse_getPositionRenderWindow(all->window);

    if (event.type == sfEvtMouseButtonPressed && sfMouse_isButtonPressed
    (sfMouseLeft)) {
        if (button_onex <= mvector.x
        && mvector.x <= button_onex + cross(276, all, 'w') && button_oney
        <= mvector.y && mvector.y <= button_oney + cross(451, all, 'h')) {
            all->game->display_upgrd = true;
            handle_upgrades_evt_two(all, button_upx, button_upy, mvector);
            return (1);
        }
    }
    return (-1);
}