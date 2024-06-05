/*
** EPITECH PROJECT, 2024
** m1cd
** File description:
** m1cd
*/

#include "../../include/rpg.h"

void m1_cd(repo_t *repo)
{
    float seconds = sfClock_getElapsedTime(repo->player->wep->clock)
        .microseconds / 1000000.0;

    if (seconds >= repo->player->wep->cd) {
        repo->player->wep->an = OFF;
    }
}

void dash_cd(repo_t *repo)
{
    float seconds = sfClock_getElapsedTime(repo->set->debounce)
        .microseconds / 1000000.0;

    if (seconds >= (3.0 - repo->player->skills->agi / 30.0)) {
        repo->player->dash = OFF;
    }
}
