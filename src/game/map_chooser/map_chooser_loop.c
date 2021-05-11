/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-diogo.faria-martins
** File description:
** map_chooser_loop
*/

#include "defender.h"

int handle_chooser_event_two(all_t *all, sfEvent event)
{
    if (all->mapchooser->nick_status == false &&
        all->mapchooser->choosedmap == true) {
        click_mapone_event(all, event);
        click_maptwo_event(all, event);
        click_mapthree_event(all, event);
        if (event.type == sfEvtKeyPressed &&
        event.key.code == sfKeyEnter
        && all->mapchooser->choice != 0)
            all->mapchooser->choosedmap = false;
        if (all->mapchooser->nick_status == false &&
        all->mapchooser->choosedmap == false) {
            if (event.type == sfEvtKeyPressed
            && event.key.code == sfKeyEnter
            && all->mapchooser->choice != 0)
                all->mapchooser->difficulty_map = true;
        }
    }
    return (0);
}

int handle_chooser_event(all_t *all)
{
    sfEvent event;
    if (all->fdp == true) {
        event.key.code = 95;
        all->fdp = false;
    }
    while (sfRenderWindow_pollEvent(all->window, &event)) {
        if (all->mapchooser->nick_status == true)
            return (get_player_nickname(all, event));
        if (all->mapchooser->difficulty_map == true) {
            click_difficultyl_event(all, event);
            click_difficultyr_event(all, event);
            if (event.type == sfEvtKeyPressed
            && event.key.code == sfKeyEnter) {
                return (-1);
            }
        }
        if (handle_chooser_event_two(all, event) == - 1)
            return (-1);
    }
    return (0);
}

void create_rectangle_shapes(all_t *all)
{
    all->mapchooser->one = sfRectangleShape_create();
    all->mapchooser->two = sfRectangleShape_create();
    all->mapchooser->three = sfRectangleShape_create();
    all->mapchooser->red = sfColor_fromRGBA(255, 0, 0, 255);
    all->mapchooser->green = sfColor_fromRGBA(0, 255, 0, 255);
    sfRectangleShape_setFillColor(all->mapchooser->one, all->mapchooser->red);
    sfRectangleShape_setFillColor(all->mapchooser->two, all->mapchooser->red);
    sfRectangleShape_setFillColor(all->mapchooser->three,
    all->mapchooser->red);
    sfRectangleShape_setPosition(all->mapchooser->one,
    (sfVector2f){cross(248, all, 'w'), cross(523, all, 'h')});
    sfRectangleShape_setPosition(all->mapchooser->two,
    (sfVector2f){cross(760, all, 'w'), cross(523, all, 'h')});
    sfRectangleShape_setPosition(all->mapchooser->three,
    (sfVector2f){cross(1272, all, 'w'), cross(523, all, 'h')});
    sfRectangleShape_setSize(all->mapchooser->one, (sfVector2f){401, 231});
    sfRectangleShape_setSize(all->mapchooser->two, (sfVector2f){401, 231});
    sfRectangleShape_setSize(all->mapchooser->three, (sfVector2f){401, 231});
}

void init_mapchooser_loop(all_t *all)
{
    create_mapchooser_sprites(all);
    all->mapchooser->nickname = malloc(sizeof(char) * 10);
    all->mapchooser->nickname[9] = '\0';
    for (int i = 0; i < 9; i++) {
        all->mapchooser->nickname[i] = ' ';
    }
    all->mapchooser->index = 0;
    all->mapchooser->nick_status = true;
    all->mapchooser->enternick = true;
    all->mapchooser->choosedmap = true;
    all->mapchooser->difficulty_map = false;
    all->mapchooser->choice = 0;
    all->fdp = true;
    all->game->difficulty = 1;
    init_sftext(all);
    init_sftext_difficulty(all);
}

void map_choser(all_t *all)
{
    init_mapchooser_loop(all);
    create_rectangle_shapes(all);
    while (all->status == game) {
        if (handle_chooser_event(all) == -1)
            return;
        sfRenderWindow_clear(all->window, sfBlack);
        while_nick_status(all);
        draw_mapchooser_sprites(all);
        if (all->mapchooser->difficulty_map == true) {
            sfText_setString(all->mapchooser->difficulty,
            my_itoa(all->game->difficulty));
            draw_difficulty(all);
            draw_cursor(all);
        }
        sfRenderWindow_display(all->window);
    }
}