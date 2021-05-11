/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** handle_spawn_points
*/

#include "defender.h"

int get_randoms(int lowest, int highest, int counter)
{
    int rd_nb = 0;

    for (int i = 0; i < counter; i++) {
        rd_nb = (rand() % (highest - lowest + 1)) + lowest;
    }
    return (rd_nb);
}

int count_spawn_points(all_t *all, int y)
{
    int sp_counter = 0;

    for (int j = 0; all->game->map_arr[y][j] != 0; j++) {
        if (all->game->map_arr[y][j] == 'S') {
            sp_counter++;
        }
    }
    return (sp_counter);
}

int **fill_array(all_t *all, int **spawn_points_inf, int spawn_points)
{
    int arr = 0;
    int nb = 0;

    for (int y = 0; all->game->map_arr[y] != NULL; y++) {
        for (int j = 0; all->game->map_arr[y][j] != 0; j++) {
            if (all->game->map_arr[y][j] == 'S') {
                spawn_points_inf[arr] = malloc(sizeof(int) * spawn_points + 1);
                spawn_points_inf[arr][nb] = j - 2;
                nb++;
                spawn_points_inf[arr][nb] = y;
                nb++;
                spawn_points_inf[arr][nb] = '\0';
                arr++;
            }
            nb = 0;
        }
    }
    return (spawn_points_inf);
}

int loop_map(all_t *all)
{
    int spawn_points_nb = 0;
    int **spawn_points_cood;

    all->game->nb_spawn_points = 0;
    for (int y = 0; all->game->map_arr[y] != NULL; y++) {
        spawn_points_nb += count_spawn_points(all, y);
    }
    spawn_points_cood = malloc(sizeof(int *) * spawn_points_nb + 1);
    all->game->nb_spawn_points = spawn_points_nb;
    all->game->spawn_points = fill_array(all, spawn_points_cood,
    spawn_points_nb);
    return (0);
}