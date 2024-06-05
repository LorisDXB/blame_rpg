/*
** EPITECH PROJECT, 2024
** reset_player
** File description:
** for rpg
*/

#include "../include/rpg.h"

void reset_player(repo_t *repo)
{
    repo->player->inv->content = NULL;
    repo->player->skills->agi = 0;
    repo->player->skills->str = 0;
    repo->player->skills->fort = 0;
    repo->player->skills->cha = 0;
    repo->player->skills->lvl = 0;
    repo->player->skills->pts = 0;
    repo->player->skills->xp = 0;
    save_skills(repo);
    save_inventory(repo);
}
