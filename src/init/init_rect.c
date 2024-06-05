/*
** EPITECH PROJECT, 2024
** rpg-loryce.gode
** File description:
** init_rect
*/

#include "../../include/rpg.h"

sfRectangleShape *get_rect(sfVector2f size, sfVector2f pos, sfColor color)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setFillColor(rect, color);
    return rect;
}
