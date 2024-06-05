/*
** EPITECH PROJECT, 2024
** rpg-loryce.gode
** File description:
** hover_sound
*/

#include "rpg.h"

static void get_hover_sound_0(repo_t *repo, sfFloatRect rect, sfVector2i ms)
{
    if (sfFloatRect_contains(&rect, ms.x, ms.y))
        sfRectangleShape_setFillColor(
            repo->main_menu->rect[sound_0].rectangle,
            repo->main_menu->rect[sound_0].color);
    else
        sfRectangleShape_setFillColor(
            repo->main_menu->rect[sound_0].rectangle,
            sfColor_fromRGBA(0, 0, 0, 0));
}

static void get_hover_sound_25(repo_t *repo, sfFloatRect rect, sfVector2i ms)
{
    if (sfFloatRect_contains(&rect, ms.x, ms.y))
        sfRectangleShape_setFillColor(
            repo->main_menu->rect[sound_25].rectangle,
            repo->main_menu->rect[sound_25].color);
    else
        sfRectangleShape_setFillColor(
            repo->main_menu->rect[sound_25].rectangle,
            sfColor_fromRGBA(0, 0, 0, 0));
}

static void get_hover_sound_50(repo_t *repo, sfFloatRect rect, sfVector2i ms)
{
    if (sfFloatRect_contains(&rect, ms.x, ms.y))
        sfRectangleShape_setFillColor(
            repo->main_menu->rect[sound_50].rectangle,
            repo->main_menu->rect[sound_50].color);
    else
        sfRectangleShape_setFillColor(
            repo->main_menu->rect[sound_50].rectangle,
            sfColor_fromRGBA(0, 0, 0, 0));
}

static void get_hover_sound_75(repo_t *repo, sfFloatRect rect, sfVector2i ms)
{
    if (sfFloatRect_contains(&rect, ms.x, ms.y))
        sfRectangleShape_setFillColor(
            repo->main_menu->rect[sound_75].rectangle,
            repo->main_menu->rect[sound_75].color);
    else
        sfRectangleShape_setFillColor(
            repo->main_menu->rect[sound_75].rectangle,
            sfColor_fromRGBA(0, 0, 0, 0));
}

static void get_hover_sound_100(repo_t *repo, sfFloatRect rect, sfVector2i ms)
{
    if (sfFloatRect_contains(&rect, ms.x, ms.y))
        sfRectangleShape_setFillColor(
            repo->main_menu->rect[sound_100].rectangle,
            repo->main_menu->rect[sound_100].color);
    else
        sfRectangleShape_setFillColor(
            repo->main_menu->rect[sound_100].rectangle,
            sfColor_fromRGBA(0, 0, 0, 0));
}

void get_hover_sound_change(repo_t *repo, sfVector2i ms)
{
    get_hover_sound_0(repo, repo->main_menu->rect[sound_0].collider, ms);
    get_hover_sound_25(repo, repo->main_menu->rect[sound_25].collider, ms);
    get_hover_sound_50(repo, repo->main_menu->rect[sound_50].collider, ms);
    get_hover_sound_75(repo, repo->main_menu->rect[sound_75].collider, ms);
    get_hover_sound_100(repo, repo->main_menu->rect[sound_100].collider, ms);
}
