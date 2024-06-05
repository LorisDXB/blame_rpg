/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** free_enemies.c
*/

#include "rpg.h"

static void destroy_slash(slash_t *slash)
{
    destroy_spritet(slash->sprite);
    sfClock_destroy(slash->cooldown);
    sfClock_destroy(slash->clock);
    free(slash);
}

static void destroy_lifebar(lifebar_t *lifebar)
{
    sfRectangleShape_destroy(lifebar->hp_rem);
    sfRectangleShape_destroy(lifebar->back);
    sfClock_destroy(lifebar->clock);
    free(lifebar);
}

static void free_enemy(enemy_t *enemy)
{
    destroy_spritet(enemy->sprite);
    sfCircleShape_destroy(enemy->range);
    sfCircleShape_destroy(enemy->detect);
    sfClock_destroy(enemy->clock);
    destroy_slash(enemy->slash);
    destroy_lifebar(enemy->lifebar);
    free(enemy);
}

void free_enemies(enemy_t **enemies)
{
    if (enemies) {
        for (int i = 0; enemies[i] != NULL; i++) {
            free_enemy(enemies[i]);
        }
        free(enemies);
    }
}
