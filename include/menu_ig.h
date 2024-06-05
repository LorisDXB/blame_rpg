/*
** EPITECH PROJECT, 2024
** rpg-loryce.gode
** File description:
** menu_ig
*/

#ifndef MENU_IG_H_
    #define MENU_IG_H_
    #include "struct.h"

    #define T_BAR (repo->ig_menu->w_pos.x + (repo->ig_menu->w_scale.x / 4))
    #define POS_X_MENU ((repo->ig_menu->w_scale.x / 2) / 100)
    #define POS_Y_MENU (repo->ig_menu->w_scale.y / 200)

    #define TOP_BAR_X T_BAR
    #define TOP_BAR_Y repo->ig_menu->w_pos.y
    #define TOP_BAR_SCALE_X repo->ig_menu->w_scale.x / 2
    #define TOP_BAR_SCALE_Y (repo->ig_menu->w_scale.y / 50) * 5
    #define TEXTURE_TOP_BAR "assets/sprites/menu/ingmenu.png"

    #define TOP_RESUME_X T_BAR + (POS_X_MENU * 17)
    #define TOP_RESUME_Y repo->ig_menu->w_pos.y + POS_Y_MENU
    #define TOP_RESUME_SCALE_X (repo->ig_menu->w_scale.y / 50) * 4
    #define TOP_RESUME_SCALE_Y (repo->ig_menu->w_scale.y / 50) * 4
    #define TEXTURE_RESUME "assets/sprites/menu/resume.png"

    #define TOP_SAVE_IG_X T_BAR + (POS_X_MENU * 45.5)
    #define TOP_SAVE_IG_Y repo->ig_menu->w_pos.y + POS_Y_MENU
    #define TOP_SAVE_IG_SCALE_X (repo->ig_menu->w_scale.y / 50) * 4
    #define TOP_SAVE_IG_SCALE_Y (repo->ig_menu->w_scale.y / 50) * 4
    #define TEXTURE_SAVE "assets/sprites/menu/save.png"

    #define TOP_LEAVE_IG_X T_BAR + (POS_X_MENU * 75)
    #define TOP_LEAVE_IG_Y repo->ig_menu->w_pos.y + POS_Y_MENU
    #define TOP_LEAVE_IG_SCALE_X (repo->ig_menu->w_scale.y / 50) * 4
    #define TOP_LEAVE_IG_SCALE_Y (repo->ig_menu->w_scale.y / 50) * 4
    #define TEXTURE_LEAVE "assets/sprites/menu/leave.png"

enum rect_sprite_ig {
    top_bar,
    resume_ig,
    save_ig,
    leave_ig,
};

void menu_ig(repo_t *repo);
void draw_menu_ig(repo_t *repo);
void destroy_menu_ig(repo_t *repo);
void handle_ig_menu(repo_t *repo, sfVector2f ms);
void get_new_pos_sprite_ig_menu(repo_t *repo);

void init_all_menu_ig(repo_t *repo);

void get_click_ig(repo_t *repo, sfVector2f mouse);
void get_ig_hover_button(repo_t *repo, sfVector2f ms);

void init_rect_ig(repo_t *repo);
void get_collider_ig(repo_t *repo);

void init_sprite_ig_menu(repo_t *repo);

#endif /* !MENU_IG_H_ */
