/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** init variables
*/

#include "defender.h"

void init_values_two(all_t *all)
{
    all->game->once = true;
    all->game->og_life_width = 1149;
    all->game->game_speed = 1;
    all->game->tower_id = -1;
    all->game->draw_mb = true;
    all->game->wavefinished = false;
    all->game->spawn_mb = true;
    all->game->startwave = false;
    all->game->display_upgrd = false;
    all->game->grab_tower = false;
    all->game->show_settings = false;
    all->game->score_nb = 0;
    all->game->score = sfText_create();
    sfText_setFont(all->game->score, sfFont_createFromFile
    ("./asset/letters/FFF_Tusj.ttf"));
    sfText_setCharacterSize(all->game->score, 32);
    sfText_setString(all->game->score , "Score : ");
}

void init_values(all_t *all)
{
    all->game->difficulty = 1;
    all->game->wave = 1;
    all->game->tower_nb = 0;
    all->game->reached_castle = 0;
    all->game->total_rcastle = 0;
    all->game->mb_counter = 0;
    all->game->map_lines = 0;
    all->game->map_cols = 0;
    all->game->death_counter = 0;
    all->game->castle_health = 100;
    all->game->gold_save = 10002;
    all->game->gold_coins = 90;
    all->pre_status = game;
    all->game->clone_death_counter = 0;
    all->game->clone_mb_reached = 0;
    all->game->starting_onthefloor = 0;
    init_values_two(all);
}

void init_game_hehe(all_t *all)
{
    all->mapchooser->index = 0;
    map_choser(all);
    init_values(all);
    create_game_sprites(all);
    draw_map(all);
    loop_map(all);
    map_size(all);
    init_score_texts(all);
    health_display(all);
    all->game->circle_range = sfCircleShape_create();
    all->game->castle_health = 100;
    sfColor color =  sfColor_fromRGBA(168, 168, 168, 120);
    sfCircleShape_setOrigin(all->game->circle_range,
    (sfVector2f){cross(3000, all, 'w'), cross(3000, all, 'h')});
    sfCircleShape_setRadius(all->game->circle_range, cross(1, all, 'w'));
    sfCircleShape_setFillColor(all->game->circle_range, color);
    sfCircleShape_setOutlineThickness(all->game->circle_range,
    cross(4, all, 'w'));
    sfCircleShape_setOutlineColor(all->game->circle_range, sfBlack);
}