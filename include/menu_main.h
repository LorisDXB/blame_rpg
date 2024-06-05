/*
** EPITECH PROJECT, 2024
** gitaction-mirror
** File description:
** menu
*/

#ifndef MENU_H_
    #define MENU_H_
    #include "struct.h"

    #define TITLE_X repo->set->mode.width / 35
    #define TITLE_Y repo->set->mode.height / 20
    #define TITLE_SCALE_X repo->set->mode.width / 2
    #define TITLE_SCALE_Y repo->set->mode.height / 4.32
    #define TITLE_SIZE repo->set->mode.width / 15.36

    #define PLAY_BUTTON_X (repo->set->mode.width / 50) * 3 - 3
    #define PLAY_BUTTON_Y (repo->set->mode.height / 2)
    #define PLAY_BUTTON_SCALE_X repo->set->mode.width / 6.4 + 3
    #define PLAY_BUTTON_SCALE_Y repo->set->mode.height / 10.8
    #define PLAY_SIZE repo->set->mode.width / 24

    #define CONTINUE_BUTTON_X (repo->set->mode.width / 50) * 3 - 3
    #define CONTINUE_BUTTON_Y (repo->set->mode.height / 50) * 31
    #define CONTINUE_BUTTON_SCALE_X repo->set->mode.width / 6.4 + 3
    #define CONTINUE_BUTTON_SCALE_Y repo->set->mode.height / 21.6
    #define CONTINUE_SIZE repo->set->mode.width / 54.86

    #define SETTING_BUTTON_X (repo->set->mode.width / 50) * 3 - 3
    #define SETTING_BUTTON_Y (repo->set->mode.height / 50) * 34
    #define SETTING_BUTTON_SCALE_X repo->set->mode.width / 6.4 + 3
    #define SETTING_BUTTON_SCALE_Y repo->set->mode.height / 21.6
    #define SETTINGS_SIZE repo->set->mode.width / 54.86

    #define LEAVE_BUTTON_X (repo->set->mode.width / 50) * 2
    #define LEAVE_BUTTON_Y (repo->set->mode.height / 5) * 4
    #define LEAVE_BUTTON_SCALE_X repo->set->mode.width / 9.6
    #define LEAVE_BUTTON_SCALE_Y repo->set->mode.height / 21.6
    #define LEAVE_SIZE repo->set->mode.width / 54.86

    #define SOUND_BUTTON_X (repo->set->mode.width / 50) * 12
    #define SOUND_BUTTON_Y (repo->set->mode.height / 50) * 32
    #define SOUND_BUTTON_SCALE_X repo->set->mode.width / 5.5
    #define SOUND_BUTTON_SCALE_Y repo->set->mode.height / 21.6
    #define SOUND_SIZE repo->set->mode.width / 54.86

    #define WINDOW_SIZE_BUTTON_X (repo->set->mode.width / 50) * 12
    #define WINDOW_SIZE_BUTTON_Y (repo->set->mode.height / 50) * 36
    #define WINDOW_SIZE_BUTTON_SCALE_X repo->set->mode.width / 5.5
    #define WINDOW_SIZE_BUTTON_SCALE_Y repo->set->mode.height / 21.6
    #define WINDOW_SIZE_SIZE repo->set->mode.width / 54.86

    #define WINDOW_16_9_X (repo->set->mode.width / 50) * 22
    #define WINDOW_16_9_Y (repo->set->mode.height / 50) * 34
    #define WINDOW_16_9_SCALE_X repo->set->mode.width / 6.4
    #define WINDOW_16_9_SCALE_Y repo->set->mode.height / 21.6
    #define WINDOW_16_9_SIZE repo->set->mode.width / 54.86

    #define WINDOW_4_3_X (repo->set->mode.width / 50) * 22
    #define WINDOW_4_3_Y (repo->set->mode.height / 50) * 38
    #define WINDOW_4_3_SCALE_X repo->set->mode.width / 6.4
    #define WINDOW_4_3_SCALE_Y repo->set->mode.height / 21.6
    #define WINDOW_4_3_SIZE repo->set->mode.width / 54.86

    #define SOUND_0_X (repo->set->mode.width / 50) * 22
    #define SOUND_0_Y (repo->set->mode.height / 50) * 30
    #define SOUND_0_SCALE_X repo->set->mode.width / 12.8
    #define SOUND_0_SCALE_Y repo->set->mode.height / 21.6
    #define SOUND_0_SIZE repo->set->mode.width / 54.86

    #define SOUND_25_X (repo->set->mode.width / 50) * 22
    #define SOUND_25_Y (repo->set->mode.height / 50) * 33
    #define SOUND_25_SCALE_X repo->set->mode.width / 12.8
    #define SOUND_25_SCALE_Y repo->set->mode.height / 21.6
    #define SOUND_25_SIZE repo->set->mode.width / 54.86

    #define SOUND_50_X (repo->set->mode.width / 50) * 22
    #define SOUND_50_Y (repo->set->mode.height / 50) * 36
    #define SOUND_50_SCALE_X repo->set->mode.width / 12.8
    #define SOUND_50_SCALE_Y repo->set->mode.height / 21.6
    #define SOUND_50_SIZE repo->set->mode.width / 54.86

    #define SOUND_75_X (repo->set->mode.width / 50) * 22
    #define SOUND_75_Y (repo->set->mode.height / 50) * 39
    #define SOUND_75_SCALE_X repo->set->mode.width / 12.8
    #define SOUND_75_SCALE_Y repo->set->mode.height / 21.6
    #define SOUND_75_SIZE repo->set->mode.width / 54.86

    #define SOUND_100_X (repo->set->mode.width / 50) * 22
    #define SOUND_100_Y (repo->set->mode.height / 50) * 42
    #define SOUND_100_SCALE_X repo->set->mode.width / 12.8
    #define SOUND_100_SCALE_Y repo->set->mode.height / 21.6
    #define SOUND_100_SIZE repo->set->mode.width / 54.86

