/*
** EPITECH PROJECT, 2024
** exp_calculation
** File description:
** for rpg
*/

#include "../include/rpg.h"

int exp_calc(repo_t *repo)
{
    int xp_req = 100 * repo->player->skills->lvl;

    if (repo->player->skills->xp >= xp_req && repo->player->skills->lvl < 20) {
        repo->player->skills->xp -= xp_req;
        repo->player->skills->lvl += 1;
        repo->player->skills->pts += 5;
    }
    return 0;
}
