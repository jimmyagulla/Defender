/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** read_map
*/

#include "defender.h"

int my_lenght(char *filepath)
{
    struct stat buff;
    int ret = stat(filepath, &buff);

    if (ret == -1)
        return (84);
    return (buff.st_size);
}

int read_myfile(char *filepath, all_t *all)
{
    int buffersize = my_lenght(filepath);
    int fd = 0;
    int lenght = 0;
    char *buffer = malloc(sizeof(char) * (buffersize + 1));

    fd = open(filepath, O_RDWR);
    if (fd == -1)
        return (84);
    lenght = read(fd, buffer, buffersize);
    if (lenght == -1)
        return (84);
    buffer[lenght] = '\0';
    close(fd);
    all->game->map_buff = buffer;
    return (0);
}

int draw_map(all_t *all)
{
    char *map;

    if (all->mapchooser->choice == 3)
        map = "src/maps/map_two.txt";
    if (all->mapchooser->choice == 2)
        map = "src/maps/map_bricks";
    if (all->mapchooser->choice == 1)
        map = "src/maps/mode_one.txt";
    if (read_myfile(map, all) == 84)
        return (84);
    all->game->map_arr = my_str_to_word_array(all->game->map_buff, "\n");
    all->game->tower_arr = all->game->map_arr;
    return (0);
}