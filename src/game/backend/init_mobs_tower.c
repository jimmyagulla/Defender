/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-diogo.faria-martins
** File description:
** create_gobj_game
*/

#include "defender.h"

void init_tower_object(tower_object_t *object, char *filepath)
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

void init_mobs_object(mobs_object_t *object, char *filepath)
{
    sfVector2u width_height = {0, 0};
    init_clock(&object->clock);
    init_clock(&object->speed_clock);
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