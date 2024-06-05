/*
** EPITECH PROJECT, 2024
** rpg-loryce.gode
** File description:
** init_text_sound
*/

#include "rpg.h"

static void get_sound_0_text(repo_t *repo)
{
    repo->main_menu->text[sound_0_txt].pos = (sfVector2f)
        {SOUND_0_X + 5, SOUND_0_Y + 7};
    repo->main_menu->text[sound_0_txt].size = SOUND_0_SIZE;
    repo->main_menu->text[sound_0_txt].msg = "0%";
    repo->main_menu->text[sound_0_txt].text = get_text_main(
        repo->main_menu->font, repo->main_menu->text[sound_0_txt].pos,
        repo->main_menu->text[sound_0_txt].msg,
        repo->main_menu->text[sound_0_txt].size);
}

static void get_sound_25_text(repo_t *repo)
{
    repo->main_menu->text[sound_25_txt].pos = (sfVector2f)
        {SOUND_25_X + 5, SOUND_25_Y + 7};
    repo->main_menu->text[sound_25_txt].size = SOUND_25_SIZE;
    repo->main_menu->text[sound_25_txt].msg = "25%";
    repo->main_menu->text[sound_25_txt].text = get_text_main(
        repo->main_menu->font, repo->main_menu->text[sound_25_txt].pos,
        repo->main_menu->text[sound_25_txt].msg,
        repo->main_menu->text[sound_25_txt].size);
}

static void get_sound_50_text(repo_t *repo)
{
    repo->main_menu->text[sound_50_txt].pos = (sfVector2f){
        SOUND_50_X + 5, SOUND_50_Y + 7};
    repo->main_menu->text[sound_50_txt].size = SOUND_50_SIZE;
    repo->main_menu->text[sound_50_txt].msg = "50%";
    repo->main_menu->text[sound_50_txt].text = get_text_main(
        repo->main_menu->font, repo->main_menu->text[sound_50_txt].pos,
        repo->main_menu->text[sound_50_txt].msg,
        repo->main_menu->text[sound_50_txt].size);
}

static void get_sound_75_text(repo_t *repo)
{
    repo->main_menu->text[sound_75_txt].pos = (sfVector2f)
        {SOUND_75_X + 5, SOUND_75_Y + 7};
    repo->main_menu->text[sound_75_txt].size = SOUND_75_SIZE;
    repo->main_menu->text[sound_75_txt].msg = "75%";
    repo->main_menu->text[sound_75_txt].text = get_text_main(
        repo->main_menu->font, repo->main_menu->text[sound_75_txt].pos,
        repo->main_menu->text[sound_75_txt].msg,
        repo->main_menu->text[sound_75_txt].size);
}

static void get_sound_100_text(repo_t *repo)
{
    repo->main_menu->text[sound_100_txt].pos = (sfVector2f)
        {SOUND_100_X + 5, SOUND_100_Y + 7};
    repo->main_menu->text[sound_100_txt].size = SOUND_100_SIZE;
    repo->main_menu->text[sound_100_txt].msg = "100%";
    repo->main_menu->text[sound_100_txt].text = get_text_main(
        repo->main_menu->font, repo->main_menu->text[sound_100_txt].pos,
        repo->main_menu->text[sound_100_txt].msg,
        repo->main_menu->text[sound_100_txt].size);
}

void init_change_sound_text(repo_t *repo)
{
    get_sound_0_text(repo);
    get_sound_25_text(repo);
    get_sound_50_text(repo);
    get_sound_75_text(repo);
    get_sound_100_text(repo);
}
