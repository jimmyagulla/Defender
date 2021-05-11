/*
** EPITECH PROJECT, 2021
** defender
** File description:
** clocks handling
*/

#include "defender.h"

void my_clock_three(all_t *all)
{
    if (all->menu[0].settings[5].clock.seconds > 0.05) {
        all->menu[0].settings[5].rect.left += 1;
        sfSprite_setTextureRect(all->menu[0].settings[5].sprite,
        all->menu[0].settings[5].rect);
        sfClock_restart(all->menu[0].settings[5].clock.clock);
        all->menu[0].settings[5].clock.seconds = 0;
    }
    if (all->menu[0].settings[6].clock.seconds > 0.02) {
        all->menu[0].settings[6].rect.left += 1;
        sfSprite_setTextureRect(all->menu[0].settings[6].sprite,
        all->menu[0].settings[6].rect);
        sfClock_restart(all->menu[0].settings[6].clock.clock);
        all->menu[0].settings[6].clock.seconds = 0;
    }
}

void my_clock_two(all_t *all)
{
    if (all->menu[0].settings[3].clock.seconds > 0.2) {
        all->menu[0].settings[3].rect.left += 1;
        sfSprite_setTextureRect(all->menu[0].settings[3].sprite,
        all->menu[0].settings[3].rect);
        sfClock_restart(all->menu[0].settings[3].clock.clock);
        all->menu[0].settings[3].clock.seconds = 0;
    }
    if (all->menu[0].settings[4].clock.seconds > 0.1) {
        all->menu[0].settings[4].rect.left += 1;
        sfSprite_setTextureRect(all->menu[0].settings[4].sprite,
        all->menu[0].settings[4].rect);
        sfClock_restart(all->menu[0].settings[4].clock.clock);
        all->menu[0].settings[4].clock.seconds = 0;
    }
    my_clock_three(all);
}

void my_clock(all_t *all)
{
    if (all->menu[0].settings[1].clock.seconds > 0.4) {
        all->menu[0].settings[1].rect.left += 1;
        sfSprite_setTextureRect(all->menu[0].settings[1].sprite,
        all->menu[0].settings[1].rect);
        sfClock_restart(all->menu[0].settings[1].clock.clock);
        all->menu[0].settings[1].clock.seconds = 0;
    }
    if (all->menu[0].settings[2].clock.seconds > 0.9) {
        all->menu[0].settings[2].rect.left += 1;
        sfSprite_setTextureRect(all->menu[0].settings[2].sprite,
        all->menu[0].settings[2].rect);
        sfClock_restart(all->menu[0].settings[2].clock.clock);
        all->menu[0].settings[2].clock.seconds = 0;
    }
    my_clock_two(all);
}