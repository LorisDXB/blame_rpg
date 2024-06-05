/*
** EPITECH PROJECT, 2024
** movement keys
** File description:
** for rpg
*/

#include "../../include/rpg.h"

static void movement_up(repo_t *repo, int y, int x, int ck)
{
    float stat = (float)repo->player->skills->agi / 50;

    if (sfKeyboard_isKeyPressed(sfKeyZ) && ck != 1 &&
            (repo->map->collision[y - 1][x] != '#')) {
        repo->player->coords.y -= (P_YSPEED) + stat;
        repo->player->key_press[0] = true;
        repo->player->key_press[4] = 0;
        repo->paral->coo.y -= (P_YSPEED) * 2 + stat;
        sfSprite_setPosition(repo->paral->back->spr, repo->paral->coo);
        repo->player->speak = 0;
        repo->player->mouve = 1;
    }
}

static void movement_left(repo_t *repo, int y, int x, int ck)
{
    float stat = (float)repo->player->skills->agi / 50;

    if (sfKeyboard_isKeyPressed(sfKeyQ) && ck != 1 &&
            repo->map->collision[y][x - 1] != '#') {
        repo->player->coords.x -= (P_XSPEED) + stat;
        repo->player->key_press[1] = true;
        repo->player->key_press[4] = 1;
        repo->paral->coo.x -= (P_XSPEED) * 2 + stat;
        sfSprite_setPosition(repo->paral->back->spr, repo->paral->coo);
        repo->player->speak = 0;
        repo->player->mouve = 1;
    }
}

static void movement_right(repo_t *repo, int y, int x, int ck)
{
    float stat = (float)repo->player->skills->agi / 50;

    if (sfKeyboard_isKeyPressed(sfKeyD) && ck != 1 &&
            repo->map->collision[y][x + 1] != '#') {
        repo->player->coords.x += (P_XSPEED) + stat;
        repo->player->key_press[3] = true;
        repo->player->key_press[4] = 3;
        repo->paral->coo.x += (P_XSPEED) * 2 + stat;
        sfSprite_setPosition(repo->paral->back->spr, repo->paral->coo);
        repo->player->speak = 0;
        repo->player->mouve = 1;
    }
}

static void movement_down(repo_t *repo, int y, int x, int ck)
{
    float stat = (float)repo->player->skills->agi / 50;

    if (sfKeyboard_isKeyPressed(sfKeyS) && ck != 1 &&
            repo->map->collision[y + 1][x] != '#') {
        repo->player->coords.y += (P_YSPEED) + stat;
        repo->player->key_press[2] = true;
        repo->player->key_press[4] = 2;
        repo->paral->coo.y += (P_YSPEED) * 2 + stat;
        sfSprite_setPosition(repo->paral->back->spr, repo->paral->coo);
        repo->player->speak = 0;
        repo->player->mouve = 1;
    }
}

void movement_keys(repo_t *repo, int ck, int y, int x)
{
    movement_up(repo, y, x, ck);
    movement_right(repo, y, x, ck);
    movement_down(repo, y, x, ck);
    movement_left(repo, y, x, ck);
}
