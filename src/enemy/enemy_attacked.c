/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** enemy_attacked.c
*/

#include "rpg.h"

static void change_lifebar(enemy_t *enemy, repo_t *repo)
{
    int num = enemy->hp;
    int pe;

    if (enemy->hp == 1)
        num = 0;
    pe = num / (float)enemy->full_hp * 100;
    if (sfRectangleShape_getSize(enemy->lifebar->hp_rem).x != pe) {
        if (sfTime_asSeconds(sfClock_getElapsedTime(enemy->lifebar->clock))
            > 0.02) {
            sfRectangleShape_setSize(enemy->lifebar->hp_rem, (sfVector2f)
                {sfRectangleShape_getSize(enemy->lifebar->hp_rem).x - 1, 10});
            sfClock_restart(enemy->lifebar->clock);
        }
    }
    if (pe == 0 && sfRectangleShape_getSize(enemy->lifebar->hp_rem).x == pe) {
        post_death(enemy, repo);
    }
}

static int sub_enemy_attacked(enemy_t *enemy)
{
    if (enemy->hp <= 0
        && sfRectangleShape_getSize(enemy->lifebar->hp_rem).x > 0)
        enemy->hp = 1;
    return 0;
}

int enemy_attacked(repo_t *repo, enemy_t *enemy)
{
    float stat = (float)repo->player->skills->str / 2;
    int debounce = repo->player->wep->cd * 1000;
    sfTime elapsed;
    sfFloatRect sprite_bounds = sfSprite_getGlobalBounds(enemy->sprite->spr);
    sfFloatRect rect =
        sfRectangleShape_getGlobalBounds(repo->player->wep->hitbox);

    if (sfFloatRect_intersects(&rect, &sprite_bounds, NULL) &&
        repo->player->wep->an == PROC) {
        elapsed = sfClock_getElapsedTime(repo->set->debounce);
        if (sfTime_asMilliseconds(elapsed) > debounce) {
            enemy->hp -= repo->player->wep->atk + stat;
            sub_enemy_attacked(enemy);
            sfClock_restart(repo->set->debounce);
        }
    }
    change_lifebar(enemy, repo);
    return 0;
}
