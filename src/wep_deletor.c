/*
** EPITECH PROJECT, 2024
** wep_deletor
** File description:
** wep_dleetor
*/

#include "../include/rpg.h"

void del_bis(weapon_t **head, weapon_t *tmp, weapon_t *prev)
{
    if (prev == NULL) {
        *head = tmp->next;
        free(tmp);
    } else {
        prev->next = tmp->next;
        free(tmp);
    }
}

void wep_deletor(weapon_t **head, int id)
{
    weapon_t *tmp = *head;
    weapon_t *prev = NULL;

    while (tmp != NULL) {
        if (tmp->id == id) {
            del_bis(head, tmp, prev);
            return;
        }
        prev = tmp;
        tmp = tmp->next;
    }
}

void wep_deletor_index(weapon_t **head, int index)
{
    weapon_t *tmp = *head;
    weapon_t *prev = NULL;
    int i = 1;

    while (tmp != NULL) {
        if (index == i) {
            del_bis(head, tmp, prev);
            return;
        }
        i++;
        prev = tmp;
        tmp = tmp->next;
    }
    perror("get_list_index");
    return;
}
