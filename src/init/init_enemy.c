/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** init_enemy.c
*/

#include "rpg.h"

static slash_t *init_slash(void)
{
    slash_t *slash = malloc(sizeof(slash_t));

    slash->cooldown = sfClock_create();
    slash->sprite = create_spritet(CLAWS_TEX, (sfVector2f){1, 1.5});
    sfSprite_setOrigin(slash->sprite->spr, (sfVector2f){
        (sfTexture_getSize(slash->sprite->tex).x / 4) / 2,
        (sfTexture_getSize(slash->sprite->tex).y / 2) / 2});
    slash->clock = sfClock_create();
    slash->appear = 0;
    return slash;
}

static lifebar_t *init_lifebar(sprite_t *sprite)
{
    lifebar_t *lifebar = malloc(sizeof(lifebar_t));

    lifebar->pos = (sfVector2f){sfSprite_getPosition(sprite->spr).x,
        sfSprite_getPosition(sprite->spr).y + sfTexture_getSize(sprite->tex).y
        / 2 / 2 + 15 * sprite->scl.x};
    lifebar->hp_rem = create_rectangle((sfVector2f){100, 10},
        lifebar->pos, sfGreen);
    sfRectangleShape_setOrigin(lifebar->hp_rem, (sfVector2f){sfSprite_getOrigin
        (sprite->spr).x, 5});
    lifebar->back = create_rectangle((sfVector2f){100, 10},
        lifebar->pos, sfRed);
    sfRectangleShape_setOrigin(lifebar->back, (sfVector2f){sfSprite_getOrigin
        (sprite->spr).x, 5});
    lifebar->clock = sfClock_create();
    return lifebar;
}

static enemy_t *sub_en_copy(enemy_db_t *tocopy, enemy_t *enemy)
{
    enemy->range = create_circle(sfCircleShape_getRadius
        (tocopy->enemy->range), enemy->coords);
    enemy->detect = create_circle(sfCircleShape_getRadius
        (tocopy->enemy->detect), enemy->coords);
    enemy->xp_rew = tocopy->enemy->xp_rew;
    enemy->cd = tocopy->enemy->cd;
    return enemy;
}

static enemy_t *en_copy(enemy_db_t *tocopy)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));
    float randscale = (float)((rand() % 7) + 7) / 10;

    enemy->name = strdup(tocopy->enemy->name);
    enemy->coords = tocopy->enemy->coords;
    enemy->full_hp = tocopy->enemy->full_hp;
    enemy->hp = tocopy->enemy->hp;
    enemy->attack = tocopy->enemy->attack;
    enemy->speed = tocopy->enemy->speed * ((float)((rand() % 7) + 7) / 10);
    enemy->sprite = malloc(sizeof(sprite_t));
    enemy->sprite->spr = sfSprite_create();
    enemy->sprite->scl = (sfVector2f){tocopy->enemy->sprite->scl.x * randscale,
        tocopy->enemy->sprite->scl.y * randscale};
    enemy->sprite->tex = tocopy->enemy->sprite->tex;
    return sub_en_copy(tocopy, enemy);
}

static enemy_t *set_enemy(enemy_t *enemy)
{
    sfIntRect rect = {0, 0, sfTexture_getSize(enemy->sprite->tex).x / 6,
        sfTexture_getSize(enemy->sprite->tex).y / 2};

    sfSprite_setTexture(enemy->sprite->spr, enemy->sprite->tex, 0);
    sfSprite_setScale(enemy->sprite->spr, enemy->sprite->scl);
    sfSprite_setOrigin(enemy->sprite->spr, (sfVector2f){sfTexture_getSize
        (enemy->sprite->tex).x / 6 / 2, sfTexture_getSize(enemy->sprite->tex).y
        / 2 / 2});
    sfSprite_setTextureRect(enemy->sprite->spr, rect);
    enemy->slash = init_slash();
    enemy->lifebar = init_lifebar(enemy->sprite);
    enemy->clock = sfClock_create();
    return enemy;
}

enemy_t *init_enemy(enemy_db_t *enemies_db, int random)
{
    enemy_db_t *tmp = enemies_db;
    enemy_t *enemy = NULL;

    while (tmp) {
        if (tmp->id == random) {
            enemy = en_copy(tmp);
            enemy = set_enemy(enemy);
            return enemy;
        }
        tmp = tmp->next;
    }
}

enemy_t *init_enemy_db(char **info)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));

    enemy->name = strdup(info[0]);
    enemy->coords = (sfVector2f){0, 0};
    enemy->full_hp = atoi(info[1]);
    enemy->hp = atoi(info[1]);
    enemy->attack = atoi(info[2]);
    enemy->speed = atof(info[3]);
    enemy->sprite = create_spritet(info[4], (sfVector2f){atoi(info[5]),
        atoi(info[5])});
    enemy->range = create_circle(atof(info[6]), enemy->coords);
    enemy->detect = create_circle(atof(info[7]), enemy->coords);
    enemy->xp_rew = atoi(info[8]);
    enemy->cd = atof(info[9]);
    return enemy;
}