enum rect_main {
    title,
    play,
    continu,
    settings,
    leave,
    sound,
    window_size,
    settings_bar,
    window_bar,
    window_16_9,
    window_4_3,
    sound_bar,
    sound_0,
    sound_25,
    sound_50,
    sound_75,
    sound_100
};

enum text_main {
    title_txt,
    play_txt,
    continu_txt,
    settings_txt,
    leave_txt,
    sound_txt,
    window_size_txt,
    window_16_9_txt,
    window_4_3_txt,
    sound_0_txt,
    sound_25_txt,
    sound_50_txt,
    sound_75_txt,
    sound_100_txt
};

/// @brief Get a new Sprite.
/// @param pos The position x and y of the sprite.
/// @param scale The scale of the sprite.
/// @param texture The texture for the sprite to have, NULL if none.
/// @return A new sfSprite*.
sfSprite *get_sprite(sfVector2f pos, sfVector2f scale, sfTexture *texture);
void menu_skill(repo_t *repo);
void menu_handling(repo_t *repo);
void main_menu(repo_t *repo);

/// @brief Get a new rectangle.
/// @param scale The scale of the rectangle.
/// @param pos The position of the rectangle.
/// @param color The color with sfColor of the rectangle.
/// @return A new sfRectangleShape*.
sfRectangleShape *get_rect(sfVector2f scale, sfVector2f pos, sfColor color);
void init_main_rect(repo_t *repo);
void get_colliders(repo_t *repo);
void init_change_window(repo_t *repo);
void init_change_sound(repo_t *repo);
void reload_rect(repo_t *repo);

/// @brief Get a new text.
/// @param font The font of your text.
/// @param pos The positon of your text.
/// @param msg The message of your text.
/// @param size The size in pixel of your text.
/// @return A new sfText*.
sfText *get_text(sfVector2f pos, unsigned int size, char *msg, sfFont *font);
/// @brief Same as get_text but with a sfcolor already in.
sfText *get_text_main(sfFont *font, sfVector2f pos,
    char *msg, unsigned int size);
void init_all_text(repo_t *repo);
void init_change_window_text(repo_t *repo);
void init_change_sound_text(repo_t *repo);

void get_mouse_click(repo_t *repo, sfVector2i mouse);
void change_window_click(repo_t *repo, sfVector2i mouse);
void change_sound_click(repo_t *repo, sfVector2i mouse);
void get_mouse_hover(repo_t *repo, sfVector2i mouse);
void get_hover_window_change(repo_t *repo, sfVector2i mouse);
void get_hover_sound_change(repo_t *repo, sfVector2i mouse);

#endif /* !MENU_H_ */
