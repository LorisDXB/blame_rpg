/*
** EPITECH PROJECT, 2024
** rpg-loryce.gode
** File description:
** init_collider
*/

#include "rpg.h"

void get_colliders(repo_t *repo)
{
    for (int index = title; index <= sound_100; index++)
        repo->main_menu->rect[index].collider =
        sfRectangleShape_getGlobalBounds(
        repo->main_menu->rect[index].rectangle);
}
