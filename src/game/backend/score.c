/*
** EPITECH PROJECT, 2021
** defender
** File description:
** score
*/

#include "defender.h"

void init_score_texts(all_t *all)
{
    all->game->score = sfText_create();
    all->game->scorenb = sfText_create();
    sfText_setString(all->game->score,
    my_strcat(all->mapchooser->nickname, "score : "));
    sfText_setFont(all->game->score, sfFont_createFromFile
    ("./asset/letters/FFF_Tusj.ttf"));
    sfText_setFont(all->game->scorenb, sfFont_createFromFile
    ("./asset/letters/FFF_Tusj.ttf"));
    sfText_setCharacterSize(all->game->score, cross(70, all, 'w'));
    sfText_setCharacterSize(all->game->scorenb, cross(70, all, 'w'));
    sfText_setPosition(all->game->score, (sfVector2f){cross(870, all, 'w'),
    cross(480, all, 'h')});
    sfText_setPosition(all->game->scorenb, (sfVector2f){cross(960, all, 'w'),
    cross(480, all, 'h')});
}

void draw_final_score(all_t *all)
{
    sfText_setCharacterSize(all->game->score, cross(50, all, 'w'));
    sfText_setCharacterSize(all->game->scorenb, cross(50, all, 'w'));
    sfText_setString(all->game->scorenb, my_itoa(all->game->score_nb - 10));
    sfText_setPosition(all->game->scorenb, (sfVector2f){cross(835, all, 'w'),
    cross(480, all, 'h')});
    sfText_setPosition(all->game->score, (sfVector2f){cross(680, all, 'w'),
    cross(420, all, 'h')});
    sfRenderWindow_drawText(all->window, all->game->score, NULL);
    sfRenderWindow_drawText(all->window, all->game->scorenb, NULL);
}

void draw_score(all_t *all)
{
    sfText_setCharacterSize(all->game->score, cross(70, all, 'w'));
    sfText_setString(all->game->scorenb, my_itoa(all->game->score_nb - 10));
    sfText_setPosition(all->game->score, (sfVector2f){cross(30, all, 'w'), 0});
    sfText_setPosition(all->game->scorenb,
    (sfVector2f){cross(620, all, 'w'), 0});
    sfText_setCharacterSize(all->game->score, cross(70, all, 'w'));
    sfRenderWindow_drawText(all->window, all->game->score, NULL);
    sfRenderWindow_drawText(all->window, all->game->scorenb, NULL);
}