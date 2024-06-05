/*
** EPITECH PROJECT, 2024
** gitaction-mirror
** File description:
** draw_png
*/

#include "rpg.h"

void draw_png(repo_t *repo)
{
    sfRenderWindow_drawSprite(repo->set->w,
    repo->room->png->sprite->spr, NULL);
    if (repo->room->png->affiche == 1 && repo->room->png->space == -1) {
        sfRenderWindow_drawSprite(repo->set->w,
        repo->room->png->spa->spr, NULL);
    }
}
