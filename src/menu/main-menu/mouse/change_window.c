/*
** EPITECH PROJECT, 2024
** rpg-loryce.gode
** File description:
** change_window
*/

#include "rpg.h"

void get_16_9_click(repo_t *repo, sfFloatRect rect, sfVector2i ms)
{
    if (sfFloatRect_contains(&rect, ms.x, ms.y) &&
        sfMouse_isButtonPressed(sfMouseLeft)) {
            sfSound_play(repo->musics[2]->sound);
            repo->set->mode.width = 1920;
            repo->set->mode.height = 1080;
            sfRenderWindow_close(repo->set->w);
            repo->set->w = sfRenderWindow_create(repo->set->mode, "BLAME!",
                sfResize | sfClose, NULL);
            init_main_rect(repo);
            init_all_text(repo);
            sfView_setSize(repo->player->view, (sfVector2f){1920, 1080});
    }
}

void get_4_3_click(repo_t *repo, sfFloatRect rect, sfVector2i ms)
{
    if (sfFloatRect_contains(&rect, ms.x, ms.y) &&
        sfMouse_isButtonPressed(sfMouseLeft)) {
            sfSound_play(repo->musics[2]->sound);
            repo->set->mode.width = 1024;
            repo->set->mode.height = 768;
            sfRenderWindow_close(repo->set->w);
            repo->set->w = sfRenderWindow_create(repo->set->mode, "BLAME!",
                sfResize | sfClose, NULL);
            init_main_rect(repo);
            init_all_text(repo);
            sfView_setSize(repo->player->view, (sfVector2f){1024, 768});
    }
}

void change_window_click(repo_t *repo, sfVector2i mouse)
{
    get_16_9_click(repo, repo->main_menu->rect[window_16_9].collider, mouse);
    get_4_3_click(repo, repo->main_menu->rect[window_4_3].collider, mouse);
}
