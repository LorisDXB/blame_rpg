/*
** EPITECH PROJECT, 2024
** rpg-loryce.gode
** File description:
** reset_pos_sprite
*/

#include "../../../../include/rpg.h"

void get_new_pos_sprite_ig_menu(repo_t *repo)
{
    repo->ig_menu->sprite[top_bar].pos = (sfVector2f)
        {TOP_BAR_X - 5, TOP_BAR_Y - 4};
    sfSprite_setPosition(repo->ig_menu->sprite[top_bar].sprite,
        repo->ig_menu->sprite[top_bar].pos);
    repo->ig_menu->sprite[resume_ig].pos = (sfVector2f)
        {TOP_RESUME_X, TOP_RESUME_Y};
    sfSprite_setPosition(repo->ig_menu->sprite[resume_ig].sprite,
        repo->ig_menu->sprite[resume_ig].pos);
    repo->ig_menu->sprite[save_ig].pos = (sfVector2f)
        {TOP_SAVE_IG_X, TOP_SAVE_IG_Y};
    sfSprite_setPosition(repo->ig_menu->sprite[save_ig].sprite,
        repo->ig_menu->sprite[save_ig].pos);
    repo->ig_menu->sprite[leave_ig].pos = (sfVector2f)
        {TOP_LEAVE_IG_X, TOP_LEAVE_IG_Y};
    sfSprite_setPosition(repo->ig_menu->sprite[leave_ig].sprite,
        repo->ig_menu->sprite[leave_ig].pos);
}
