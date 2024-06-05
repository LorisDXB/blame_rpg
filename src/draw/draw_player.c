/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** draw_player.c
*/

#include "../../include/rpg.h"

static void change_pos_bars(player_t *player)
{
    sfSprite_setPosition(player->hpbar->sprite->spr,
        (sfVector2f){sfSprite_getPosition(player->sprite->spr).x - 1100,
        sfSprite_getPosition(player->sprite->spr).y + 370});
    sfRectangleShape_setPosition(player->hpbar->back,
        (sfVector2f){sfSprite_getPosition(player->sprite->spr).x - 1070,
        sfSprite_getPosition(player->sprite->spr).y + 542});
    sfRectangleShape_setPosition(player->hpbar->rem,
        (sfVector2f){sfSprite_getPosition(player->sprite->spr).x - 1070,
        sfSprite_getPosition(player->sprite->spr).y + 542});
    sfSprite_setPosition(player->xpbar->sprite->spr,
        (sfVector2f){sfSprite_getPosition(player->sprite->spr).x - 1000,
        sfSprite_getPosition(player->sprite->spr).y + 370});
    sfRectangleShape_setPosition(player->xpbar->back,
        (sfVector2f){sfSprite_getPosition(player->sprite->spr).x - 970,
        sfSprite_getPosition(player->sprite->spr).y + 542});
    sfRectangleShape_setPosition(player->xpbar->rem,
        (sfVector2f){sfSprite_getPosition(player->sprite->spr).x - 970,
        sfSprite_getPosition(player->sprite->spr).y + 542});
}

void affiche_help(repo_t *repo)
{
    if (repo->help->show == 1) {
        sfSprite_setPosition(repo->help->sprite->spr, repo->player->coords);
        sfRenderWindow_drawSprite(repo->set->w, repo->help->sprite->spr, NULL);
    }
}

void draw_bars(sfRenderWindow *win, player_t *player)
{
    change_pos_bars(player);
    sfRenderWindow_drawRectangleShape(win, player->hpbar->back, NULL);
    sfRenderWindow_drawRectangleShape(win, player->hpbar->rem, NULL);
    sfRenderWindow_drawSprite(win, player->hpbar->sprite->spr, NULL);
    sfRenderWindow_drawRectangleShape(win, player->xpbar->back, NULL);
    sfRenderWindow_drawRectangleShape(win, player->xpbar->rem, NULL);
    sfRenderWindow_drawSprite(win, player->xpbar->sprite->spr, NULL);
}

static void sub_draw_player(repo_t *repo, player_t *p, sprite_t *pspr)
{
    if (repo->player->hp <= 0) {
        sfSprite_setTexture(pspr->spr, p->death, 0);
        death_animation(repo);
    }
    sfRenderWindow_drawSprite(repo->set->w, repo->player->sprite->spr, NULL);
    sfSprite_setPosition(repo->player->sprite->spr, (repo->player->coords));
}

void draw_player(repo_t *repo)
{
    int *kp = repo->player->key_press;
    player_t *p = repo->player;
    sprite_t *pspr = repo->player->sprite;
    static int ft = 0;

    if (p->hp > 0) {
        if (kp[0] == 0 && kp[1] == 0 && kp[2] == 0 && kp[3] == 0) {
            sfSprite_setTexture(pspr->spr, pspr->tex, 0);
            repo->player->mouve = 0;
            idle_animation(repo, &ft);
        } else {
            ft = 1;
            sfSprite_setTexture(pspr->spr, repo->player->run, 0);
            run_animation(repo);
        }
    }
    sub_draw_player(repo, p, pspr);
}
