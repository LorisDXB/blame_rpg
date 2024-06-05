/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** creation_mod.c
*/

#include "rpg.h"

sfRectangleShape *create_rectangle(sfVector2f size, sfVector2f pos,
    sfColor color)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setFillColor(rect, color);
    sfRectangleShape_setOrigin(rect, (sfVector2f){size.x / 2, size.y / 2});
    return rect;
}

sfCircleShape *create_circle(float radius, sfVector2f pos)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setPosition(circle, pos);
    sfCircleShape_setOrigin(circle, (sfVector2f){radius, radius});
    return circle;
}

sprite_t *create_spritet(char *path, sfVector2f scale)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));

    sprite->spr = sfSprite_create();
    sprite->tex = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(sprite->spr, sprite->tex, 0);
    sprite->scl = scale;
    sfSprite_setScale(sprite->spr, sprite->scl);
    return sprite;
}
