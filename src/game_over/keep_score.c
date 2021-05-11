/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-diogo.faria-martins
** File description:
** keep_score
*/

#include "defender.h"

void write_scorefile(all_t *all, int fd)
{
    write(fd, ";", 1);
    write(fd, my_strcat(all->mapchooser->nickname, "score : "),
    my_strlen(my_strcat(all->mapchooser->nickname, "score : ")));
    write(fd, my_itoa(all->game->score_nb),
    my_strlen(my_itoa(all->game->score_nb)));
}

char *read_myfile_score(char *filepath, all_t *all, int i)
{
    int buffersize = my_lenght(filepath);
    int fd = 0;
    int lenght = 0;
    char *buffer = malloc(sizeof(char) * (buffersize + 1));

    fd = open(filepath, O_RDWR);
    if (fd == -1)
        return (NULL);
    lenght = read(fd, buffer, buffersize);
    if (lenght == -1)
        return (NULL);
    if (i == 0)
        write_scorefile(all, fd);
    buffer[lenght] = '\0';
    close(fd);
    return (buffer);
}