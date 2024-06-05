/*
** EPITECH PROJECT, 2024
** show_list
** File description:
** blabla
*/

#include "../include/rpg.h"

void show_list(weapon_t **head)
{
    weapon_t *tmp = *head;

    while (tmp != NULL) {
        if (tmp->atk == 0)
            tmp = tmp->next;
        printf("id: %d\n, atk: %d\n, cd: %f\n spd %d\n",
            tmp->id, tmp->atk, tmp->cd, tmp->speed);
        tmp = tmp->next;
    }
}

void show_qu_list(quest_t **list)
{
    for (int i = 0; list[i] != NULL; i++) {
        printf("goal: %s\n", list[i]->goal);
    }
}
