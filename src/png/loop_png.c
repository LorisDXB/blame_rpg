/*
** EPITECH PROJECT, 2024
** gitaction-mirror
** File description:
** loop_png
*/

#include "rpg.h"

static void change_rect_png(png_t *png)
{
    png->sprite->rect.left += 192 / 8;
    if (png->sprite->rect.left >= (192 / 4))
        png->sprite->rect.left = 0;
    sfSprite_setTextureRect(png->sprite->spr, png->sprite->rect);
}

void loop_rect_png(repo_t *repo)
{
    float sec =
        sfClock_getElapsedTime(repo->set->png).microseconds / 1000000.0;

    if (sec >= 0.5) {
        change_rect_png(repo->room->png);
        sfClock_restart(repo->set->png);
    }
}
