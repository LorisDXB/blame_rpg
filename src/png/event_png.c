/*
** EPITECH PROJECT, 2024
** gitaction-mirror
** File description:
** event_png
*/

#include "rpg.h"

void zone_png(repo_t *repo)
{
    sfVector2f dire = (sfVector2f){repo->room->png->pos.x -
    repo->player->coords.x, repo->room->png->pos.y - repo->player->coords.y};
    float distance = sqrt(pow(dire.x, 2) + pow(dire.y, 2));

    if (distance <= 500)
        repo->room->png->affiche = 1;
    else {
        repo->room->png->affiche = -1;
        repo->room->png->space = -1;
    }
}

void event_png(sfRenderWindow *window, sfEvent event, repo_t *repo)
{
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeySpace && repo->room->png->affiche == 1) {
            repo->room->png->space *= -1;
            free(repo->room->png->text->msg);
            repo->room->png->text->msg = string_rand("./assets/sentence.txt");
            sfText_setPosition(repo->room->png->text->text,
            (sfVector2f){repo->room->png->pos.x - ((strlen(
                repo->room->png->text->msg) / 2) * 19),
                repo->room->png->pos.y - ((832 / 26) * 5)});
            sfSound_play(repo->room->png->sound->sound);
        }
    }
}
