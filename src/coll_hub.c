/*
** EPITECH PROJECT, 2024
** collision hub
** File description:
** for rpg
*/

#include "rpg.h"

static int get_x(repo_t *repo)
{
    float x = repo->player->coords.x;

    return x / 160;
}

static int get_y(repo_t *repo)
{
    float y = repo->player->coords.y;

    return y / 160;
}

static int *get_pos(repo_t *repo)
{
    int x = 0;
    int y = 0;
    int *coords = malloc(sizeof(int) * 2);

    x = get_x(repo);
    y = get_y(repo);
    coords[0] = x;
    coords[1] = y;
    return coords;
}

int coll_update(repo_t *repo)
{
    int *coords = NULL;

    coords = get_pos(repo);
    repo->map->collision = get_grid(repo->room->colision);
    repo->map->collision[coords[1]][coords[0]] = 'P';
    free(coords);
    return 0;
}
