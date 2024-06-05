/*
** EPITECH PROJECT, 2024
** rpg-loryce.gode
** File description:
** init_title
*/

#include "rpg.h"

static void get_title(repo_t *repo)
{
    repo->main_menu->rect[title].pos =
        (sfVector2f){TITLE_X, TITLE_Y};
    repo->main_menu->rect[title].scale =
        (sfVector2f){TITLE_SCALE_X, TITLE_SCALE_Y};
    repo->main_menu->rect[title].color =
        (sfColor)sfColor_fromRGB(237, 176, 176);
    repo->main_menu->rect[title].rectangle =
    get_rect(repo->main_menu->rect[title].scale,
        repo->main_menu->rect[title].pos,
        repo->main_menu->rect[title].color);
}

static void get_play(repo_t *repo)
{
    repo->main_menu->rect[play].pos =
        (sfVector2f){PLAY_BUTTON_X, PLAY_BUTTON_Y};
    repo->main_menu->rect[play].scale =
        (sfVector2f){PLAY_BUTTON_SCALE_X, PLAY_BUTTON_SCALE_Y};
    repo->main_menu->rect[play].color =
        (sfColor)sfColor_fromRGB(237, 176, 176);
    repo->main_menu->rect[play].rectangle =
    get_rect(repo->main_menu->rect[play].scale,
        repo->main_menu->rect[play].pos,
        repo->main_menu->rect[play].color);
}

static void get_continu(repo_t *repo)
{
    repo->main_menu->rect[continu].pos =
        (sfVector2f){CONTINUE_BUTTON_X, CONTINUE_BUTTON_Y};
    repo->main_menu->rect[continu].scale =
        (sfVector2f){CONTINUE_BUTTON_SCALE_X, CONTINUE_BUTTON_SCALE_Y};
    repo->main_menu->rect[continu].color =
        (sfColor)sfColor_fromRGB(237, 176, 176);
    repo->main_menu->rect[continu].rectangle =
    get_rect(repo->main_menu->rect[continu].scale,
        repo->main_menu->rect[continu].pos,
        repo->main_menu->rect[continu].color);
}

static void get_settings(repo_t *repo)
{
    repo->main_menu->rect[settings].pos =
        (sfVector2f){SETTING_BUTTON_X, SETTING_BUTTON_Y};
    repo->main_menu->rect[settings].scale =
        (sfVector2f){SETTING_BUTTON_SCALE_X, SETTING_BUTTON_SCALE_Y};
    repo->main_menu->rect[settings].color =
        (sfColor)sfColor_fromRGB(237, 176, 176);
    repo->main_menu->rect[settings].rectangle =
    get_rect(repo->main_menu->rect[settings].scale,
        repo->main_menu->rect[settings].pos,
        repo->main_menu->rect[settings].color);
}

static void get_leave(repo_t *repo)
{
    repo->main_menu->rect[leave].pos =
        (sfVector2f){LEAVE_BUTTON_X, LEAVE_BUTTON_Y};
    repo->main_menu->rect[leave].scale =
        (sfVector2f){LEAVE_BUTTON_SCALE_X,
        LEAVE_BUTTON_SCALE_Y};
    repo->main_menu->rect[leave].color =
        (sfColor)sfColor_fromRGB(237, 176, 176);
    repo->main_menu->rect[leave].rectangle =
    get_rect(repo->main_menu->rect[leave].scale,
        repo->main_menu->rect[leave].pos,
        repo->main_menu->rect[leave].color);
}

void get_bar(repo_t *repo)
{
    repo->main_menu->rect[settings_bar].pos = (sfVector2f)
        {(repo->set->mode.width / 50) * 11 + (repo->set->mode.width / 128),
        (repo->set->mode.height / 50) * 32 + (repo->set->mode.height / 216)};
    repo->main_menu->rect[settings_bar].scale = (sfVector2f)
        {repo->set->mode.width / 384,
        repo->set->mode.height / 9};
    repo->main_menu->rect[settings_bar].color =
        (sfColor)sfColor_fromRGB(159, 83, 236);
    repo->main_menu->rect[settings_bar].rectangle =
    get_rect(repo->main_menu->rect[settings_bar].scale,
        repo->main_menu->rect[settings_bar].pos,
        repo->main_menu->rect[settings_bar].color);
}

void get_sound(repo_t *repo)
{
    repo->main_menu->rect[sound].pos =
        (sfVector2f){SOUND_BUTTON_X, SOUND_BUTTON_Y};
    repo->main_menu->rect[sound].scale =
        (sfVector2f){SOUND_BUTTON_SCALE_X, SOUND_BUTTON_SCALE_Y};
    repo->main_menu->rect[sound].color =
        (sfColor)sfColor_fromRGB(237, 176, 176);
    repo->main_menu->rect[sound].rectangle =
    get_rect(repo->main_menu->rect[sound].scale,
        repo->main_menu->rect[sound].pos,
        repo->main_menu->rect[sound].color);
}

void get_window_size(repo_t *repo)
{
    repo->main_menu->rect[window_size].pos =
        (sfVector2f){WINDOW_SIZE_BUTTON_X,
        WINDOW_SIZE_BUTTON_Y};
    repo->main_menu->rect[window_size].scale =
        (sfVector2f){WINDOW_SIZE_BUTTON_SCALE_X, WINDOW_SIZE_BUTTON_SCALE_Y};
    repo->main_menu->rect[window_size].color =
        (sfColor)sfColor_fromRGB(237, 176, 176);
    repo->main_menu->rect[window_size].rectangle =
    get_rect(repo->main_menu->rect[window_size].scale,
        repo->main_menu->rect[window_size].pos,
        repo->main_menu->rect[window_size].color);
}

void init_main_rect(repo_t *repo)
{
    repo->main_menu->background = get_sprite((sfVector2f){1, 0.94},
    (sfVector2f){0, 0}, sfTexture_createFromFile("assets/background2.png",
    NULL));
    get_title(repo);
    get_play(repo);
    get_continu(repo);
    get_settings(repo);
    get_leave(repo);
    get_sound(repo);
    get_window_size(repo);
    get_bar(repo);
    init_change_window(repo);
    init_change_sound(repo);
}
