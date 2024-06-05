/*
** EPITECH PROJECT, 2024
** write_message
** File description:
** for rpg
*/

#include "../include/rpg.h"

void write_message(repo_t *repo, char *str)
{
    char *write = malloc(sizeof(char) * strlen(str));

    sprintf(write, "%s", str);
    sfText_setString(repo->player->inv->drop, write);
    repo->player->inv->drop_ck = 1;
}
