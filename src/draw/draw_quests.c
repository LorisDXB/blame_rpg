/*
** EPITECH PROJECT, 2024
** draw_quests
** File description:
** for rpg
*/

#include "../../include/rpg.h"

void draw_quests(repo_t *repo)
{
    sfVector2f pc = repo->player->coords;
    quest_t **quest = repo->db->quest;
    float mult = 0.5;

    for (int i = 0; quest[i] != NULL; i++) {
        if (quest[i]->status == DONE)
            sfText_setColor(quest[i]->txt, sfGreen);
        if (quest[i]->status != NOTFOUND || quest[i]->xp_rew == 0) {
            sfText_setPosition(quest[i]->txt,
                (sfVector2f){pc.x - 1200, pc.y + (200 * mult)});
            sfRenderWindow_drawText(repo->set->w, quest[i]->txt, NULL);
            mult += 0.3;
        }
    }
}
