/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** menu_parallax
*/

#include "defender.h"

void repeat_textures_menu(all_t *all)
{
    sfTexture_setRepeated(all->menu[0].settings[0].texture, sfTrue);
    sfTexture_setRepeated(all->menu[0].settings[1].texture, sfTrue);
    sfTexture_setRepeated(all->menu[0].settings[2].texture, sfTrue);
    sfTexture_setRepeated(all->menu[0].settings[3].texture, sfTrue);
    sfTexture_setRepeated(all->menu[0].settings[4].texture, sfTrue);
    sfTexture_setRepeated(all->menu[0].settings[5].texture, sfTrue);
    sfTexture_setRepeated(all->menu[0].settings[6].texture, sfTrue);
}

void create_sprites_menu_buttons(all_t *all)
{
    game_object_t start = {0, 0, {cross(0.6, all, 'w'), cross(0.6, all, 'h')},
    0, {cross(760, all, 'w'), cross(315, all, 'h')}, 0, 0, {0, 0, 600, 200}, {0
    , {0}, 0}};
    game_object_t settings = {0, 0, {cross(0.6, all, 'w'), cross(0.6, all, 'h')
    }, 0, {cross(760, all, 'w'), cross(465, all, 'h')}, 0, 0, {0, 0, 600, 200},
    {0, {0}, 0}};
    game_object_t quit = {0, 0, {cross(0.6, all, 'w'), cross(0.6, all, 'h')}, 0
    , {cross(760, all, 'w'), cross(620, all, 'h')}, 0, 0, {0, 0, 600, 200}, {0,
    {0}, 0}};
    init_game_object(&start, "asset/menu/buttons/start_button.png");
    init_game_object(&settings, "asset/menu/buttons/Settings Button.png");
    init_game_object(&quit, "asset/menu/buttons/Quit Button.png");
    all->menu[0].settings[7] = start;
    all->menu[0].settings[8] = settings;
    all->menu[0].settings[9] = quit;
}

void create_sprites_menu_parallax_two(all_t *all)
{
    game_object_t hills = {0, 0, {cross(1, all, 'w'), cross(1, all, 'h')}, 0,
    {cross(0, all, 'w'), cross(0, all, 'h')}, 0, 0, {0, 0, 1980, 1080}, {0,
    {0}, 0}};
    game_object_t background = {0, 0, {cross(1, all, 'w'), cross(1, all, 'h')},
    0, {cross(0, all, 'w'), cross(0, all, 'h')}, 0, 0, {0, 0, 1980, 1080}, {0,
    {0}, 0}};
    game_object_t rocks = {0, 0, {cross(1, all, 'w'), cross(1, all, 'h')}, 0,
    {cross(0, all, 'w'), cross(0, all, 'h')}, 0, 0, {0, 0, 1980, 1080}, {0, {0}
    , 0}};
    init_game_object(&rocks, "asset/menu/backgrounds/rocks.png");
    init_game_object(&hills, "asset/menu/backgrounds/hills.png");
    init_game_object(&background, "asset/menu/backgrounds/bg_rocks.png");
    all->menu[0].settings[3] = hills;
    all->menu[0].settings[2] = background;
    all->menu[0].settings[5] = rocks;
}

void create_sprites_menu_parallax(all_t *all)
{
    game_object_t ground = {0, 0, {cross(1, all, 'w'), cross(1, all, 'h')}, 0,
    {cross(0, all, 'w'), cross(0, all, 'h')}, 0, 0, {0, 0, 1920, 1080}, {0,
    {0}, 0}};
    game_object_t castle = {0, 0, {cross(1, all, 'w'), cross(1, all, 'h')}, 0,
    {cross(0, all, 'w'), cross(0, all, 'h')}, 0, 0, {0, 0, 1920, 1080}, {0,
    {0}, 0}};
    game_object_t sky = {0, 0, {cross(1, all, 'w'), cross(1, all, 'h')}, 0,
    {cross(0, all, 'w'), cross(0, all, 'h')}, 0, 0, {0, 0, 1920, 1080}, {0,
    {0}, 0}};
    game_object_t clouds = {0, 0, {cross(1, all, 'w'), cross(1, all, 'h')}, 0,
    {cross(0, all, 'w'), cross(0, all, 'h')}, 0, 0, {0, 0, 1920, 1080}, {0,
    {0}, 0}};
    init_game_object(&sky, "asset/menu/backgrounds/sky.png");
    init_game_object(&clouds, "asset/menu/backgrounds/clouds.png");
    init_game_object(&castle, "asset/menu/backgrounds/castele.png");
    init_game_object(&ground, "asset/menu/backgrounds/castle_ground.png");
    all->menu[0].settings[0] = sky;
    all->menu[0].settings[1] = clouds;
    all->menu[0].settings[4] = castle;
    all->menu[0].settings[6] = ground;
}

void create_sprites_menu(all_t *all)
{
    all->menu[0].settings = malloc(sizeof(game_object_t) * 12);

    all->fps_clock = sfClock_create();
    create_sprites_menu_parallax(all);
    create_sprites_menu_parallax_two(all);
    create_sprites_menu_buttons(all);
    create_tutorial_sprites(all);
    repeat_textures_menu(all);
}