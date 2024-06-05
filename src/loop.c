/*
** EPITECH PROJECT, 2024
** loop for rpg
** File description:
** loop for window
*/

#include "rpg.h"

static sfVector2f get_window_pos(repo_t *repo)
{
    sfVector2i org = sfMouse_getPositionRenderWindow(repo->set->w);
    sfVector2f ms = sfRenderWindow_mapPixelToCoords(repo->set->w, org, NULL);

    repo->ig_menu->w_scale = sfView_getSize(repo->player->view);
    repo->ig_menu->w_pos = sfView_getCenter(repo->player->view);
    repo->ig_menu->w_pos = (sfVector2f)
        {repo->ig_menu->w_pos.x - (repo->ig_menu->w_scale.x / 2),
        repo->ig_menu->w_pos.y - (repo->ig_menu->w_scale.y / 2)};
    return ms;
}

static void check_id(repo_t *repo, sfVector2f ms)
{
    if (repo->ig_menu->id_menu == true)
        handle_ig_menu(repo, ms);
}

static void rebase_menu_ig(repo_t *repo)
{
    destroy_menu_ig(repo);
    repo->ig_menu->id_menu = false;
    repo->ig_menu->id_settings = false;
    if (repo->main_menu->id_main == true) {
        repo->main_menu->id_main = false;
        sfSound_stop(repo->musics[1]->sound);
        main_menu(repo);
    }
}

void window_in_loop(repo_t *repo, sfVector2f ms)
{
    change_hpbar(repo->player);
    change_xpbar(repo->player);
    draw_sprites(repo);
    handle_keys(repo);
    handle_clicks(repo);
    handle_view(repo);
    if (repo->set->transition_request != 1)
        enemy_hub(repo, repo->room->enemies);
    sfRenderWindow_display(repo->set->w);
    sfClock_restart(repo->set->clock);
    check_id(repo, ms);
    exp_calc(repo);
    quest_checks(repo);
}

void window_loop(repo_t *repo)
{
    sfVector2f ms = {0, 0};

    sfSound_play(repo->musics[1]->sound);
    init_all_menu_ig(repo);
    while (sfRenderWindow_isOpen(repo->set->w)) {
        ms = get_window_pos(repo);
        while (sfRenderWindow_pollEvent(repo->set->w,
            &repo->set->ev))
            handle_events(repo, ms);
        sfRenderWindow_clear(repo->set->w, (sfColor){51, 21, 65, 255});
        window_in_loop(repo, ms);
        if (repo->main_menu->id_main == true)
            break;
    }
    rebase_menu_ig(repo);
}
