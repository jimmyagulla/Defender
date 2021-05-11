/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** create_options
*/

#include "defender.h"

int calc_volume(all_t *all)
{
    sfVector2f sprite_pos =
    sfSprite_getPosition(all->menu[1].settings[2].sprite);
    int value_two = (cross(1181, all, 'w') - cross(882, all, 'w'));
    int value_one = (cross(1181, all, 'w') - sprite_pos.x - value_two);
    int ret = 0;
    all->menu->music_posx = cross(sprite_pos.x, all, 'w');

    if (value_one < 0)
        value_one = value_one * -1;
    ret = value_one * 100 / value_two;
    if (ret > 80)
        ret = 80;
    if (ret < 5)
        ret = 0;
    return (ret);
}

int calc_sfx(all_t *all)
{
    sfVector2f sprite_pos =
    sfSprite_getPosition(all->menu[1].settings[1].sprite);
    int value_two = (cross(1181, all, 'w') - cross(902, all, 'w'));
    int value_one = (cross(1181, all, 'w') - sprite_pos.x - value_two);
    int ret = 0;
    all->menu->sfx_posx = cross(sprite_pos.x, all, 'w');

    if (value_one < 0)
        value_one = value_one * -1;
    ret = value_one * 100 / value_two;
    if (ret > 80)
        ret = 80;
    if (ret < 5)
        ret = 0;
    return (ret);
}

int calc_fps(all_t *all)
{
    sfVector2f sprite_pos =
    sfSprite_getPosition(all->menu[1].settings[3].sprite);
    int value_two = (cross(1181, all, 'w') - cross(902, all, 'w'));
    int value_one = (cross(1181, all, 'w') - sprite_pos.x - value_two);
    int ret = 0;
    all->menu->fps_posx = cross(sprite_pos.x, all, 'w');

    if (value_one < 0)
        value_one = value_one * -1;
    ret = value_one * 100 / value_two;
    if (ret > 100)
        ret = 100;
    if (ret < 5)
        ret = 0;
    return (ret + 30);
}

void play_clicksound(all_t *all)
{
    sfMusic_destroy(all->click_sound);
    all->click_sound =
    sfMusic_createFromFile("asset/menu/sounds/buttonclick.ogg");
    sfMusic_setVolume(all->click_sound, all->menu->sfx_vol);
    sfMusic_play(all->click_sound);
}