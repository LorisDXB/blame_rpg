/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** change_xpbar.c
*/

#include "rpg.h"

static void increase_xpbar(player_t *player, int perc)
{
    sfVector2f size = {30, sfRectangleShape_getSize(player->xpbar->rem).y + 1};

    if (sfRectangleShape_getSize(player->xpbar->rem).y != perc) {
        if (sfTime_asSeconds(sfClock_getElapsedTime(player->xpbar->clock))
            > 0.002) {
            sfRectangleShape_setSize(player->xpbar->rem, size);
            sfClock_restart(player->xpbar->clock);
        }
    }
}

void change_xpbar(player_t *player)
{
    int perc = player->skills->xp / (float)(player->skills->lvl * 100) * 415;

    if (perc < sfRectangleShape_getSize(player->xpbar->rem).y)
        sfRectangleShape_setSize(player->xpbar->rem, (sfVector2f){30, 0});
    if (perc > sfRectangleShape_getSize(player->xpbar->rem).y)
        increase_xpbar(player, perc);
}
