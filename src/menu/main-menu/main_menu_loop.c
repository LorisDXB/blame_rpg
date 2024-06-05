/*
** EPITECH PROJECT, 2024
** gitaction-mirror
** File description:
** main_menu
*/

#include "rpg.h"

static void end_menu(repo_t *repo)
{
    repo->main_menu->id_settings = false;
    repo->main_menu->id_sound = false;
    repo->main_menu->id_window_size = false;
    if (repo->main_menu->id_main == true) {
        repo->main_menu->id_main = false;
        sfSound_stop(repo->musics[0]->sound);
        window_loop(repo);
    }
}

static void new_main_menu(repo_t *repo)
{
    sfRenderWindow_close(repo->set->w);
    repo->set->w = sfRenderWindow_create(repo->set->mode, "BLAME!",
        sfResize | sfClose, NULL);
    init_main_rect(repo);
}

static void draw_settings(repo_t *repo)
{
    sfRenderWindow_drawRectangleShape(repo->set->w,
        repo->main_menu->rect[sound].rectangle, NULL);
    sfRenderWindow_drawRectangleShape(repo->set->w,
        repo->main_menu->rect[window_size].rectangle, NULL);
    sfRenderWindow_drawRectangleShape(repo->set->w,
        repo->main_menu->rect[settings_bar].rectangle, NULL);
    if (repo->main_menu->id_window_size == true) {
        for (int index = window_bar; index <= window_4_3; index++)
        sfRenderWindow_drawRectangleShape(repo->set->w,
            repo->main_menu->rect[index].rectangle, NULL);
    }
    if (repo->main_menu->id_sound == true) {
        for (int index = sound_bar; index <= sound_100; index++)
            sfRenderWindow_drawRectangleShape(repo->set->w,
                repo->main_menu->rect[index].rectangle, NULL);
    }
}

static void draw_text(repo_t *repo)
{
    sfRenderWindow_drawText(repo->set->w,
        repo->main_menu->text[sound_txt].text, NULL);
    sfRenderWindow_drawText(repo->set->w,
        repo->main_menu->text[window_size_txt].text, NULL);
    if (repo->main_menu->id_window_size == true) {
        for (int i = window_16_9_txt; i <= window_4_3_txt; i++)
            sfRenderWindow_drawText(repo->set->w,
                repo->main_menu->text[i].text, NULL);
    }
    if (repo->main_menu->id_sound == true) {
        for (int i = sound_0_txt; i <= sound_100_txt; i++)
            sfRenderWindow_drawText(repo->set->w,
                repo->main_menu->text[i].text, NULL);
    }
}

void draw_things(repo_t *repo, sfSprite *background)
{
    sfRenderWindow_drawSprite(repo->set->w, background, NULL);
    for (int index = 1; index < sound; index++)
        sfRenderWindow_drawRectangleShape(repo->set->w,
            repo->main_menu->rect[index].rectangle, NULL);
    for (int i = 0; i < sound_txt; i++)
        sfRenderWindow_drawText(repo->set->w,
            repo->main_menu->text[i].text, NULL);
    if (repo->main_menu->id_settings == true) {
        draw_settings(repo);
        draw_text(repo);
    } else {
        repo->main_menu->id_settings = false;
        repo->main_menu->id_window_size = false;
        repo->main_menu->id_sound = false;
    }
}

void handle_event_menu(repo_t *repo, sfVector2i mouse)
{
    if (repo->set->ev.type == sfEvtClosed)
        sfRenderWindow_close(repo->set->w);
    get_mouse_hover(repo, mouse);
    if (repo->set->ev.type == sfEvtMouseButtonPressed) {
        if (sfMouse_isButtonPressed(sfMouseLeft))
            get_mouse_click(repo, mouse);
    }
}

void handle_keys_menu(repo_t *repo, sfVector2i mouse)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        repo->main_menu->id_settings = false;
        repo->main_menu->id_window_size = false;
        repo->main_menu->id_sound = false;
    }
}

void destroy_main_menu(repo_t *repo)
{
    sfSprite_destroy(repo->main_menu->background);
    for (int index = title; index <= sound_100; index++)
        sfRectangleShape_destroy(repo->main_menu->rect[index].rectangle);
    for (int index = title_txt; index <= sound_100_txt; index++)
        sfText_destroy(repo->main_menu->text[index].text);
}

void main_menu(repo_t *repo)
{
    sfVector2i mouse = {0, 0};

    sfSound_play(repo->musics[0]->sound);
    new_main_menu(repo);
    init_all_text(repo);
    while (sfRenderWindow_isOpen(repo->set->w)) {
        get_colliders(repo);
        mouse = sfMouse_getPositionRenderWindow(repo->set->w);
        while (sfRenderWindow_pollEvent(repo->set->w, &repo->set->ev))
            handle_event_menu(repo, mouse);
        sfRenderWindow_clear(repo->set->w, sfColor_fromRGB(30, 23, 89));
        handle_keys_menu(repo, mouse);
        draw_things(repo, repo->main_menu->background);
        sfRenderWindow_display(repo->set->w);
        if (repo->main_menu->id_main == true)
            break;
    }
    destroy_main_menu(repo);
    end_menu(repo);
}
