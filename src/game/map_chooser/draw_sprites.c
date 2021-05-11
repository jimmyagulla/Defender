/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-diogo.faria-martins
** File description:
** draw_sprites
*/

#include "defender.h"

void draw_mapchooser_sprites(all_t *all)
{
    if (all->mapchooser->nick_status == false &&
    all->mapchooser->choosedmap == true) {
        sfRenderWindow_drawSprite(all->window,
        all->mapchooser[0].game_obj[4].sprite, NULL);
        sfRenderWindow_drawRectangleShape(all->window,
        all->mapchooser->one, NULL);
        sfRenderWindow_drawRectangleShape(all->window,
        all->mapchooser->two, NULL);
        sfRenderWindow_drawRectangleShape(all->window,
        all->mapchooser->three, NULL);
        sfRenderWindow_drawSprite(all->window,
        all->mapchooser[0].game_obj[1].sprite, NULL);
        sfRenderWindow_drawSprite(all->window,
        all->mapchooser[0].game_obj[2].sprite, NULL);
        sfRenderWindow_drawSprite(all->window,
        all->mapchooser[0].game_obj[3].sprite, NULL);
        draw_cursor(all);
    }
}

void draw_difficulty(all_t *all)
{
    for (int i = 4; i <= 6; i++) {
        sfRenderWindow_drawSprite(all->window,
        all->mapchooser[0].game_obj[i].sprite, NULL);
    }
    sfRenderWindow_drawText(all->window,
    all->mapchooser->difficulty, NULL);
    sfRenderWindow_drawText(all->window, all->mapchooser->diff_txt, NULL);
}
