/*
** EPITECH PROJECT, 2021
** defender
** File description:
** game over loop
*/

#include "defender.h"

void draw_gameover(all_t *all)
{
    for (int i = 0; i < 3; i++) {
        sfRenderWindow_drawSprite(all->window,
        all->gameover[0].game_obj[i].sprite, NULL);
    }
}

void handle_gameover_events(all_t *all)
{
    sfEvent event;
    sfVector2i mvector = sfMouse_getPositionRenderWindow(all->window);

    while (sfRenderWindow_pollEvent(all->window, &event)) {
        if (event.type == sfEvtKeyPressed) {
            all->status = quit_game;
            all->game->show_settings = false;
            sfMusic_destroy(all->gameover->gameover_sound);
        }
        menu_button_mouse(all, event, mvector);
        restart_button_mouse(all, event, mvector);
    }
}

void gameover_loop(all_t *all)
{
    create_gameover_sprites(all);
    while (all->status == game_over) {
        sfRenderWindow_clear(all->window, sfBlack);
        draw_game_map(all);
        get_path_pos(all);
        draw_game_ui(all);
        handle_gameover_events(all);
        draw_gameover(all);
        draw_final_score(all);
        draw_cursor(all);
        sfRenderWindow_display(all->window);
    }
    all->menu->highest_score = read_myfile_score
    ("src/game_over/score.txt", all, 0);
}