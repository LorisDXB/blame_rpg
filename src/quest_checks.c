/*
** EPITECH PROJECT, 2024
** quest checks
** File description:
** for rpg
*/

#include "../include/rpg.h"

void quest_checks(repo_t *repo)
{
    if (repo->player->skills->lvl >= 5) {
        repo->db->quest[3]->status = DONE;
        if (repo->player->skills->lvl == 5)
            repo->player->skills->xp += repo->db->quest[3]->xp_rew;
    }
    if (repo->player->skills->lvl >= 10) {
        repo->db->quest[4]->status = DONE;
        if (repo->player->skills->lvl == 10)
            repo->player->skills->xp += repo->db->quest[4]->xp_rew;
    }
    if (repo->player->skills->lvl >= 20) {
        repo->db->quest[5]->status = DONE;
        if (repo->player->skills->lvl == 20)
            repo->player->skills->xp += 0;
    }
}
