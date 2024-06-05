/*
** EPITECH PROJECT, 2024
** idle_animation
** File description:
** for rpg
*/

#include "../../include/rpg.h"

static void check_last_key(sfIntRect *animation, repo_t *repo)
{
    int last_key = repo->player->key_press[4];

    if (last_key == 0)
        (*animation).top = 240;
    if (last_key == 1)
        (*animation).top = 80;
    if (last_key == 2)
        (*animation).top = 160;
    if (last_key == 3)
        (*animation).top = 0;
}

void text_machine_player(repo_t *repo, int f)
{
    int len = strlen(repo->player->text->msg);
    static int i = 0;
    char *str;
    float sec =
        sfClock_getElapsedTime(repo->player->text_c).microseconds / 1000000.0;

    if (f == 0)
        i = -1;
    if (repo->player->speak == 1) {
        if (sec >= 0.05 && i < len) {
            str = charcat(sfText_getString(repo->player->text->text),
            repo->player->text->msg[i]);
            sfText_setString(repo->player->text->text, str);
            free(str);
            sfClock_restart(repo->player->text_c);
            i++;
        }
    } else
        i = 0;
}

void player_speak_2(repo_t *repo)
{
    float sec =
        sfClock_getElapsedTime(repo->player->wait).microseconds / 1000000.0;

    if (sec >= 10) {
        if (repo->player->speak == 0) {
            free(repo->player->text->msg);
            repo->player->text->msg = string_rand("./assets/speak.txt");
            text_machine_player(repo, 0);
            sfText_setString(repo->player->text->text, "");
            sfText_setPosition(repo->player->text->text,
            (sfVector2f){repo->player->coords.x - ((strlen(
                    repo->player->text->msg) / 2) * 19),
                    repo->player->coords.y - 100});
        }
        repo->player->speak = 1;
        sfClock_restart(repo->player->wait);
    }
}

void player_speak(repo_t *repo, int *f)
{
    player_speak_2(repo);
    if (repo->player->speak == 1) {
        text_machine_player(repo, 1);
        sfRenderWindow_drawText(repo->set->w, repo->player->text->text, NULL);
    } else {
        text_machine_player(repo, 1);
        sfText_setString(repo->player->text->text, "");
    }
}

void idle_animation(repo_t *repo, int *ft)
{
    static sfIntRect animation = {0, 0, 80, 80};
    sfClock *clock = repo->player->clock;
    float sec =
        sfClock_getElapsedTime(clock).microseconds / 1000000.0;

    if (repo->player->mouve == 0 && repo->player->png_trans == 0)
        player_speak(repo, ft);
    if (sec >= 0.1 || (*ft) == 1) {
        check_last_key(&animation, repo);
        animation.left = (animation.left == 320) ? 0 : animation.left;
        sfSprite_setTextureRect(repo->player->sprite->spr, animation);
        animation.left += animation.width;
        (*ft) = 0;
        sfClock_restart(clock);
    }
}
