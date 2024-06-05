/*
** EPITECH PROJECT, 2024
** rpg-loryce.gode
** File description:
** change_sound
*/

#include "rpg.h"

static void get_sound_0_click(repo_t *repo, sfFloatRect rect, sfVector2i ms)
{
    if (sfFloatRect_contains(&rect, ms.x, ms.y) &&
        sfMouse_isButtonPressed(sfMouseLeft)) {
            sfSound_play(repo->musics[2]->sound);
            sfSound_setVolume(repo->musics[0]->sound, 0);
            sfSound_setVolume(repo->musics[1]->sound, 0);
    }
}

static void get_sound_25_click(repo_t *repo, sfFloatRect rect, sfVector2i ms)
{
    if (sfFloatRect_contains(&rect, ms.x, ms.y) &&
        sfMouse_isButtonPressed(sfMouseLeft)) {
            sfSound_play(repo->musics[2]->sound);
            sfSound_setVolume(repo->musics[0]->sound, 25);
            sfSound_setVolume(repo->musics[1]->sound, 25);
    }
}

static void get_sound_50_click(repo_t *repo, sfFloatRect rect, sfVector2i ms)
{
    if (sfFloatRect_contains(&rect, ms.x, ms.y) &&
        sfMouse_isButtonPressed(sfMouseLeft)) {
            sfSound_play(repo->musics[2]->sound);
            sfSound_setVolume(repo->musics[0]->sound, 50);
            sfSound_setVolume(repo->musics[1]->sound, 50);
    }
}

static void get_sound_75_click(repo_t *repo, sfFloatRect rect, sfVector2i ms)
{
    if (sfFloatRect_contains(&rect, ms.x, ms.y) &&
        sfMouse_isButtonPressed(sfMouseLeft)) {
            sfSound_play(repo->musics[2]->sound);
            sfSound_setVolume(repo->musics[0]->sound, 75);
            sfSound_setVolume(repo->musics[1]->sound, 75);
    }
}

static void get_sound_100_click(repo_t *repo, sfFloatRect rect, sfVector2i ms)
{
    if (sfFloatRect_contains(&rect, ms.x, ms.y) &&
        sfMouse_isButtonPressed(sfMouseLeft)) {
            sfSound_play(repo->musics[2]->sound);
            sfSound_setVolume(repo->musics[0]->sound, 100);
            sfSound_setVolume(repo->musics[1]->sound, 100);
    }
}

void change_sound_click(repo_t *repo, sfVector2i ms)
{
    get_sound_0_click(repo, repo->main_menu->rect[sound_0].collider, ms);
    get_sound_25_click(repo, repo->main_menu->rect[sound_25].collider, ms);
    get_sound_50_click(repo, repo->main_menu->rect[sound_50].collider, ms);
    get_sound_75_click(repo, repo->main_menu->rect[sound_75].collider, ms);
    get_sound_100_click(repo, repo->main_menu->rect[sound_100].collider, ms);
}
