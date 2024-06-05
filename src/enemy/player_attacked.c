/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** player_attacked.c
*/

#include "../../include/rpg.h"

static void increase_hpbar(player_t *player, int perc)
{
    sfVector2f size = {30, sfRectangleShape_getSize(player->hpbar->rem).y + 1};

    if (sfRectangleShape_getSize(player->hpbar->rem).y != perc) {
        if (sfTime_asSeconds(sfClock_getElapsedTime(player->hpbar->clock))
            > 0.002) {
            sfRectangleShape_setSize(player->hpbar->rem, size);
            sfClock_restart(player->hpbar->clock);
        }
    }
}

static void decrease_hpbar(player_t *player, int perc)
{
    sfVector2f size = {30, sfRectangleShape_getSize(player->hpbar->rem).y - 1};

    if (sfRectangleShape_getSize(player->hpbar->rem).y != perc) {
        if (sfTime_asSeconds(sfClock_getElapsedTime(player->hpbar->clock))
            > 0.002) {
            sfRectangleShape_setSize(player->hpbar->rem, size);
            sfClock_restart(player->hpbar->clock);
        }
    }
}

void change_hpbar(player_t *player)
{
    int num = player->hp;
    int perc;

    if (player->hp < 0)
        return;
    if (player->hp == 1)
        num = 0;
    perc = num / (float)player->full_hp * 415;
    if (perc > sfRectangleShape_getSize(player->hpbar->rem).y)
        increase_hpbar(player, perc);
    else
        decrease_hpbar(player, perc);
    if (perc == 0 && sfRectangleShape_getSize(player->hpbar->rem).y == perc)
        player->hp = 0;
}

static int sub_player_attacked(player_t *player)
{
    if (player->hp <= 0
        && sfRectangleShape_getSize(player->hpbar->rem).y > 0)
        player->hp = 1;
    return 0;
}

void player_attacked(repo_t *repo, enemy_t *enemy)
{
    int debounce = enemy->cd * 1000;
    sfTime elapsed;
    sfFloatRect player_bounds = sfSprite_getGlobalBounds
        (repo->player->sprite->spr);
    sfFloatRect slash_bounds = sfSprite_getGlobalBounds
        (enemy->slash->sprite->spr);

    if (sfFloatRect_intersects(&player_bounds, &slash_bounds, NULL)
        && enemy->slash->appear == 1) {
        elapsed = sfClock_getElapsedTime(repo->set->en_debounce);
        if (sfTime_asMilliseconds(elapsed) > debounce) {
            repo->player->hp -= enemy->attack;
            sub_player_attacked(repo->player);
            sfClock_restart(repo->set->en_debounce);
        }
    }
    change_hpbar(repo->player);
}
