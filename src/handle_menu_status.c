/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** handling menu of the game
*/

#include "defender.h"

void draw_menu(all_t *all)
{
    for (int i = 0; i <= 10; i++)
        sfRenderWindow_drawSprite(all->window,
        all->menu[0].settings[i].sprite, NULL);
    draw_cursor(all);
    draw_fps(all);
}

char *fill_nb_array(int y, char *str, char **array)
{
    int i = 0;

    for (int x = 0; array[y][x]; x++) {
        if (array[y][x] >= '0' && array[y][x] <= '9') {
            str[i] = array[y][x];
            i++;
        }
    }
    str[i] = '\0';
    return (str);
}

char *get_highest_score(all_t *all)
{
    char **array = my_str_to_word_array(all->menu->highest_score, ";");
    char *number = malloc(sizeof(char) * 10);
    int old_nb = 0;
    int line = 0;

    for (int y = 0; array[y] != NULL; y++) {
        number = fill_nb_array(y, number, array);
        if (my_getnbr(number) > old_nb) {
            old_nb = my_getnbr(number);
            for (int s = 0; number[s]; number[s++] = '\0');
            line = y;
        }
    }
    free(number);
    return (array[line]);
}

void create_highestscore_text(all_t *all, char *str)
{
    all->menu->highestscore = sfText_create();
    sfText_setString(all->menu->highestscore, str);
    sfText_setFont(all->menu->highestscore, sfFont_createFromFile
    ("./asset/letters/FFF_Tusj.ttf"));
    sfText_setFont(all->menu->highestscore, sfFont_createFromFile
    ("./asset/letters/FFF_Tusj.ttf"));
    sfText_setCharacterSize(all->menu->highestscore, cross(70, all, 'w'));
    sfText_setPosition(all->menu->highestscore, (sfVector2f){cross(0, all, 'w'),
    cross(0, all, 'h')});
}

void menu_loop(all_t *all)
{
    all->game->show_settings = false;
    all->pre_status = menu;
    all->menu->highest_score =
    read_myfile_score("src/game_over/score.txt", all, 1);
    get_highest_score(all);
    create_sprites_menu(all);
    create_highestscore_text(all, get_highest_score(all));
    while (all->status == menu) {
        assign_clock(all);
        my_clock(all);
        handle_menu_event(all);
        sfRenderWindow_clear(all->window, sfBlack);
        draw_menu(all);
        handle_cursor_hand_menu(all);
        sfRenderWindow_drawText(all->window, all->menu->highestscore, NULL);
        sfRenderWindow_display(all->window);
    }
}