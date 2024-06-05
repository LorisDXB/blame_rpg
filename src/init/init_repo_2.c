/*
** EPITECH PROJECT, 2024
** gitaction-mirror
** File description:
** init_repo_2
*/

#include "rpg.h"

help_t *init_help(void)
{
    help_t *help = malloc(sizeof(help_t));

    help->sprite = create_spritet("./assets/sprites/z.png",
    (sfVector2f){2, 2});
    sfSprite_setOrigin(help->sprite->spr, (sfVector2f){300, 200});
    help->show = 1;
    return help;
}
