/*
** EPITECH PROJECT, 2024
** view hub for rpg
** File description:
** rpg
*/

#include "rpg.h"

void handle_view(repo_t *repo)
{
    sfView_setCenter(repo->player->view, (repo->player->coords));
    sfView_setSize(repo->player->view, (sfVector2f){1920, 1080});
    sfView_zoom(repo->player->view, repo->view);
    sfRenderWindow_setView(repo->set->w, repo->player->view);
}
