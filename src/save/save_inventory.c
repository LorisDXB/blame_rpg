/*
** EPITECH PROJECT, 2024
** save inventory
** File description:
** save for rpg
*/

#include "../../include/rpg.h"

static char *fill_invdata(weapon_t **head, int total_length)
{
    char *invdata = malloc(sizeof(char) * (total_length + 1));
    weapon_t *tmp = *head;
    char buffer[30];

    invdata[0] = '\0';
    while (tmp != NULL) {
        sprintf(buffer, "%d;", tmp->id);
        strcat(invdata, buffer);
        tmp = tmp->next;
    }
    return invdata;
}

static char *get_inv_data(weapon_t **head)
{
    weapon_t *tmp = *head;
    int len = wep_len(head);
    char *invdata = NULL;
    int total_length = 0;

    if (len == 0)
        return NULL;
    while (tmp != NULL) {
        total_length += snprintf(NULL, 0, "%d;", tmp->id);
        tmp = tmp->next;
    }
    invdata = fill_invdata(head, total_length);
    return invdata;
}

void save_inventory(repo_t *repo)
{
    FILE *file = fopen(INV_SVFILE, "w");
    char *str = get_inv_data(&(repo->player->inv->content));

    if (str == NULL) {
        fclose(file);
    } else {
        fwrite(str, 1, strlen(str), file);
        fclose(file);
    }
    free(str);
}
