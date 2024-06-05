/*
** EPITECH PROJECT, 2024
** dash system
** File description:
** for rpg
*/

#include "../../include/rpg.h"

static void dash_up(repo_t *repo, int y, int x, int ck)
{
    float seconds =
        sfClock_getElapsedTime(repo->set->debounce).microseconds / 1000000.0;
    sfVector2f sp = repo->player->coords;
    sfVector2f mp = (sfVector2f){sp.x, sp.y - 100};
    sfVector2f ip = (sfVector2f){0, 0};

    if (repo->map->collision[y - 1][x] == 'O' ||
        repo->map->collision[y - 1][x] == 'E') {
        if (seconds <= 0.07) {
            ip.x = sp.x + (mp.x - sp.x) * seconds;
            ip.y = sp.y + (mp.y - sp.y) * seconds;
            repo->player->coords = ip;
        }
        if (seconds > 0.2) {
            repo->player->dash = CD;
            sfClock_restart(repo->set->debounce);
        }
    }
}

static void dash_left(repo_t *repo, int y, int x, int ck)
{
    float seconds =
        sfClock_getElapsedTime(repo->set->debounce).microseconds / 1000000.0;
    sfVector2f sp = repo->player->coords;
    sfVector2f mp = (sfVector2f){sp.x - 100, sp.y};
    sfVector2f ip = (sfVector2f){0, 0};

    if (repo->map->collision[y][x - 1] == 'O' ||
        repo->map->collision[y][x - 1] == 'E') {
        if (seconds <= 0.07) {
            ip.x = sp.x + (mp.x - sp.x) * seconds;
            ip.y = sp.y + (mp.y - sp.y) * seconds;
            repo->player->coords = ip;
        }
        if (seconds > 0.2) {
            repo->player->dash = CD;
            sfClock_restart(repo->set->debounce);
        }
    }
}

static void dash_down(repo_t *repo, int y, int x, int ck)
{
    float seconds =
        sfClock_getElapsedTime(repo->set->debounce).microseconds / 1000000.0;
    sfVector2f sp = repo->player->coords;
    sfVector2f mp = (sfVector2f){sp.x, sp.y + 100};
    sfVector2f ip = (sfVector2f){0, 0};

    if (repo->map->collision[y + 1][x] == 'O' ||
        repo->map->collision[y + 1][x] == 'E') {
        if (seconds <= 0.07) {
            ip.x = sp.x + (mp.x - sp.x) * seconds;
            ip.y = sp.y + (mp.y - sp.y) * seconds;
            repo->player->coords = ip;
        }
        if (seconds > 0.2) {
            repo->player->dash = CD;
            sfClock_restart(repo->set->debounce);
        }
    }
}

static void dash_right(repo_t *repo, int y, int x, int ck)
{
    float seconds =
        sfClock_getElapsedTime(repo->set->debounce).microseconds / 1000000.0;
    sfVector2f sp = repo->player->coords;
    sfVector2f mp = (sfVector2f){sp.x + 100, sp.y};
    sfVector2f ip = (sfVector2f){0, 0};

    if (repo->map->collision[y][x + 1] == 'O' ||
        repo->map->collision[y][x + 1] == 'E') {
        if (seconds <= 0.07) {
            ip.x = sp.x + (mp.x - sp.x) * seconds;
            ip.y = sp.y + (mp.y - sp.y) * seconds;
            repo->player->coords = ip;
        }
        if (seconds > 0.2) {
            repo->player->dash = CD;
            sfClock_restart(repo->set->debounce);
        }
    }
}

void dash_sound(repo_t *repo)
{
    float seconds =
        sfClock_getElapsedTime(repo->set->debounce).microseconds / 1000000.0;
    sfSoundBuffer *buffer =
        sfSoundBuffer_createFromFile("assets/musics/dash.ogg");
    sfSound *sound = sfSound_create();

    sfSound_setBuffer(sound, buffer);
    sfSound_play(sound);
    if (seconds >= 0.2) {
        sfSound_destroy(sound);
        sfSoundBuffer_destroy(buffer);
    }
}

void dash_in_direction(repo_t *repo)
{
    int y = floor(repo->player->coords.y / 160);
    int x = floor(repo->player->coords.x / 160);
    int ck = repo->set->transition_request;

    switch (repo->player->key_press[4]) {
        case (0):
            dash_up(repo, y, x, ck);
            break;
        case (1):
            dash_left(repo, y, x, ck);
            break;
        case (2):
            dash_down(repo, y, x, ck);
            break;
        case (3):
            dash_right(repo, y, x, ck);
            break;
    }
}
