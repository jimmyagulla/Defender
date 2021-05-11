/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** initialize variables for the game
*/

#include "defender.h"

void init_var(all_t *all)
{
    create_window(all, 1920, 1080, sfFullscreen);
    all->status = menu;
    all->menu->fps_status = false;
    all->resize_status = resize;
    all->width = 1920;
    all->height = 1080;
    all->menu->fps_posx = 900;
    all->menu->music_posx = 1000;
    all->menu->sfx_posx = 1000;
    all->menu->sfx_vol = 5;
    all->menu->mus_vol = 2;
    all->game->show_settings = false;
}