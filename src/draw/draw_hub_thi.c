/*
** EPITECH PROJECT, 2024
** draw_hub third
** File description:
** for rpg
*/

#include "rpg.h"

void draw_button_sprites(sprite_t **ct, repo_t *repo)
{
    int mult = 0;

    for (int i = 0; ct[i] != NULL; i++) {
        sfRenderWindow_drawSprite(repo->set->w,
            ct[i]->spr, NULL);
        sfSprite_setPosition(ct[i]->spr,
            (sfVector2f){(repo->player->coords).x + 880,
            ((repo->player->coords).y - 65) + i * 65});
    }
}

void draw_hover(repo_t *repo, sfSprite *button)
{
    sfRectangleShape *hover = repo->player->skills->hover;
    sfVector2f b_pos = sfSprite_getPosition(button);

    sfRenderWindow_drawRectangleShape(repo->set->w, hover, NULL);
    sfRectangleShape_setPosition(hover, b_pos);
}

static void fade_checks(repo_t *repo, int *i, int *sec_part)
{
    if ((*i) >= 255) {
        (*sec_part) = 1;
    }
    if ((*i) == 0 && (*sec_part) == 1) {
        repo->player->inv->drop_ck = 0;
        (*i) = 0;
        (*sec_part) = 0;
    }
}

static int sub_fade_transition(repo_t *repo, int i, float sec, int sec_part)
{
    sfText *txt = repo->player->inv->drop;

    if (sec_part == 1 && sec >= 0.005 && i != 0) {
        sfText_setColor(txt, sfColor_fromRGBA(255, 255, 255, i));
        sfText_setPosition(txt, (sfVector2f){repo->player->coords.x - 170,
            repo->player->coords.y - 200});
        sfClock_restart(repo->set->trans_time);
        i--;
    }
    return i;
}

void dropped_weapon(repo_t *repo)
{
    float sec =
        sfClock_getElapsedTime(repo->set->trans_time).microseconds / 1000000.0;
    sfText *txt = repo->player->inv->drop;
    static int i = 0;
    static int sec_part = 0;

    fade_checks(repo, &i, &sec_part);
    if (sec_part == 0 && sec >= 0.005 && i != 255) {
        sfText_setColor(txt, sfColor_fromRGBA(255, 255, 255, i));
        sfText_setPosition(txt, (sfVector2f){repo->player->coords.x - 170,
            repo->player->coords.y - 200});
        sfClock_restart(repo->set->trans_time);
        i++;
    }
    i = sub_fade_transition(repo, i, sec, sec_part);
    sfRenderWindow_drawText(repo->set->w, repo->player->inv->drop, NULL);
}
