/*
** EPITECH PROJECT, 2024
** rpg-loryce.gode
** File description:
** init_sprite_ig_menu
*/

#include "../../../../include/rpg.h"

static void get_top_bar_sprite(repo_t *repo)
{
    repo->ig_menu->sprite[top_bar].pos = (sfVector2f)
        {TOP_BAR_X - 5, TOP_BAR_Y - 4};
    repo->ig_menu->sprite[top_bar].scale = (sfVector2f)
        {2.37, 1.03};
    repo->ig_menu->sprite[top_bar].texture =
        sfTexture_createFromFile(TEXTURE_TOP_BAR, NULL);
    repo->ig_menu->sprite[top_bar].sprite = get_sprite(
        repo->ig_menu->sprite[top_bar].scale,
        repo->ig_menu->sprite[top_bar].pos,
        repo->ig_menu->sprite[top_bar].texture);
}

static void get_resume_sprite(repo_t *repo)
{
    repo->ig_menu->sprite[resume_ig].pos = (sfVector2f)
        {TOP_RESUME_X, TOP_RESUME_Y};
    repo->ig_menu->sprite[resume_ig].scale = (sfVector2f)
        {0.2, 0.2};
    repo->ig_menu->sprite[resume_ig].texture =
        sfTexture_createFromFile(TEXTURE_RESUME, NULL);
    repo->ig_menu->sprite[resume_ig].sprite = get_sprite(
        repo->ig_menu->sprite[resume_ig].scale,
        repo->ig_menu->sprite[resume_ig].pos,
        repo->ig_menu->sprite[resume_ig].texture);
}

static void get_settings_sprite(repo_t *repo)
{
    repo->ig_menu->sprite[save_ig].pos = (sfVector2f)
        {TOP_SAVE_IG_X, TOP_SAVE_IG_Y};
    repo->ig_menu->sprite[save_ig].scale = (sfVector2f)
        {0.2, 0.2};
    repo->ig_menu->sprite[save_ig].texture =
        sfTexture_createFromFile(TEXTURE_SAVE, NULL);
    repo->ig_menu->sprite[save_ig].sprite = get_sprite(
        repo->ig_menu->sprite[save_ig].scale,
        repo->ig_menu->sprite[save_ig].pos,
        repo->ig_menu->sprite[save_ig].texture);
}

void get_leave_sprite(repo_t *repo)
{
    repo->ig_menu->sprite[leave_ig].pos = (sfVector2f)
        {TOP_LEAVE_IG_X, TOP_LEAVE_IG_Y};
    repo->ig_menu->sprite[leave_ig].scale = (sfVector2f)
        {0.5, 0.5};
    repo->ig_menu->sprite[leave_ig].texture =
        sfTexture_createFromFile(TEXTURE_LEAVE, NULL);
    repo->ig_menu->sprite[leave_ig].sprite = get_sprite(
        repo->ig_menu->sprite[leave_ig].scale,
        repo->ig_menu->sprite[leave_ig].pos,
        repo->ig_menu->sprite[leave_ig].texture);
}

void init_sprite_ig_menu(repo_t *repo)
{
    get_top_bar_sprite(repo);
    get_resume_sprite(repo);
    get_settings_sprite(repo);
    get_leave_sprite(repo);
}
