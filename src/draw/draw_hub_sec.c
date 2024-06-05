/*
** EPITECH PROJECT, 2024
** draw_hub_sec
** File description:
** second draw hub
*/

#include "rpg.h"

void draw_item_sprites(sprite_t **ct, repo_t *repo)
{
    int mult = 0;

    for (int i = 0; ct[i] != NULL && i != 32; i++) {
        sfRenderWindow_drawSprite(repo->set->w,
                ct[i]->spr, NULL);
        sfSprite_setPosition(ct[i]->spr,
                (sfVector2f){(repo->player->coords).x - 370 + (mult * 107),
                ((repo->player->coords).y - 160) + (i / 8) * 107});
        if (mult == 7)
            mult = 0;
        else
            mult++;
    }
}

static void set_text_information(repo_t *repo, sfVector2f ms, sprite_t *item)
{
    char str[100];
    weapon_t *wep = wep_selector(item->id, &(repo->db->wep));

    sprintf(str, "name: %s\natk: %d\nrange: %d\ncd: %.1f",
        wep->name, wep->atk, wep->speed, wep->cd);
    sfRectangleShape_setPosition(repo->player->inv->rect, ms);
    sfText_setPosition(repo->player->inv->text, ms);
    sfText_setString(repo->player->inv->text, str);
    sfRenderWindow_drawRectangleShape(repo->set->w,
        repo->player->inv->rect, NULL);
    sfRenderWindow_drawText(repo->set->w, repo->player->inv->text, NULL);
    sfSprite_destroy(wep->spr->spr);
    sfRectangleShape_destroy(wep->hitbox);
    sfClock_destroy(wep->clock);
    free(wep->name);
    free(wep->spr);
    free(wep);
}

int draw_item_information(repo_t *repo)
{
    sfFloatRect rect;
    sfVector2i org = sfMouse_getPositionRenderWindow(repo->set->w);
    sfVector2f ms = sfRenderWindow_mapPixelToCoords(repo->set->w, org, NULL);

    for (int i = 0; repo->player->inv->items[i] != NULL; i++) {
        rect = sfSprite_getGlobalBounds(repo->player->inv->items[i]->spr);
        if (sfFloatRect_contains(&rect, ms.x, ms.y)) {
            set_text_information(repo, ms, repo->player->inv->items[i]);
            return 1;
        }
        check_inventory_bis(rect, ms, repo, i);
    }
    return 0;
}

static void fade_checks(repo_t *repo, int *i, int *sec_part)
{
    if ((*i) >= 255) {
        sfTexture_destroy(repo->map->sprite->tex);
        if (repo->room->index == 0)
            repo->set->despawn = 0;
        else
            repo->set->despawn = 1;
        repo->map->sprite->tex = sfTexture_createFromFile(repo->room->path,
            NULL);
        sfSprite_setTexture(repo->map->sprite->spr, repo->map->sprite->tex,
            sfFalse);
        tp_player(repo);
        (*sec_part) = 1;
    }
    if ((*i) == 0 && (*sec_part) == 1) {
        repo->set->transition_request = 0;
        (*i) = 0;
        (*sec_part) = 0;
    }
}

static int sub_fade_transition(repo_t *repo, int i, float sec, int sec_part)
{
    sfRectangleShape *rect = repo->set->transition;

    if (sec_part == 1 && sec >= 0.001 && i != 0) {
        sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(0, 0, 0, i));
        sfRectangleShape_setPosition(rect,
            sfSprite_getPosition(repo->player->sprite->spr));
        sfClock_restart(repo->set->trans_time);
        i--;
    }
    return i;
}

void fade_transition(repo_t *repo)
{
    float sec =
        sfClock_getElapsedTime(repo->set->trans_time).microseconds / 1000000.0;
    sfRectangleShape *rect = repo->set->transition;
    static int i = 0;
    static int sec_part = 0;

    fade_checks(repo, &i, &sec_part);
    if (sec_part == 0 && sec >= 0.001 && i != 255) {
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

static void draw_skills(repo_t *repo)
{
    char str[100];
    skills_t *sk = repo->player->skills;
    sfVector2f invpos = sfSprite_getPosition(repo->player->inv->spr->spr);

    sprintf(str,
        "strength: %d\n\nfortitude: %d\n\nagility: %d\n\ncharisma: %d\n\n",
        sk->str, sk->fort, sk->agi, sk->cha);
    sfText_setPosition(repo->player->skills->text,
        (sfVector2f){invpos.x + 640, invpos.y - 80});
    sfText_setString(repo->player->skills->text, str);
    sfText_setCharacterSize(repo->player->skills->text, 35);
    sfRenderWindow_drawText(repo->set->w, repo->player->skills->text, NULL);
    draw_button_sprites(sk->buttons, repo);
}

static void draw_char_info(repo_t *repo)
{
    char str[100];
    skills_t *sk = repo->player->skills;
    sfVector2f invpos = sfSprite_getPosition(repo->player->inv->spr->spr);

    sprintf(str, " number: %d  cores: %d\n\n            >points: %d<",
        sk->name, sk->lvl, sk->pts);
    sfText_setPosition(repo->player->skills->text,
        (sfVector2f){invpos.x + 640, invpos.y - 230});
    sfText_setString(repo->player->skills->text, str);
    sfText_setCharacterSize(repo->player->skills->text, 35);
    sfRenderWindow_drawText(repo->set->w, repo->player->skills->text, NULL);
}

void draw_skill_text(repo_t *repo)
{
    draw_skills(repo);
    draw_char_info(repo);
}
