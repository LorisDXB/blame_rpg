/*
** EPITECH PROJECT, 2024
** my_rph
** File description:
** enemy_hub.c
*/

#include "rpg.h"

void enemy_hub(repo_t *repo, enemy_t **enemies)
{
    if (enemies == NULL)
        return;
    for (int i = 0; enemies[i] != NULL; i++) {
        if (enemies[i]->hp > 0)
            enemy_move(repo, enemies[i]);
    }
}
