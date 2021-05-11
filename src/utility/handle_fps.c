/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** handle_fps
*/

#include "defender.h"

void fps_display(all_t *all)
{
    char *fps = "\tFPS:\n";
    all->fps_word = sfText_create();
    all->fps_nb = sfText_create();
    all->fps_font = sfFont_createFromFile
    ("./asset/letters/FFF_Tusj.ttf");
    sfText_setCharacterSize(all->fps_nb, cross(70, all, 'w'));
    sfText_setString(all->fps_word, fps);
    sfText_setFont(all->fps_nb, all->fps_font);
    sfText_setFont(all->fps_word, all->fps_font);
    sfText_setColor(all->fps_word, sfBlue);
    sfText_setColor(all->fps_nb, sfWhite);
    sfText_setPosition(all->fps_word,
    (sfVector2f){cross(20, all, 'w'), cross(50, all, 'h')});
    sfText_setPosition(all->fps_nb,
    (sfVector2f){cross(190, all, 'w'), cross(50, all, 'h')});
}

void health_display(all_t *all)
{
    all->game->health_nb = sfText_create();
    all->game->gold_nb = sfText_create();
    all->game->health_font = sfFont_createFromFile
    ("./asset/letters/FFF_Tusj.ttf");
    sfText_setCharacterSize(all->game->health_nb, cross(50, all, 'w'));
    sfText_setCharacterSize(all->game->gold_nb, cross(50, all, 'w'));
    sfText_setString(all->game->gold_nb, "100");
    sfText_setString(all->game->health_nb, "100");
    sfText_setFont(all->game->gold_nb, all->game->health_font);
    sfText_setFont(all->game->health_nb, all->game->health_font);
    sfText_setColor(all->game->health_nb, sfRed);
    sfText_setColor(all->game->gold_nb, sfYellow);
    sfText_setPosition(all->game->health_nb, (sfVector2f){cross(1770, all, 'w')
    , cross(125, all, 'h')});
    sfText_setPosition(all->game->gold_nb, (sfVector2f){cross(1770, all, 'w')
    , cross(27, all, 'h')});
}

void grab_fps(all_t *all)
{
    int fps = 0;
    float current_time = 0;

    current_time = sfTime_asSeconds(sfClock_restart(all->fps_clock));
    fps = 1.f / current_time;
    sfText_setColor(all->fps_word, sfWhite);
    sfText_setString(all->fps_nb , my_itoa(fps));
    sfText_setCharacterSize(all->fps_word, 40);
    sfText_setCharacterSize(all->fps_nb, 40);
    sfText_setPosition(all->fps_word, (sfVector2f){0, 100});
    sfText_setPosition(all->fps_nb, (sfVector2f){150, 100});
    sfRenderWindow_drawText(all->window, all->fps_word, NULL);
    sfRenderWindow_drawText(all->window, all->fps_nb, NULL);
}

void draw_fps(all_t *all)
{
    if (all->menu->fps_status == true)
        grab_fps(all);
}

void handle_fps_events(all_t *all, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyA)
        all->menu->fps_status = !all->menu->fps_status;
}