/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** handling red towers
*/

#include "defender.h"

void init_red_tower(all_t *all)
{
    all->game->grab_tower = true;
    all->game[3].tower[all->game->tower_nb - 1].price = 70;
    all->game[3].tower[all->game->tower_nb - 1].upgrade_status = 1;
    all->game[3].tower[all->game->tower_nb - 1].upgrade_price = 80;
    all->game[3].tower[all->game->tower_nb - 1].tower_type = RED;
    all->game[3].tower[all->game->tower_nb - 1].range = 250;
    all->game[3].tower[all->game->tower_nb - 1].damage = 4;
    all->game[3].tower[all->game->tower_nb - 1].total_cost = 70;
    all->game[3].tower[all->game->tower_nb - 1].attack_speed = 0.40;
}

void red_tower(all_t *all, sfEvent event)
{
    sfVector2i mvector = sfMouse_getPositionRenderWindow(all->window);
    float redt_butx = cross(1690, all, 'w');
    float redt_buty = cross(310, all, 'h');

    if (redt_butx <= mvector.x && mvector.x
    <= redt_butx + cross(215, all, 'w') && redt_buty
    <= mvector.y && mvector.y <= redt_buty + cross(72, all, 'h')) {
        if (event.type == sfEvtMouseButtonPressed && sfMouse_isButtonPressed
        (sfMouseLeft) && all->game->gold_coins >= 70) {
            all->game->tower_nb++;
            tower_object_t red = {122, 0, {cross(0.6, all, 'w'), cross(0.6, all
            , 'h')}, 0, 0, 0, 0, 0, 0, 0, 0, {mvector.x, mvector.y}, 0, 0, {57,
            88, 130, 158}, {0, {0}, 0}};
            init_tower_object(&red, "asset/game/redtower(1).png");
            all->game[3].tower[all->game->tower_nb - 1] = red;
            init_red_tower(all);
        }
    }
}