/*
** EPITECH PROJECT, 2024
** draw_item.c
** File description:
** draw item
*/

#include "../include/rpg.h"

static float calc_spr_to_mouse(sfVector2f playerPos, sfVector2f mousePos)
{
    float dx = mousePos.x - playerPos.x;
    float dy = mousePos.y - playerPos.y;

    return atan2(dy, dx) * 180 / M_PI;
}

void rectfollow_mouse(repo_t *repo, sfRectangleShape *rect)
{
    sfVector2i mp = sfMouse_getPositionRenderWindow(repo->set->w);
    sfVector2f sp = sfRectangleShape_getPosition(rect);
    float angle = calc_spr_to_mouse(sp,
            sfRenderWindow_mapPixelToCoords(repo->set->w, mp, NULL));

    sfRectangleShape_setRotation(rect, angle);
    return;
}

void follow_mouse(repo_t *repo, sfSprite *sprite)
{
    sfVector2i mp = sfMouse_getPositionRenderWindow(repo->set->w);
    sfVector2f sp = sfSprite_getPosition(sprite);
    float angle = calc_spr_to_mouse(sp,
        sfRenderWindow_mapPixelToCoords(repo->set->w, mp, NULL));

    sfSprite_setRotation(sprite, angle);
    return;
}

static int draw_wep(repo_t *repo)
{
    sfSprite_setPosition(repo->player->wep->spr->spr,
        (sfVector2f){repo->player->coords.x + 37,
        repo->player->coords.y + 15});
    if (repo->player->wep->an != PROC) {
        sfRectangleShape_setPosition(repo->player->wep->hitbox,
            (sfVector2f){repo->player->coords.x + 37,
            repo->player->coords.y + 15});
        sfRenderWindow_drawSprite(repo->set->w,
            repo->player->wep->spr->spr, NULL);
    }
    rectfollow_mouse(repo, repo->player->wep->hitbox);
    follow_mouse(repo, repo->player->wep->spr->spr);
    return 0;
}

static int draw_sup(repo_t *repo)
{
    sfSprite_setPosition(repo->player->sup->spr->spr,
            (sfVector2f){repo->player->coords.x,
            repo->player->coords.y + 50});
    sfRenderWindow_drawSprite(repo->set->w,
            repo->player->sup->spr->spr, NULL);
    follow_mouse(repo, repo->player->sup->spr->spr);
    return 0;
}

void draw_item(repo_t *repo)
{
    if (repo->player->eq == WEP)
        draw_wep(repo);
    if (repo->player->eq == SUP) {
        draw_sup(repo);
        return;
    }
    if (repo->player->eq == EMP)
        return;
}
