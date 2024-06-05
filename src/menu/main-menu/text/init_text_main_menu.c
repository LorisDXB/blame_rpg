/*
** EPITECH PROJECT, 2024
** rpg-loryce.gode
** File description:
** init_text_main_menu
*/

#include "rpg.h"

static void get_title_text(repo_t *repo)
{
    repo->main_menu->text[title_txt].pos = (sfVector2f)
        {TITLE_X + 100, TITLE_Y + 35};
    repo->main_menu->text[title_txt].size = TITLE_SIZE;
    repo->main_menu->text[title_txt].msg = "BLAME!";
    repo->main_menu->text[title_txt].text = get_text_main(
        repo->main_menu->font, repo->main_menu->text[title_txt].pos,
        repo->main_menu->text[title_txt].msg,
        repo->main_menu->text[title_txt].size);
}

static void get_play_text(repo_t *repo)
{
    repo->main_menu->text[play_txt].pos = (sfVector2f)
        {PLAY_BUTTON_X + 5, PLAY_BUTTON_Y + 10};
    repo->main_menu->text[play_txt].size = PLAY_SIZE;
    repo->main_menu->text[play_txt].msg = "Play";
    repo->main_menu->text[play_txt].text = get_text_main(
        repo->main_menu->font, repo->main_menu->text[play_txt].pos,
        repo->main_menu->text[play_txt].msg,
        repo->main_menu->text[play_txt].size);
}

static void get_continu_text(repo_t *repo)
{
    repo->main_menu->text[continu_txt].pos = (sfVector2f)
        {CONTINUE_BUTTON_X + 5, CONTINUE_BUTTON_Y + 7};
    repo->main_menu->text[continu_txt].size = CONTINUE_SIZE;
    repo->main_menu->text[continu_txt].msg = "Continue";
    repo->main_menu->text[continu_txt].text = get_text_main(
        repo->main_menu->font, repo->main_menu->text[continu_txt].pos,
        repo->main_menu->text[continu_txt].msg,
        repo->main_menu->text[continu_txt].size);
}

static void get_settings_text(repo_t *repo)
{
    repo->main_menu->text[settings_txt].pos = (sfVector2f)
        {SETTING_BUTTON_X + 5, SETTING_BUTTON_Y + 7};
    repo->main_menu->text[settings_txt].size = SETTINGS_SIZE;
    repo->main_menu->text[settings_txt].msg = "Settings";
    repo->main_menu->text[settings_txt].text = get_text_main(
        repo->main_menu->font, repo->main_menu->text[settings_txt].pos,
        repo->main_menu->text[settings_txt].msg,
        repo->main_menu->text[settings_txt].size);
}

static void get_leave_text(repo_t *repo)
{
    repo->main_menu->text[leave_txt].pos = (sfVector2f)
        {LEAVE_BUTTON_X + 16, LEAVE_BUTTON_Y + 7};
    repo->main_menu->text[leave_txt].size = LEAVE_SIZE;
    repo->main_menu->text[leave_txt].msg = "Leave";
    repo->main_menu->text[leave_txt].text = get_text_main(
        repo->main_menu->font, repo->main_menu->text[leave_txt].pos,
        repo->main_menu->text[leave_txt].msg,
        repo->main_menu->text[leave_txt].size);
}

void get_sound_text(repo_t *repo)
{
    repo->main_menu->text[sound_txt].pos = (sfVector2f)
        {SOUND_BUTTON_X + 5, SOUND_BUTTON_Y + 7};
    repo->main_menu->text[sound_txt].size = SOUND_SIZE;
    repo->main_menu->text[sound_txt].msg = "Sound";
    repo->main_menu->text[sound_txt].text = get_text_main(
        repo->main_menu->font, repo->main_menu->text[sound_txt].pos,
        repo->main_menu->text[sound_txt].msg,
        repo->main_menu->text[sound_txt].size);
}

void get_window_change_text(repo_t *repo)
{
    repo->main_menu->text[window_size_txt].pos = (sfVector2f)
        {WINDOW_SIZE_BUTTON_X + 5, WINDOW_SIZE_BUTTON_Y + 7};
    repo->main_menu->text[window_size_txt].size = WINDOW_SIZE_SIZE;
    repo->main_menu->text[window_size_txt].msg = "Resolution";
    repo->main_menu->text[window_size_txt].text = get_text_main(
        repo->main_menu->font, repo->main_menu->text[window_size_txt].pos,
        repo->main_menu->text[window_size_txt].msg,
        repo->main_menu->text[window_size_txt].size);
}

void init_all_text(repo_t *repo)
{
    get_title_text(repo);
    get_play_text(repo);
    get_continu_text(repo);
    get_settings_text(repo);
    get_leave_text(repo);
    get_sound_text(repo);
    get_window_change_text(repo);
    init_change_window_text(repo);
    init_change_sound_text(repo);
}

sfText *get_text_main(sfFont *font, sfVector2f pos,
    char *msg, unsigned int size)
{
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setPosition(text, pos);
    sfText_setString(text, msg);
    sfText_setFillColor(text, sfColor_fromRGB(188, 19, 254));
    sfText_setCharacterSize(text, size);
    return text;
}
