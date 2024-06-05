/*
** EPITECH PROJECT, 2024
** rpg-loryce.gode
** File description:
** hover_sound
*/

#include "rpg.h"

void get_hover_window_16_9(repo_t *repo, sfFloatRect rect, sfVector2i ms)
{
    if (sfFloatRect_contains(&rect, ms.x, ms.y))
        sfRectangleShape_setFillColor(
            repo->main_menu->rect[window_16_9].rectangle,
            repo->main_menu->rect[window_16_9].color);
    else
        sfRectangleShape_setFillColor(
            repo->main_menu->rect[window_16_9].rectangle,
            sfColor_fromRGBA(0, 0, 0, 0));
}

void get_hover_window_4_3(repo_t *repo, sfFloatRect rect, sfVector2i ms)
{
    if (sfFloatRect_contains(&rect, ms.x, ms.y))
        sfRectangleShape_setFillColor(
            repo->main_menu->rect[window_4_3].rectangle,
            repo->main_menu->rect[window_4_3].color);
    else
        sfRectangleShape_setFillColor(
            repo->main_menu->rect[window_4_3].rectangle,
            sfColor_fromRGBA(0, 0, 0, 0));
}

void get_hover_window_change(repo_t *repo, sfVector2i ms)
{
    get_hover_window_16_9(repo,
        repo->main_menu->rect[window_16_9].collider, ms);
    get_hover_window_4_3(repo,
        repo->main_menu->rect[window_4_3].collider, ms);
}
