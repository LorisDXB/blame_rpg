/*
** EPITECH PROJECT, 2024
** rpg-loryce.gode
** File description:
** init_rect_ig
*/

#include "../../../../include/rpg.h"

static void get_resume(repo_t *repo)
{
    repo->ig_menu->rect[resume_ig].pos = (sfVector2f)
        {TOP_RESUME_X, TOP_RESUME_Y};
    repo->ig_menu->rect[resume_ig].scale = (sfVector2f)
        {TOP_RESUME_SCALE_X,
        TOP_RESUME_SCALE_Y};
    repo->ig_menu->rect[resume_ig].color = (sfColor)
        sfColor_fromRGB(0, 0, 0);
    repo->ig_menu->rect[resume_ig].rectangle = get_rect(
        repo->ig_menu->rect[resume_ig].scale,
        repo->ig_menu->rect[resume_ig].pos,
        repo->ig_menu->rect[resume_ig].color);
}

static void get_settings(repo_t *repo)
{
    repo->ig_menu->rect[save_ig].pos = (sfVector2f)
        {TOP_SAVE_IG_X, TOP_SAVE_IG_Y};
    repo->ig_menu->rect[save_ig].scale = (sfVector2f)
        {TOP_SAVE_IG_SCALE_X,
        TOP_SAVE_IG_SCALE_Y};
    repo->ig_menu->rect[save_ig].color = (sfColor)
        sfColor_fromRGB(0, 0, 0);
    repo->ig_menu->rect[save_ig].rectangle = get_rect(
        repo->ig_menu->rect[save_ig].scale,
        repo->ig_menu->rect[save_ig].pos,
        repo->ig_menu->rect[save_ig].color);
}

void get_leave(repo_t *repo)
{
    repo->ig_menu->rect[leave_ig].pos = (sfVector2f)
    {TOP_LEAVE_IG_X, TOP_LEAVE_IG_Y};
    repo->ig_menu->rect[leave_ig].scale = (sfVector2f)
    {TOP_LEAVE_IG_SCALE_X,
        TOP_LEAVE_IG_SCALE_Y};
    repo->ig_menu->rect[leave_ig].color = (sfColor)
        sfColor_fromRGB(0, 0, 0);
    repo->ig_menu->rect[leave_ig].rectangle = get_rect(
        repo->ig_menu->rect[leave_ig].scale,
        repo->ig_menu->rect[leave_ig].pos,
        repo->ig_menu->rect[leave_ig].color);
}

void init_rect_ig(repo_t *repo)
{
    get_resume(repo);
    get_settings(repo);
    get_leave(repo);
}
