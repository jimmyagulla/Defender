/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** menu_clocks
*/

#include "defender.h"

void assign_clock_two(all_t *all)
{
    all->menu[0].settings[4].clock.seconds =
    all->menu[0].settings[4].clock.time.microseconds  / 1000000.0;
    all->menu[0].settings[5].clock.time = sfClock_getElapsedTime(all->menu
    [0].settings[5].clock.clock);
    all->menu[0].settings[5].clock.seconds =
    all->menu[0].settings[5].clock.time.microseconds  / 1000000.0;
    all->menu[0].settings[6].clock.time = sfClock_getElapsedTime(all->menu
    [0].settings[6].clock.clock);
    all->menu[0].settings[6].clock.seconds =
    all->menu[0].settings[6].clock.time.microseconds  / 1000000.0;
}

void assign_clock(all_t *all)
{
    all->menu[0].settings[1].clock.time = sfClock_getElapsedTime(all->menu
    [0].settings[1].clock.clock);
    all->menu[0].settings[1].clock.seconds =
    all->menu[0].settings[1].clock.time.microseconds / 1000000.0;
    all->menu[0].settings[2].clock.time = sfClock_getElapsedTime(all->menu
    [0].settings[2].clock.clock);
    all->menu[0].settings[2].clock.seconds =
    all->menu[0].settings[2].clock.time.microseconds  / 1000000.0;
    all->menu[0].settings[3].clock.time = sfClock_getElapsedTime(all->menu
    [0].settings[3].clock.clock);
    all->menu[0].settings[3].clock.seconds =
    all->menu[0].settings[3].clock.time.microseconds  / 1000000.0;
    all->menu[0].settings[4].clock.time =
    sfClock_getElapsedTime(all->menu[0].settings[4].clock.clock);
    assign_clock_two(all);
}