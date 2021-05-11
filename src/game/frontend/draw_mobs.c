/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** draw mobs
*/

#include "defender.h"

void get_path_pos(all_t *all)
{
    int total_death = 0;
    int reached_castle = 0;

    if (all->game->show_settings == false && all->status != game_over) {
        get_monsters_directions(all);
        handle_clock_monsters(all);
    }
    for (int i = 0; i < all->game->mb_counter; i++) {
        if (all->game[2].mobs[i].health <= 0) {
            total_death += 1;
        }
        draw_mobs(all, i);
        if (all->game[2].mobs[i].reached_castle == true) {
            reached_castle += 1;
        }
    }
    if (total_death > all->game->death_counter)
        all->game->score_nb += total_death - all->game->death_counter;
    all->game->reached_castle = reached_castle;
    all->game->death_counter = total_death;
}

void health_bars_display(all_t *all, int id)
{
    sfRenderWindow_drawSprite(all->window,
    all->game[4].game_obj[id + all->game->mb_counter].sprite, NULL);
    sfRenderWindow_drawSprite(all->window,
    all->game[4].game_obj[id].sprite, NULL);
}

void draw_mobs(all_t *all, int i)
{
    if (all->game[2].mobs[i].health > 0) {
        sfSprite_setTextureRect(all->game[4].game_obj[i +
        all->game->mb_counter].sprite, (sfIntRect){100, 0,
        get_mobs_lifebarlen(all->game[2].mobs[i],
        all->game->og_life_width, all), 82});
        if (all->game->show_settings == false) {
            sfSprite_setPosition(all->game[4].game_obj[i].sprite,
            (sfVector2f){cross(all->game[2].mobs[i].pos.x * 17.39 + 8, all,
            'w')
            , cross(all->game[2].mobs[i].pos.y * 27.87 + 10, all , 'h')});
            sfSprite_setPosition(all->game[4].game_obj[i +
            all->game->mb_counter].sprite, (sfVector2f)
            {cross(all->game[2].mobs[i].pos.x * 17.39 + 25.5, all, 'w'),
            cross(all->game[2].mobs[i].pos.y * 27.87 + 14, all, 'h')});
        }
        sfRenderWindow_drawSprite(all->window, all->game[2].mobs[i].sprite,
        NULL);
        health_bars_display(all, i);
    }
}