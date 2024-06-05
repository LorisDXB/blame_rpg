/*
** EPITECH PROJECT, 2024
** rpg-loryce.gode
** File description:
** init_window_size
*/

#include "rpg.h"

void get_window_bar(repo_t *repo)
{
    repo->main_menu->rect[window_bar].pos = (sfVector2f)
        {(repo->set->mode.width / 50) * 21 + (repo->set->mode.width / 96),
        (repo->set->mode.height / 50) * 34 + (repo->set->mode.height / 216)};
    repo->main_menu->rect[window_bar].scale = (sfVector2f)
        {repo->set->mode.width / 384, repo->set->mode.height / 9};
    repo->main_menu->rect[window_bar].color =
        (sfColor)sfColor_fromRGB(159, 83, 236);
    repo->main_menu->rect[window_bar].rectangle =
        get_rect(repo->main_menu->rect[window_bar].scale,
        repo->main_menu->rect[window_bar].pos,
        repo->main_menu->rect[window_bar].color);
}

void get_window_16_9(repo_t *repo)
{
    repo->main_menu->rect[window_16_9].pos =
        (sfVector2f){WINDOW_16_9_X, WINDOW_16_9_Y};
    repo->main_menu->rect[window_16_9].scale =
        (sfVector2f){WINDOW_16_9_SCALE_X, WINDOW_16_9_SCALE_Y};
    repo->main_menu->rect[window_16_9].color =
        (sfColor)sfColor_fromRGB(237, 176, 176);
    repo->main_menu->rect[window_16_9].rectangle =
        get_rect(repo->main_menu->rect[window_16_9].scale,
        repo->main_menu->rect[window_16_9].pos,
        repo->main_menu->rect[window_16_9].color);
}

void get_window_4_3(repo_t *repo)
{
    repo->main_menu->rect[window_4_3].pos =
        (sfVector2f){WINDOW_4_3_X, WINDOW_4_3_Y};
    repo->main_menu->rect[window_4_3].scale =
        (sfVector2f){WINDOW_4_3_SCALE_X, WINDOW_4_3_SCALE_Y};
    repo->main_menu->rect[window_4_3].color =
        (sfColor)sfColor_fromRGB(237, 176, 176);
    repo->main_menu->rect[window_4_3].rectangle =
        get_rect(repo->main_menu->rect[window_4_3].scale,
        repo->main_menu->rect[window_4_3].pos,
        repo->main_menu->rect[window_4_3].color);
}

void init_change_window(repo_t *repo)
{
    get_window_bar(repo);
    get_window_16_9(repo);
    get_window_4_3(repo);
}
