/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** get_position.c
*/

#include "rpg.h"

int *get_position(sfVector2f coords)
{
    int *pos = malloc(sizeof(int) * 2);

    pos[0] = coords.x / 160;
    pos[1] = coords.y / 160;
    return pos;
}
