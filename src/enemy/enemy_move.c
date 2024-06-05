/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** enemy_move.c
*/

#include "rpg.h"

static int same_coords(sfVector2f coords1, sfVector2f coords2)
{
    if (coords1.x == coords2.x && coords1.y == coords2.y)
        return 1;
    return 0;
}

static int in_range(sfVector2f player_pos, sfCircleShape *circle)
{
    float dist_x = player_pos.x - sfCircleShape_getPosition(circle).x;
    float dist_y = player_pos.y - sfCircleShape_getPosition(circle).y;
    float distance = sqrt(dist_x * dist_x + dist_y * dist_y);

    if (distance <= sfCircleShape_getRadius(circle))
        return 1;
    return 0;
}

static void change_pos_lifebar(enemy_t *enemy)
{
    enemy->lifebar->pos.x = sfSprite_getPosition(enemy->sprite->spr).x;
    enemy->lifebar->pos.y = sfSprite_getPosition(enemy->sprite->spr).y
        + sfTexture_getSize(enemy->sprite->tex).y / 2 / 2 + 20
            * enemy->sprite->scl.x;
    sfRectangleShape_setPosition(enemy->lifebar->back, enemy->lifebar->pos);
    sfRectangleShape_setPosition(enemy->lifebar->hp_rem, enemy->lifebar->pos);
}

static void move_to(sfClock *clock, enemy_t *enemy,
    sfVector2f coords, char **collision)
{
    float seconds = sfTime_asSeconds(sfClock_getElapsedTime(clock));
    sfVector2f en_coords = sfSprite_getPosition(enemy->sprite->spr);
    sfVector2f new_pos;
    float distance = sqrt(pow(coords.x - en_coords.x, 2)
        + pow(coords.y - en_coords.y, 2));

    new_pos.x = en_coords.x + (((coords.x - en_coords.x)
        / distance) * enemy->speed) * seconds;
    new_pos.y = en_coords.y + (((coords.y - en_coords.y)
        / distance) * enemy->speed) * seconds;
    if (collision[(int)new_pos.x / 155][(int)new_pos.y / 155] != '#') {
        enemy_anim(enemy, coords);
        sfSprite_setPosition(enemy->sprite->spr, new_pos);
        sfCircleShape_setPosition(enemy->range, new_pos);
        sfCircleShape_setPosition(enemy->detect, new_pos);
        change_pos_lifebar(enemy);
    }
}

void enemy_move(repo_t *repo, enemy_t *enemy)
{
    if (in_range(repo->player->coords, enemy->range) == 1)
        enemy_attack(repo, enemy);
    else if (in_range(repo->player->coords, enemy->detect) == 1) {
        move_to(repo->set->clock, enemy, repo->player->coords,
            repo->map->collision);
        enemy->slash->appear = 0;
        sfClock_restart(enemy->slash->cooldown);
        sfClock_restart(enemy->slash->clock);
    }
    if (in_range(repo->player->coords, enemy->detect) == 0
        && same_coords(sfSprite_getPosition(enemy->sprite->spr),
        enemy->coords) == 0) {
        move_to(repo->set->clock, enemy, enemy->coords, repo->map->collision);
        enemy->slash->appear = 0;
        sfClock_restart(enemy->slash->cooldown);
        sfClock_restart(enemy->slash->clock);
    }
    enemy_attacked(repo, enemy);
    return;
}
