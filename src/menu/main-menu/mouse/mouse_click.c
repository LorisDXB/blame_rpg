/*
** EPITECH PROJECT, 2024
** rpg-loryce.gode
** File description:
** mouse_click
*/

#include "rpg.h"

static void get_id_settings(repo_t *repo)
{
    if (repo->main_menu->id_settings == true)
        repo->main_menu->id_settings = false;
    else
        repo->main_menu->id_settings = true;
}

static void get_id_window(repo_t *repo)
{
    if (repo->main_menu->id_sound == true)
        repo->main_menu->id_sound = false;
    if (repo->main_menu->id_window_size == true)
        repo->main_menu->id_window_size = false;
    else
        repo->main_menu->id_window_size = true;
}

static void get_id_sound(repo_t *repo)
{
    if (repo->main_menu->id_window_size == true)
        repo->main_menu->id_window_size = false;
    if (repo->main_menu->id_sound == true)
        repo->main_menu->id_sound = false;
    else
        repo->main_menu->id_sound = true;
}

static void get_leave_click(repo_t *repo, sfFloatRect rect, sfVector2i ms)
{
    if (sfFloatRect_contains(&rect, ms.x, ms.y) &&
        sfMouse_isButtonPressed(sfMouseLeft)) {
        sfSound_play(repo->musics[2]->sound);
        sfRenderWindow_close(repo->set->w);
    }
}

static void get_play_click(repo_t *repo, sfFloatRect rect, sfVector2i ms)
{
    if (sfFloatRect_contains(&rect, ms.x, ms.y) &&
        sfMouse_isButtonPressed(sfMouseLeft)) {
        sfSound_play(repo->musics[2]->sound);
        repo->main_menu->id_main = true;
    }
}

void get_settings_click(repo_t *repo, sfFloatRect rect, sfVector2i ms)
{
    if (sfFloatRect_contains(&rect, ms.x, ms.y) &&
        sfMouse_isButtonPressed(sfMouseLeft)) {
        sfSound_play(repo->musics[2]->sound);
        get_id_settings(repo);
    }
}

void get_window_click(repo_t *repo, sfFloatRect rect, sfVector2i ms)
{
    if (sfFloatRect_contains(&rect, ms.x, ms.y) &&
        sfMouse_isButtonPressed(sfMouseLeft)) {
        sfSound_play(repo->musics[2]->sound);
        get_id_window(repo);
    }
}

void get_sound_click(repo_t *repo, sfFloatRect rect, sfVector2i ms)
{
    if (sfFloatRect_contains(&rect, ms.x, ms.y) &&
        sfMouse_isButtonPressed(sfMouseLeft)) {
        sfSound_play(repo->musics[2]->sound);
        get_id_sound(repo);
    }
}

void get_mouse_click(repo_t *repo, sfVector2i ms)
{
    get_play_click(repo, repo->main_menu->rect[play].collider, ms);
    get_settings_click(repo, repo->main_menu->rect[settings].collider, ms);
    get_leave_click(repo, repo->main_menu->rect[leave].collider, ms);
    if (repo->main_menu->id_settings == true) {
        get_window_click(repo,
            repo->main_menu->rect[window_size].collider, ms);
        get_sound_click(repo, repo->main_menu->rect[sound].collider, ms);
        if (repo->main_menu->id_window_size == true)
            change_window_click(repo, ms);
        if (repo->main_menu->id_sound == true)
            change_sound_click(repo, ms);
    }
}
