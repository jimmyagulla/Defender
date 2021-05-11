/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** window utilities
*/

#include "defender.h"

float cross(float value, all_t *all, char option)
{
    if (option == 'h')
        return (value * all->height / 1080);
    if (option == 'w')
        return (value * all->width / 1920);
    return (0);
}

sfRenderWindow *create_window(all_t *all, int width,
int height, sfUint32 style)
{
    if (style == sfFullscreen) {
        all->window = sfRenderWindow_create(*sfVideoMode_getFullscreenModes(0)
        , "First try", style, NULL);
        sfRenderWindow_setFramerateLimit(all->window, 30);
        return (all->window);
    }
    sfVideoMode mode = {width, height, 32};
    all->window = sfRenderWindow_create(mode, "Defender", style,
    NULL);
    sfRenderWindow_setFramerateLimit(all->window, 30);
    return (all->window);
}