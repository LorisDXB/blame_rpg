/*
** EPITECH PROJECT, 2024
** gitaction-mirror
** File description:
** menu_game
*/

#include "../../../include/rpg.h"

void init_all_menu_ig(repo_t *repo)
{
    init_rect_ig(repo);
    get_collider_ig(repo);
    init_sprite_ig_menu(repo);
}

void draw_menu_ig(repo_t *repo)
{
    sfRenderWindow_drawSprite(repo->set->w,
        repo->ig_menu->sprite[top_bar].sprite, NULL);
    for (int index = resume_ig; index <= leave_ig; index++) {
        sfRenderWindow_drawRectangleShape(repo->set->w,
            repo->ig_menu->rect[index].rectangle, NULL);
    }
    for (int index = resume_ig; index <= leave_ig; index++)
        sfRenderWindow_drawSprite(repo->set->w,
            repo->ig_menu->sprite[index].sprite, NULL);
}

void destroy_menu_ig(repo_t *repo)
{
    for (int index = resume_ig; index <= leave_ig; index++)
        sfRectangleShape_destroy(repo->ig_menu->rect[index].rectangle);
    for (int index = top_bar; index <= leave_ig; index++) {
        sfTexture_destroy(repo->ig_menu->sprite[index].texture);
        sfSprite_destroy(repo->ig_menu->sprite[index].sprite);
    }
}

void handle_ig_menu(repo_t *repo, sfVector2f ms)
{
    get_collider_ig(repo);
    get_new_pos_sprite_ig_menu(repo);
    get_ig_hover_button(repo, ms);
}

void menu_ig(repo_t *repo)
{
    if (repo->ig_menu->id_menu == true)
        repo->ig_menu->id_menu = false;
    else
        repo->ig_menu->id_menu = true;
}
