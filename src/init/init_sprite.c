/*
** EPITECH PROJECT, 2024
** rpg-loryce.gode
** File description:
** init_sprite
*/

#include "../../include/rpg.h"

sfSprite *get_sprite(sfVector2f scale, sfVector2f pos, sfTexture *texture)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, scale);
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}
