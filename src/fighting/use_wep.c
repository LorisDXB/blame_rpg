/*
** EPITECH PROJECT, 2024
** use_wep.c
** File description:
** use_wep.c
*/

#include "../../include/rpg.h"

static sfVector2f slash_anim_bis(sfVector2f sp, sfVector2f targetdir,
    float maxmvdist, sfVector2f target)
{
    float targetdist =
        sqrt(pow(targetdir.x, 2) + pow(targetdir.y, 2));

    if (targetdist <= maxmvdist) {
        sp.x = target.x;
        sp.y = target.y;
    } else {
        sp.x += targetdir.x / targetdist * maxmvdist;
        sp.y += targetdir.y / targetdist * maxmvdist;
    }
    return sp;
}

static void slash_anim(repo_t *repo, weapon_t *wep, float sec)
{
    sfVector2i m_p = sfMouse_getPositionRenderWindow(repo->set->w);
    sfVector2f mp = sfRenderWindow_mapPixelToCoords(repo->set->w, m_p, NULL);
    sfVector2f sp = sfSprite_getPosition(repo->player->wep->spr->spr);
    sfVector2f direction = {mp.x - sp.x, mp.y - sp.y};
    float distance = sqrt(pow(direction.x, 2) + pow(direction.y, 2));
    sfVector2f target;
    sfVector2f targetdir;
    float targetdist = 0.0;
    float maxmvdist = 0.0;

    direction.x /= distance;
    direction.y /= distance;
    target = (sfVector2f){mp.x - direction.x * 30, mp.y - direction.y * 30};
    targetdir = (sfVector2f){target.x - sp.x, target.y - sp.y};
    targetdist = sqrt(pow(targetdir.x, 2) + pow(targetdir.y, 2));
    maxmvdist = (wep->speed * 20) * sec;
    sp = slash_anim_bis(sp, targetdir, maxmvdist, target);
    sfSprite_setPosition(wep->spr->spr, sp);
    sfRectangleShape_setPosition(repo->player->wep->hitbox, sp);
    sfRenderWindow_drawSprite(repo->set->w, wep->spr->spr, NULL);
}

int use_wep(repo_t *repo)
{
    float sec =
    sfClock_getElapsedTime(repo->player->wep->clock).microseconds / 1000000.0;

    if (repo->player->wep->an != CD && repo->set->transition_request != 1 &&
        repo->set->death_request != 1) {
        if (repo->player->wep->an == OFF)
            sfClock_restart(repo->player->wep->clock);
        repo->player->wep->an = PROC;
        slash_anim(repo, repo->player->wep, sec);
    }
    m1_cd(repo);
    return 0;
}
