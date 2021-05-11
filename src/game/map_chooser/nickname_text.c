/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-diogo.faria-martins
** File description:
** nickname_text
*/

#include "defender.h"

void click_mapone_scale_event(all_t *all, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed && sfMouse_isButtonPressed
    (sfMouseLeft)){
        all->mapchooser->choice = 1;
        sfRectangleShape_setFillColor(all->mapchooser->one,
        all->mapchooser->green);
    }
    sfSprite_setScale(all->mapchooser[0].game_obj[1].sprite,
    (sfVector2f){cross(0.21, all, 'w'), cross(0.21, all, 'h')});
    sfRectangleShape_setScale(all->mapchooser->one, (sfVector2f)
    {cross(1.05, all, 'w'), cross(1.05, all, 'h')});
}

void init_sftext(all_t *all)
{
    all->mapchooser->nicktext = sfText_create();
    all->mapchooser->nickinput = sfText_create();
    all->mapchooser->nickfont = sfFont_createFromFile
    ("./asset/letters/FFF_Tusj.ttf");
    sfText_setCharacterSize(all->mapchooser->nicktext, cross(50, all, 'w'));
    sfText_setCharacterSize(all->mapchooser->nickinput, cross(50, all, 'w'));
    sfText_setFont(all->mapchooser->nicktext, all->mapchooser->nickfont);
    sfText_setFont(all->mapchooser->nickinput, all->mapchooser->nickfont);
    sfText_setColor(all->mapchooser->nicktext, sfBlack);
    sfText_setColor(all->mapchooser->nickinput, sfBlack);
    sfText_setPosition(all->mapchooser->nicktext, (sfVector2f){cross
    ((1920 / 2) - 395, all, 'w'), cross((1080 / 2) + 120, all, 'h')});
    sfText_setPosition(all->mapchooser->nickinput, (sfVector2f){
    cross((1920 / 2) - 270, all, 'w'), cross(((1080 / 2) + 122),
    all, 'h')});
    sfText_setString(all->mapchooser->nickinput, "Enter your Nickname...");
}

bool check_string_char(char *str, char c)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] != '\0' && str[i] != c)
            return (false);
    }
    return (true);
}

int get_player_nickname(all_t *all, sfEvent event)
{
    if (check_string_char(all->mapchooser->nickname, ' ') == true)
        all->mapchooser->enternick = true;
    if (event.key.code >= 97 && event.key.code <= 122 && all->mapchooser->index
    < 8) {
        all->mapchooser->nickname[all->mapchooser->index] = event.key.code;
        all->mapchooser->index++;
        all->mapchooser->enternick = false;
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyBackspace &&
    all->mapchooser->index >= 0) {
        if (all->mapchooser->index > 0) {
            all->mapchooser->nickname[all->mapchooser->index - 1] = ' ';
            all->mapchooser->index--;
        }
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEnter) {
        all->mapchooser->nick_status = false;
    }
    return (0);
}

void while_nick_status(all_t *all)
{
    if (all->mapchooser->nick_status == true) {
        sfRenderWindow_drawSprite(all->window,
        all->mapchooser[0].game_obj[0].sprite, NULL);
        if (all->mapchooser->enternick == true) {
            sfRenderWindow_drawText(all->window,
            all->mapchooser->nickinput, NULL);
        }
        sfText_setString(all->mapchooser->nicktext,
        all->mapchooser->nickname);
        sfRenderWindow_drawText(all->window,
        all->mapchooser->nicktext, NULL);
    }
}