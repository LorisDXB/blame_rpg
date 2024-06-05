/*
** EPITECH PROJECT, 2024
** death_transition.c
** File description:
** for rpg
*/

#include "../../include/rpg.h"

static void fade_checks(repo_t *repo, int *i, int *sec_part)
{
    if ((*i) >= 255) {
        repo->room_past = repo->room->index;
        repo->room = go_to_room(&(repo->full_dongeons), 0);
        coll_update(repo);
        repo->player->coords = (sfVector2f){6200, 5400};
        sfTexture_destroy(repo->map->sprite->tex);
        repo->map->sprite->tex = sfTexture_createFromFile(repo->room->path,
            NULL);
        sfSprite_setTexture(repo->map->sprite->spr, repo->map->sprite->tex,
            sfFalse);
        repo->set->despawn = 0;
        reset_player(repo);
        (*sec_part) = 1;
    }
    if ((*i) == 0 && (*sec_part) == 1) {
        repo->set->death_request = 0;
        repo->player->hp = repo->player->full_hp;
        (*i) = 0;
        (*sec_part) = 0;
    }
}

static int sub_fade_transition(repo_t *repo, int i, float sec, int sec_part)
{
    sfRectangleShape *rect = repo->set->transition;

    if (sec_part == 1 && sec >= 0.01 && i != 0) {
        sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(0, 0, 0, i));
        sfRectangleShape_setPosition(rect,
                sfSprite_getPosition(repo->player->sprite->spr));
        sfClock_restart(repo->set->trans_time);
        i--;
    }
    return i;
}

void death_transition(repo_t *repo)
{
    float sec =
        sfClock_getElapsedTime(repo->set->trans_time).microseconds / 1000000.0;
    sfRectangleShape *rect = repo->set->transition;
    static int i = 0;
    static int sec_part = 0;

    fade_checks(repo, &i, &sec_part);
    if (sec_part == 0 && sec >= 0.02 && i != 255) {
        sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(0, 0, 0, i));
        sfRectangleShape_setPosition(rect,
                sfSprite_getPosition(repo->player->sprite->spr));
        sfClock_restart(repo->set->trans_time);
        i++;
    }
    i = sub_fade_transition(repo, i, sec, sec_part);
    sfRenderWindow_drawRectangleShape(repo->set->w,
            repo->set->transition, NULL);
    sfRenderWindow_drawRectangleShape(repo->set->w, repo->set->transition,
            NULL);
}
