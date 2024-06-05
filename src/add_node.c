/*
** EPITECH PROJECT, 2024
** add node
** File description:
** for rpg
*/

#include "rpg.h"

void add_node(weapon_t **head, char *dicti, int id)
{
    weapon_t *tmp = *head;
    char **ctmp = str_to_array(dicti, ";");
    sprite_t *sprite = malloc(sizeof(sprite_t));

    while (tmp->next != NULL)
        tmp = tmp->next;
    sprite->spr = sfSprite_create();
    sprite->tex = sfTexture_createFromFile(ctmp[4], NULL);
    sprite->scl = (sfVector2f){3, 2};
    tmp->next = init_wep(sprite, ctmp, id);
}

void check_quests_drops(weapon_t *tmp, repo_t *repo)
{
    quest_t **quest = repo->db->quest;

    if (quest[2] && quest[2]->status == ONGOING &&
            strcmp(tmp->next->name, "Translator") == 0)
        repo->db->quest[2]->status = DONE;
    if (quest[6] && quest[6]->status == ONGOING &&
            strcmp(tmp->next->name, "Antony??") == 0)
        repo->db->quest[6]->status = DONE;
    save_quests(repo);
}

weapon_t *add_inventory_node(weapon_t **head, repo_t *repo)
{
    int rand_wep = rand() % wep_len(&(repo->db->wep));
    weapon_t *tmp = *head;

    if (tmp == NULL) {
        return wep_selector(rand_wep, &(repo->db->wep));
    }
    while (tmp->next != NULL) {
        if (tmp->id == 0) {
            tmp = tmp->next;
            continue;
        }
        tmp = tmp->next;
    }
    tmp->next = wep_selector(rand_wep, &(repo->db->wep));
    check_quests_drops(tmp, repo);
}
