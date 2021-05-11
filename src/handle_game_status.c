/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** handle_game_status
*/

#include "defender.h"

void show_settings(all_t *all, sfEvent event)
{
    if (all->game->show_settings == true) {
        play_clicksound(all);
        resume_button(all, event);
        quit_gbutton(all, event);
        menu_button(all, event);
        option_gbutton(all, event);
    }
}

void handle_escape_key(all_t *all, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
        all->game->show_settings = !all->game->show_settings;
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace) {
        all->game->game_speed = (all->game->game_speed == 1) ? 2 : 1;
    }
}

void draw_game_map(all_t *all)
{
    sfRenderWindow_drawSprite(all->window, all->game[0].game_obj[0].sprite,
    NULL);
    if (all->game->death_counter + all->game->reached_castle ==
    all->game->mb_counter && all->game->wavefinished == false) {
        all->game->score_nb += 10;
        all->game->gold_coins += 10;
        all->game->wavefinished = true;
    }
}

void show_settings_hehe(all_t *all)
{
    if (all->game->show_settings == true) {
        board_loop(all);
    }
}

void game_loop(all_t *all)
{
    init_game_hehe(all);
    sfVector2i mvector;
    while (all->status == game) {
        handle_game_event(all);
        sfRenderWindow_clear(all->window, sfBlack);
        show_settings_hehe(all);
        if (all->game->show_settings == false) {
            draw_game_map(all);
            start_wave(all);
            display_upgrade(all);
            mvector = sfMouse_getPositionRenderWindow(all->window);
            set_tower_positions(all, mvector);
            draw_game_ui(all);
            draw_score(all);
            display_tower_upgrd_window(all);
            draw_cursor(all);
        }
        sfRenderWindow_display(all->window);
    }
}