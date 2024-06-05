/*
** EPITECH PROJECT, 2024
** rpg-loryce.gode
** File description:
** collider_rect_ig
*/

#include "../../../../include/rpg.h"

static sfRectangleShape *get_newpos_rect(sfRectangleShape *rect,
    sfVector2f scale, sfVector2f pos)
{
    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setSize(rect, scale);
    return rect;
}

static void reset_pos(repo_t *repo)
{
    repo->ig_menu->rect[resume_ig].pos = (sfVector2f)
        {TOP_RESUME_X, TOP_RESUME_Y};
    repo->ig_menu->rect[resume_ig].scale = (sfVector2f)
        {TOP_RESUME_SCALE_X, TOP_RESUME_SCALE_Y};
    repo->ig_menu->rect[resume_ig].rectangle = get_newpos_rect(
        repo->ig_menu->rect[resume_ig].rectangle,
        repo->ig_menu->rect[resume_ig].scale,
        repo->ig_menu->rect[resume_ig].pos);
}

static void reset_pos_2(repo_t *repo)
{
    repo->ig_menu->rect[save_ig].pos = (sfVector2f)
        {TOP_SAVE_IG_X, TOP_SAVE_IG_Y};
    repo->ig_menu->rect[save_ig].scale = (sfVector2f)
        {TOP_SAVE_IG_SCALE_X, TOP_SAVE_IG_SCALE_Y};
    repo->ig_menu->rect[save_ig].rectangle = get_newpos_rect(
        repo->ig_menu->rect[save_ig].rectangle,
        repo->ig_menu->rect[save_ig].scale,
        repo->ig_menu->rect[save_ig].pos);
    repo->ig_menu->rect[leave_ig].pos = (sfVector2f)
        {TOP_LEAVE_IG_X, TOP_LEAVE_IG_Y};
    repo->ig_menu->rect[leave_ig].scale = (sfVector2f)
        {TOP_LEAVE_IG_SCALE_X, TOP_LEAVE_IG_SCALE_Y};
    repo->ig_menu->rect[leave_ig].rectangle = get_newpos_rect(
        repo->ig_menu->rect[leave_ig].rectangle,
        repo->ig_menu->rect[leave_ig].scale,
        repo->ig_menu->rect[leave_ig].pos);
}

void reset_pos_rect(repo_t *repo)
{
    reset_pos(repo);
    reset_pos_2(repo);
}

void get_collider_ig(repo_t *repo)
{
    reset_pos_rect(repo);
    for (int i = resume_ig; i <= leave_ig; i++)
        repo->ig_menu->rect[i].collider = sfRectangleShape_getGlobalBounds(
        repo->ig_menu->rect[i].rectangle);
}
