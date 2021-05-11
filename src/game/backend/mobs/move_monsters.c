/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** move_monsters
*/

#include "defender.h"

void monster_rect(all_t *all, int left, int width, int id)
{
    all->game[2].mobs[id].clock.time =
    sfClock_getElapsedTime(all->game[2].mobs[id].clock.clock);
    all->game[2].mobs[id].clock.seconds =
    all->game[2].mobs[id].clock.time.microseconds / 1000000.0;
    if (all->game[2].mobs[id].clock.seconds > 0.01 /
    (all->game->game_speed + 0.5)) {
        if (all->game[2].mobs[id].rect.left == left + 2 * width)
            all->game[2].mobs[id].rect.left = left;
        else if (all->game[2].mobs[id].rect.left == left + width)
            all->game[2].mobs[id].rect.left = left + 2 * width;
        else
            all->game[2].mobs[id].rect.left = left + width;
        sfSprite_setTextureRect(all->game[2].mobs[id].sprite,
        all->game[2].mobs[id].rect);
        sfClock_restart(all->game[2].mobs[id].clock.clock);
        all->game[2].mobs[id].clock.seconds = 0;
    }
}

void move_monsters_two(all_t *all, int id)
{
    all->game[2].mobs[id].slow = 0;
    if (all->game[2].mobs[id].karim == UP) {
        sfSprite_setPosition(all->game[2].mobs[id].sprite, (sfVector2f){
        cross(all->game[2].mobs[id].pos.x * 17.39, all, 'w'), cross((
        all->game[2].mobs[id].pos.y + 1) * 27.87, all, 'h')});
        all->game[2].mobs[id].pos.y -= 1;
        monster_rect(all, 192, 32, id);
    }
    if (all->game[2].mobs[id].karim == RIGHT) {
        sfSprite_setPosition(all->game[2].mobs[id].sprite, (sfVector2f){
        cross(all->game[2].mobs[id].pos.x * 17.39, all, 'w'), cross((
        all->game[2].mobs[id].pos.y + 1) * 27.87, all, 'h')});
        all->game[2].mobs[id].pos.x += 1;
        monster_rect(all, 96, 32, id);
    }
}

void move_monsters_one(all_t *all, int id)
{
    all->game[2].mobs[id].slow = 0;
    if (all->game[2].mobs[id].karim == DOWN) {
        sfSprite_setPosition(all->game[2].mobs[id].sprite, (sfVector2f){
        cross(all->game[2].mobs[id].pos.x * 17.39, all, 'w'), cross((
        all->game[2].mobs[id].pos.y + 1) * 27.87, all, 'h')});
        all->game[2].mobs[id].pos.y += 1;
        monster_rect(all, 0, 32, id);
    }
    if (all->game[2].mobs[id].karim == LEFT) {
        sfSprite_setPosition(all->game[2].mobs[id].sprite, (sfVector2f){
        cross(all->game[2].mobs[id].pos.x * 17.39, all, 'w'), cross((
        all->game[2].mobs[id].pos.y + 1) * 27.87, all, 'h')});
        all->game[2].mobs[id].pos.x -= 1;
        monster_rect(all, 288, 32, id);
    }
    move_monsters_two(all, id);
}

void handle_clock_monsters(all_t *all)
{
    float dif = 0;

    for (int i = 0; i < all->game->mb_counter; i++) {
        all->game[2].mobs[i].speed_clock.time = sfClock_getElapsedTime
        (all->game[2].mobs[i].speed_clock.clock);
        all->game[2].mobs[i].speed_clock.seconds =
        all->game[2].mobs[i].speed_clock.time.microseconds / 1000000.0;
        dif = 0;
        if (all->game->starting_onthefloor < 50) {
            dif = 0.01 * i + 0.01;
        }
        if (all->game[2].mobs[i].speed_clock.seconds > ((0.20 + dif)) /
        (all->game->game_speed + 0.5) + all->game[2].mobs[i].slow &&
        all->game[2].mobs[i].health > 0) {
            move_monsters_one(all, i);
            all->game->starting_onthefloor++;
            sfClock_restart(all->game[2].mobs[i].speed_clock.clock);
            all->game[2].mobs[i].speed_clock.seconds = 0;
        }
    }
}