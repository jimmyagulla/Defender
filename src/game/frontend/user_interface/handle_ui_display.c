/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-diogo.faria-martins
** File description:
** handle_gold_display
*/

#include "defender.h"

void draw_game_ui(all_t *all)
{
    for (int i = 1; i <= 7; i++)
        sfRenderWindow_drawSprite(all->window, all->game[0].game_obj[i].sprite,
        NULL);
    if (all->game->show_settings == true) {
        for (int i = 0; i < 5; i++)
            sfRenderWindow_drawSprite(all->window,
            all->game[1].game_obj[i].sprite, NULL);
    }
    sfRenderWindow_drawText(all->window, all->game->tower_prices, NULL);
    draw_health(all);
    draw_gold(all);
    draw_fps(all);
}

void board_loop(all_t *all)
{
    handle_game_event(all);
    draw_game_map(all);
    get_path_pos(all);
    for (int i = 0; i <= all->game->tower_nb - 1; i++) {
        sfRenderWindow_drawSprite(all->window,
        all->game[3].tower[i].sprite, NULL);
    }
    draw_game_ui(all);
    draw_score(all);
    draw_cursor(all);
}

void draw_health(all_t *all)
{
    if (all->game->castle_health >= 0
    && all->game->clone_mb_reached != all->game->reached_castle) {
        all->game->total_rcastle += all->game->reached_castle -
        all->game->clone_mb_reached;
        all->game->clone_mb_reached = all->game->reached_castle;
        for (int i = 0; i < all->game->total_rcastle; all->game->castle_health
        = 100 - (all->game->total_rcastle * 10)) {
            sfText_setString(all->game->health_nb ,
            my_itoa(all->game->castle_health));
            sfRenderWindow_drawText(all->window, all->game->health_nb, NULL);
            i++;
        }
    } else if (all->game->castle_health <= 0) {
        sfText_setString(all->game->health_nb , "0");
        sfRenderWindow_drawText(all->window, all->game->health_nb, NULL);
        all->status = game_over;
    }
    sfRenderWindow_drawText(all->window, all->game->health_nb, NULL);
}

void draw_gold(all_t *all)
{
    if ((all->game->gold_coins >= 0) && (all->game->clone_death_counter !=
    all->game->death_counter || (all->game->gold_save !=
    all->game->gold_coins))) {
        if ((all->game->death_counter - all->game->clone_death_counter) * 20
        > 0)
            all->game->gold_coins += (all->game->death_counter -
            all->game->clone_death_counter) * 5;
        all->game->clone_death_counter = all->game->death_counter;
        all->game->gold_save = all->game->gold_coins;
        sfText_setString(all->game->gold_nb,
        my_itoa(all->game->gold_coins));
        sfRenderWindow_drawText(all->window, all->game->gold_nb, NULL);
    } else if (all->game->gold_coins < 0) {
        all->game->gold_coins = 0;
        sfText_setString(all->game->gold_nb , "0");
        sfRenderWindow_drawText(all->window, all->game->gold_nb, NULL);
    }
    sfText_setString(all->game->gold_nb, my_itoa(all->game->gold_coins));
    sfRenderWindow_drawText(all->window, all->game->gold_nb, NULL);
}