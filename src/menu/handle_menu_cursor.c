/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-diogo.faria-martins
** File description:
** handle_menu_cursor
*/

#include "defender.h"

void handle_cursor_hand_menu(all_t *all)
{
    sfVector2i mvector = sfMouse_getPositionRenderWindow(all->window);

    if (all->status == menu) {
        for (int i = 7; i <= 9; i++) {
            if (all->menu[0].settings[i].pos.x < mvector.x
            && all->menu[0].settings[i].pos.x +
            all->menu[0].settings[i].rect.width - 238 > mvector.x
            && all->menu[0].settings[i].rect.height + 120 < mvector.y
            && all->menu[0].settings[i].pos.y +
            all->menu[0].settings[i].rect.height - 81 > mvector.y) {
                sfSprite_setTextureRect(all->cursor[0].gcursor[0].sprite,
                (sfIntRect){60, 0, 30, 48});
            } else
                sfSprite_setTextureRect(all->cursor[0].gcursor[0].sprite,
                (sfIntRect){0, 0, 30, 48});
        }
    }
}

void handle_cursor_hand_option(all_t *all)
{
    sfVector2i mvector = sfMouse_getPositionRenderWindow(all->window);

    if (all->status == option) {
        for (int i = 1; i <= 3; i++) {
            if (cross(890, all, 'w') < mvector.x
            && cross(890 + 290, all, 'w') > mvector.x
            && all->menu[1].settings[i].pos.y < mvector.y + 22
            && all->menu[1].settings[i].pos.y +
            all->menu[1].settings[i].rect.height > mvector.y) {
                sfSprite_setTextureRect(all->cursor[0].gcursor[0].sprite,
                (sfIntRect){60, 0, 30, 48});
            } else {
                sfSprite_setTextureRect(all->cursor[0].gcursor[0].sprite,
                (sfIntRect){0, 0, 30, 48});
            }
        }
    }
}