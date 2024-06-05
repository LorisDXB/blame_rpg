/*
** EPITECH PROJECT, 2024
** wep_len
** File description:
** for rpg
*/

#include "../include/rpg.h"

int wep_len(weapon_t **head)
{
    weapon_t *tmp = *head;
    int ct = 1;

    while (tmp != NULL) {
        if (tmp->id < 0) {
            tmp = tmp->next;
            continue;
        }
        ct++;
        tmp = tmp->next;
    }
    return ct - 1;
}
