/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** game_object
*/

#include "defender.h"

void init_clock(myclock_t *clock)
{
    clock->clock = sfClock_create();
    clock->time = sfClock_getElapsedTime(clock->clock);
}

void init_game_object(game_object_t *object, char *filepath)
{
    sfVector2u width_height = {0, 0};

    init_clock(&object->clock);
    object->texture = sfTexture_createFromFile(filepath, NULL);
    object->sprite = sfSprite_create();
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    object->width = width_height.x;
    object->height = width_height.y;
    object->rect.left = (object->rect.left == 0) ? 0 : object->rect.left;
    object->rect.top = (object->rect.top == 0) ? 0 : object->rect.top;
    sfSprite_setScale(object->sprite, object->scale);
    sfSprite_setPosition(object->sprite, object->pos);
    sfSprite_setTextureRect(object->sprite, object->rect);
}