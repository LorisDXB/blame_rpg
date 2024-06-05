/*
** EPITECH PROJECT, 2024
** run_animation
** File description:
** for rpg
*/

#include "../../include/rpg.h"

static void check_last_key(sfIntRect *animation, repo_t *repo)
{
    int last_key = repo->player->key_press[4];

    if (last_key == 0)
        (*animation).top = 240;
    if (last_key == 1)
        (*animation).top = 80;
    if (last_key == 2)
        (*animation).top = 160;
    if (last_key == 3)
        (*animation).top = 0;
}

void death_animation(repo_t *repo)
{
    static sfIntRect animation = {0, 0, 80, 80};
    sfClock *clock = repo->player->clock;
    float sec =
        sfClock_getElapsedTime(clock).microseconds / 1000000.0;

    if (sec >= 0.1) {
        check_last_key(&animation, repo);
        sfSprite_setTextureRect(repo->player->sprite->spr, animation);
        if (animation.left < 400)
            animation.left += animation.width;
        else
            repo->set->death_request = 1;
        sfClock_restart(clock);
    }
}
