/*
** EPITECH PROJECT, 2024
** rpg-loryce.gode
** File description:
** hover_ig_menu
*/

#include "../../../../include/rpg.h"

static void get_resume_ig_hover(repo_t *repo, sfFloatRect rect,
    sfVector2f ms)
{
    if (sfFloatRect_contains(&rect, ms.x, ms.y))
        sfRectangleShape_setFillColor(
            repo->ig_menu->rect[resume_ig].rectangle,
            sfColor_fromRGBA(60, 60, 60, 155));
    else
        sfRectangleShape_setFillColor(
            repo->ig_menu->rect[resume_ig].rectangle,
            sfColor_fromRGBA(0, 0, 0, 0));
}

static void get_save_ig_hover(repo_t *repo, sfFloatRect rect,
    sfVector2f ms)
{
    if (sfFloatRect_contains(&rect, ms.x, ms.y))
        sfRectangleShape_setFillColor(
            repo->ig_menu->rect[save_ig].rectangle,
            sfColor_fromRGBA(60, 60, 60, 155));
    else
        sfRectangleShape_setFillColor(
            repo->ig_menu->rect[save_ig].rectangle,
            sfColor_fromRGBA(0, 0, 0, 0));
}

void get_leave_ig_hover(repo_t *repo, sfFloatRect rect,
    sfVector2f ms)
{
    if (sfFloatRect_contains(&rect, ms.x, ms.y))
        sfRectangleShape_setFillColor(
            repo->ig_menu->rect[leave_ig].rectangle,
            sfColor_fromRGBA(60, 60, 60, 155));
    else
        sfRectangleShape_setFillColor(
            repo->ig_menu->rect[leave_ig].rectangle,
            sfColor_fromRGBA(0, 0, 0, 0));
}

void get_ig_hover_button(repo_t *repo, sfVector2f ms)
{
    get_resume_ig_hover(repo,
        repo->ig_menu->rect[resume_ig].collider, ms);
    get_save_ig_hover(repo,
        repo->ig_menu->rect[save_ig].collider, ms);
    get_leave_ig_hover(repo,
        repo->ig_menu->rect[leave_ig].collider, ms);
}
