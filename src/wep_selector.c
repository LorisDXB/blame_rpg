/*
** EPITECH PROJECT, 2024
** wep_selector.c
** File description:
** select a weapon from db
*/

#include "../include/rpg.h"

void set_weapon(weapon_t *tmp)
{
    sfFloatRect bounds = {0, 0};

    sfSprite_setTexture(tmp->spr->spr, tmp->spr->tex, 0);
    sfSprite_setScale(tmp->spr->spr, tmp->spr->scl);
    bounds = sfSprite_getLocalBounds(tmp->spr->spr);
    sfSprite_setOrigin(tmp->spr->spr,
        (sfVector2f){bounds.width / 7, bounds.height / 2});
    tmp->hitbox = wep_hitbox_gen(tmp);
    tmp->clock = sfClock_create();
}

static weapon_t *wep_copy(weapon_t *tocopy)
{
    weapon_t *copy = malloc(sizeof(weapon_t));

    copy->id = tocopy->id;
    copy->spr = malloc(sizeof(sprite_t));
    copy->spr->spr = sfSprite_create();
    copy->spr->scl = tocopy->spr->scl;
    copy->spr->tex = tocopy->spr->tex;
    copy->atk = tocopy->atk;
    copy->name = strdup(tocopy->name);
    copy->speed = tocopy->speed;
    copy->cd = tocopy->cd;
    copy->hitbox = NULL;
    copy->clock = NULL;
    copy->an = OFF;
    copy->next = NULL;
    return copy;
}

weapon_t *wep_selector(int id, weapon_t **head)
{
    weapon_t *tmp = *head;
    weapon_t *ret = NULL;

    if (id == 0)
        id = 1;
    while (tmp != NULL) {
        if (tmp->id == id && id != 0) {
            ret = wep_copy(tmp);
            set_weapon(ret);
            return ret;
        }
        tmp = tmp->next;
    }
    perror("wep_selector");
    return NULL;
}

weapon_t *get_list_index(weapon_t **head, int index)
{
    weapon_t *tmp = *head;
    weapon_t *ret = NULL;
    int i = 1;

    if (index == 1) {
        ret = wep_copy(tmp);
        return ret;
    }
    while (tmp != NULL) {
        if (index == i) {
            ret = wep_copy(tmp);
            return ret;
        }
        i++;
        tmp = tmp->next;
    }
    perror("get_list_index");
    return NULL;
}
