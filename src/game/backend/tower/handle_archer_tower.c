/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-diogo.faria-martins
** File description:
** handle_archer_tower
*/

#include "defender.h"

void init_archer_tower(all_t *all)
{
    all->game->grab_tower = true;
    all->game[3].tower[all->game->tower_nb - 1].price = 40;
    all->game[3].tower[all->game->tower_nb - 1].upgrade_status = 1;
    all->game[3].tower[all->game->tower_nb - 1].upgrade_price = 50;
    all->game[3].tower[all->game->tower_nb - 1].tower_type = ARCHER;
    all->game[3].tower[all->game->tower_nb - 1].range = 300;
    all->game[3].tower[all->game->tower_nb - 1].damage = 4;
    all->game[3].tower[all->game->tower_nb - 1].total_cost = 40;
    all->game[3].tower[all->game->tower_nb - 1].attack_speed = 0.35;
}

void archer_tower(all_t *all, sfEvent event)
{
    sfVector2i mvector = sfMouse_getPositionRenderWindow(all->window);
    float archert_butx = cross(1690, all, 'w');
    float archert_buty = cross(440, all, 'h');

    if (archert_butx <= mvector.x && mvector.x
    <= archert_butx + cross(215, all, 'w') && archert_buty
    <= mvector.y && mvector.y <= archert_buty + cross(72, all, 'h')) {
        if (event.type == sfEvtMouseButtonPressed && sfMouse_isButtonPressed
        (sfMouseLeft) && all->game->gold_coins >= 40) {
            all->game->tower_nb++;
            tower_object_t archer = {122, 0, {cross(0.6, all, 'w'),
            cross(0.6, all, 'h')}, 0, 0, 0, 0, 0, 0, 0, 0, {mvector.x,
            mvector.y}, 0, 0, {88, 129, 141, 180}, {0, {0}, 0}};
            init_tower_object(&archer, "asset/game/archer.png");
            all->game[3].tower[all->game->tower_nb - 1] = archer;
            init_archer_tower(all);
        }
    }
}