/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** enemy_attacks.c
*/

#include "rpg.h"
#include <time.h>

static void attack_anim(enemy_t *enemy, sfRenderWindow *win)
{
    sfIntRect rect = sfSprite_getTextureRect(enemy->slash->sprite->spr);
    float time;

    if (enemy->slash->appear == 0)
        sfClock_restart(enemy->slash->clock);
    enemy->slash->appear = 1;
    if (sfTime_asSeconds(sfClock_getElapsedTime(enemy->slash->clock)) < 0.4) {
        time = sfTime_asSeconds(sfClock_getElapsedTime(enemy->slash->clock));
        if (time > 0.1 && time < 0.2)
            rect.left = 40.5;
        if (time > 0.2 && time < 0.3)
            rect.left = 40.5 * 2;
        if (time > 0.3)
            rect.left = 40.5 * 3;
        sfSprite_setTextureRect(enemy->slash->sprite->spr, rect);
    } else {
        enemy->slash->appear = 0;
        sfClock_restart(enemy->slash->cooldown);
    }
}

static void enemy_attack_anim(enemy_t *enemy, sfVector2f player_pos,
    sfRenderWindow *win)
{
    sfVector2f enemy_pos = sfSprite_getPosition(enemy->sprite->spr);
    float elapsed;

    if (player_pos.x < enemy_pos.x) {
        sfSprite_setTextureRect(enemy->slash->sprite->spr,
            (sfIntRect){0, 53, 40.5, 53});
        enemy_pos.x -= 50;
        sfSprite_setPosition(enemy->slash->sprite->spr, player_pos);
        attack_anim(enemy, win);
    } else if (player_pos.x > enemy_pos.x) {
        sfSprite_setTextureRect(enemy->slash->sprite->spr,
            (sfIntRect){0, 0, 40.5, 53});
        enemy_pos.x += 50;
        sfSprite_setPosition(enemy->slash->sprite->spr, player_pos);
        attack_anim(enemy, win);
    }
}

void enemy_attack(repo_t *repo, enemy_t *enemy)
{
    float seconds =
        sfTime_asSeconds(sfClock_getElapsedTime(enemy->slash->cooldown));

    if (seconds > enemy->cd) {
        enemy_attack_anim(enemy, repo->player->coords, repo->set->w);
        if (repo->player->hp > 0);
        player_attacked(repo, enemy);
    }
    return;
}
