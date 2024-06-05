/*
** EPITECH PROJECT, 2024
** rpg-loryce.gode
** File description:
** init_text_settings
*/

#include "rpg.h"

void get_window_16_9_text(repo_t *repo)
{
    repo->main_menu->text[window_16_9_txt].pos = (sfVector2f)
        {WINDOW_16_9_X + 5, WINDOW_16_9_Y + 7};
    repo->main_menu->text[window_16_9_txt].size = WINDOW_16_9_SIZE;
    repo->main_menu->text[window_16_9_txt].msg = "1920x1080";
    repo->main_menu->text[window_16_9_txt].text = get_text_main(
        repo->main_menu->font, repo->main_menu->text[window_16_9_txt].pos,
        repo->main_menu->text[window_16_9_txt].msg,
        repo->main_menu->text[window_16_9_txt].size);
}

void get_window_4_3_text(repo_t *repo)
{
    repo->main_menu->text[window_4_3_txt].pos = (sfVector2f)
        {WINDOW_4_3_X + 5, WINDOW_4_3_Y + 7};
    repo->main_menu->text[window_4_3_txt].size = WINDOW_4_3_SIZE;
    repo->main_menu->text[window_4_3_txt].msg = "1024x768";
    repo->main_menu->text[window_4_3_txt].text = get_text_main(
        repo->main_menu->font, repo->main_menu->text[window_4_3_txt].pos,
        repo->main_menu->text[window_4_3_txt].msg,
        repo->main_menu->text[window_4_3_txt].size);
}

void init_change_window_text(repo_t *repo)
{
    get_window_16_9_text(repo);
    get_window_4_3_text(repo);
}
