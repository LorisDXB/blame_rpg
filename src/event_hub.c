/*
** EPITECH PROJECT, 2024
** event_hub
** File description:
** event_hub
*/

#include "rpg.h"

void show_skill_board(repo_t *repo)
{
    if (repo->ig_menu->id_skill == true) {
        repo->ig_menu->id_skill = false;
    } else {
        repo->ig_menu->id_skill = true;
    }
}

void close_window(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}

void view_up(sfRenderWindow *window, sfEvent event, repo_t *repo)
{
    static float view = 1.2;
    static int nbr = 1;

    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyV) {
            view = view + (nbr * 4.5);
            nbr *= -1;
            repo->view = view;
        }
    }
}

void show_help(sfRenderWindow *window, sfEvent event, repo_t *repo)
{
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyH) {
            repo->help->show *= -1;
        }
    }
}

void handle_events(repo_t *repo, sfVector2f ms)
{
    close_window(repo->set->w, repo->set->ev);
    view_up(repo->set->w, repo->set->ev, repo);
    show_help(repo->set->w, repo->set->ev, repo);
    if (repo->set->ev.type == sfEvtKeyPressed) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            menu_ig(repo);
        if (sfKeyboard_isKeyPressed(sfKeyU))
            show_skill_board(repo);
    }
    if (repo->ig_menu->id_menu == true)
        get_click_ig(repo, ms);
    if (repo->room->is_png == 1) {
        event_png(repo->set->w, repo->set->ev, repo);
        zone_png(repo);
    }
}
