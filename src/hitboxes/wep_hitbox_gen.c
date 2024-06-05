/*
** EPITECH PROJECT, 2024
** wep_hitbox generator
** File description:
** for rpg
*/

#include "../../include/rpg.h"

sfRectangleShape *wep_hitbox_gen(weapon_t *wep)
{
    sfRectangleShape *ret = sfRectangleShape_create();
    sfFloatRect bounds = sfSprite_getLocalBounds(wep->spr->spr);

    sfRectangleShape_setOrigin(ret,
        (sfVector2f){bounds.width / 7, bounds.height / 7});
    sfRectangleShape_setScale(ret, (sfVector2f){3, 3});
    sfRectangleShape_setSize(ret, (sfVector2f){bounds.width, bounds.height});
    sfRectangleShape_setOutlineThickness(ret, 1);
    sfRectangleShape_setOutlineColor(ret, sfRed);
    sfRectangleShape_setFillColor(ret, sfTransparent);
    return ret;
}
