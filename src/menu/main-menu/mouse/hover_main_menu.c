/*
** EPITECH PROJECT, 2024
** rpg-loryce.gode
** File description:
** hover_main_menu
*/

#include "rpg.h"

static void get_hover_play(repo_t *repo, sfFloatRect rect, sfVector2i ms)
{
    if (sfFloatRect_contains(&rect, ms.x, ms.y))
        sfRectangleShape_setFillColor(
            repo->main_menu->rect[play].rectangle,
            repo->main_menu->rect[play].color);
    else
        sfRectangleShape_setFillColor(
            repo->main_menu->rect[play].rectangle,
            sfColor_fromRGBA(0, 0, 0, 0));
}

static void get_hover_continu(repo_t *repo, sfFloatRect rect, sfVector2i ms)
{
    if (sfFloatRect_contains(&rect, ms.x, ms.y))
        sfRectangleShape_setFillColor(
            repo->main_menu->rect[continu].rectangle,
            repo->main_menu->rect[continu].color);
    else
        sfRectangleShape_setFillColor(
            repo->main_menu->rect[continu].rectangle,
            sfColor_fromRGBA(0, 0, 0, 0));
}

static void get_hover_settings(repo_t *repo, sfFloatRect rect, sfVector2i ms)
{
    if (sfFloatRect_contains(&rect, ms.x, ms.y))
        sfRectangleShape_setFillColor(
            repo->main_menu->rect[settings].rectangle,
            repo->main_menu->rect[settings].color);
    else
        sfRectangleShape_setFillColor(
            repo->main_menu->rect[settings].rectangle,
            sfColor_fromRGBA(0, 0, 0, 0));
}

static void get_hover_leave(repo_t *repo, sfFloatRect rect, sfVector2i ms)
{
    if (sfFloatRect_contains(&rect, ms.x, ms.y))
        sfRectangleShape_setFillColor(
            repo->main_menu->rect[leave].rectangle,
            repo->main_menu->rect[leave].color);
    else
        sfRectangleShape_setFillColor(
            repo->main_menu->rect[leave].rectangle,
            sfColor_fromRGBA(0, 0, 0, 0));
}

static void get_hover_sound(repo_t *repo, sfFloatRect rect, sfVector2i ms)
{
    if (sfFloatRect_contains(&rect, ms.x, ms.y))
        sfRectangleShape_setFillColor(
            repo->main_menu->rect[sound].rectangle,
            repo->main_menu->rect[sound].color);
    else
        sfRectangleShape_setFillColor(
            repo->main_menu->rect[sound].rectangle,
            sfColor_fromRGBA(0, 0, 0, 0));
}

void get_hover_window(repo_t *repo, sfFloatRect rect, sfVector2i ms)
{
    if (sfFloatRect_contains(&rect, ms.x, ms.y))
        sfRectangleShape_setFillColor(
            repo->main_menu->rect[window_size].rectangle,
            repo->main_menu->rect[window_size].color);
    else
        sfRectangleShape_setFillColor(
            repo->main_menu->rect[window_size].rectangle,
            sfColor_fromRGBA(0, 0, 0, 0));
}

void get_mouse_hover(repo_t *repo, sfVector2i ms)
{
    get_hover_play(repo, repo->main_menu->rect[play].collider, ms);
    get_hover_continu(repo, repo->main_menu->rect[continu].collider, ms);
    get_hover_settings(repo, repo->main_menu->rect[settings].collider, ms);
    get_hover_leave(repo, repo->main_menu->rect[leave].collider, ms);
    get_hover_sound(repo, repo->main_menu->rect[sound].collider, ms);
    get_hover_window(repo, repo->main_menu->rect[window_size].collider, ms);
    get_hover_window_change(repo, ms);
    get_hover_sound_change(repo, ms);
}
