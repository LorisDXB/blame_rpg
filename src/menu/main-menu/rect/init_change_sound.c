/*
** EPITECH PROJECT, 2024
** rpg-loryce.gode
** File description:
** init_sound_change
*/

#include "rpg.h"

static void get_sound_0(repo_t *repo)
{
    repo->main_menu->rect[sound_0].pos =
        (sfVector2f){SOUND_0_X, SOUND_0_Y};
    repo->main_menu->rect[sound_0].scale =
        (sfVector2f){SOUND_0_SCALE_X, SOUND_0_SCALE_Y};
    repo->main_menu->rect[sound_0].color =
        (sfColor)sfColor_fromRGB(237, 176, 176);
    repo->main_menu->rect[sound_0].rectangle =
    get_rect(repo->main_menu->rect[sound_0].scale,
        repo->main_menu->rect[sound_0].pos,
        repo->main_menu->rect[sound_0].color);
}

static void get_sound_25(repo_t *repo)
{
    repo->main_menu->rect[sound_25].pos =
        (sfVector2f){SOUND_25_X, SOUND_25_Y};
    repo->main_menu->rect[sound_25].scale =
        (sfVector2f){SOUND_25_SCALE_X, SOUND_25_SCALE_Y};
    repo->main_menu->rect[sound_25].color =
        (sfColor)sfColor_fromRGB(237, 176, 176);
    repo->main_menu->rect[sound_25].rectangle =
    get_rect(repo->main_menu->rect[sound_25].scale,
        repo->main_menu->rect[sound_25].pos,
        repo->main_menu->rect[sound_25].color);
}

static void get_sound_50(repo_t *repo)
{
    repo->main_menu->rect[sound_50].pos =
        (sfVector2f){SOUND_50_X, SOUND_50_Y};
    repo->main_menu->rect[sound_50].scale =
        (sfVector2f){SOUND_50_SCALE_X, SOUND_50_SCALE_Y};
    repo->main_menu->rect[sound_50].color =
        (sfColor)sfColor_fromRGB(237, 176, 176);
    repo->main_menu->rect[sound_50].rectangle =
    get_rect(repo->main_menu->rect[sound_50].scale,
        repo->main_menu->rect[sound_50].pos,
        repo->main_menu->rect[sound_50].color);
}

static void get_sound_75(repo_t *repo)
{
    repo->main_menu->rect[sound_75].pos =
        (sfVector2f){SOUND_75_X, SOUND_75_Y};
    repo->main_menu->rect[sound_75].scale =
        (sfVector2f){SOUND_75_SCALE_X, SOUND_75_SCALE_Y};
    repo->main_menu->rect[sound_75].color =
        (sfColor)sfColor_fromRGB(237, 176, 176);
    repo->main_menu->rect[sound_75].rectangle =
    get_rect(repo->main_menu->rect[sound_75].scale,
        repo->main_menu->rect[sound_75].pos,
        repo->main_menu->rect[sound_75].color);
}

static void get_sound_100(repo_t *repo)
{
    repo->main_menu->rect[sound_100].pos =
        (sfVector2f){SOUND_100_X, SOUND_100_Y};
    repo->main_menu->rect[sound_100].scale =
        (sfVector2f){SOUND_100_SCALE_X, SOUND_100_SCALE_Y};
    repo->main_menu->rect[sound_100].color =
        (sfColor)sfColor_fromRGB(237, 176, 176);
    repo->main_menu->rect[sound_100].rectangle =
    get_rect(repo->main_menu->rect[sound_100].scale,
        repo->main_menu->rect[sound_100].pos,
        repo->main_menu->rect[sound_100].color);
}

void get_sound_bar(repo_t *repo)
{
    repo->main_menu->rect[sound_bar].pos = (sfVector2f)
        {(repo->set->mode.width / 50) * 21 + (repo->set->mode.width / 96),
        (repo->set->mode.height / 50) * 30 + (repo->set->mode.height / 216)};
    repo->main_menu->rect[sound_bar].scale = (sfVector2f)
        {repo->set->mode.width / 384, repo->set->mode.height / 3.73};
    repo->main_menu->rect[sound_bar].color =
        (sfColor)sfColor_fromRGB(159, 83, 236);
    repo->main_menu->rect[sound_bar].rectangle =
    get_rect(repo->main_menu->rect[sound_bar].scale,
        repo->main_menu->rect[sound_bar].pos,
        repo->main_menu->rect[sound_bar].color);
}

void init_change_sound(repo_t *repo)
{
    get_sound_bar(repo);
    get_sound_0(repo);
    get_sound_25(repo);
    get_sound_50(repo);
    get_sound_75(repo);
    get_sound_100(repo);
}
