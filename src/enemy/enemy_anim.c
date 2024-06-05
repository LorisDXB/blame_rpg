/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** enemy_anim.c
*/

#include "rpg.h"

void enemy_anim(enemy_t *enemy, sfVector2f next_coords)
{
    float seconds = sfTime_asSeconds(sfClock_getElapsedTime(enemy->clock));
    sfVector2f coords = sfSprite_getPosition(enemy->sprite->spr);
    sfIntRect rect = sfSprite_getTextureRect(enemy->sprite->spr);

    if (seconds > 0.2) {
        if (next_coords.x < coords.x)
            rect.top = 0;
        else
            rect.top = sfTexture_getSize(enemy->sprite->tex).y / 2;
        if (rect.left >= sfTexture_getSize(enemy->sprite->tex).x / 6 * 5)
            rect.left = 0;
        else
            rect.left += rect.width;
        sfSprite_setTextureRect(enemy->sprite->spr, rect);
        sfClock_restart(enemy->clock);
    }
}
