/*
** EPITECH PROJECT, 2024
** rpg-loryce.gode
** File description:
** idknow
*/

#include "../../../../include/rpg.h"

static void get_click_on_resume(repo_t *repo, sfFloatRect rect,
    sfVector2f ms)
{
    if (sfFloatRect_contains(&rect, ms.x, ms.y) &&
        sfMouse_isButtonPressed(sfMouseLeft))
        repo->ig_menu->id_menu = false;
}

static void get_click_on_settings(repo_t *repo, sfFloatRect rect,
    sfVector2f ms)
{
    if (sfFloatRect_contains(&rect, ms.x, ms.y) &&
        sfMouse_isButtonPressed(sfMouseLeft)) {
            printf("saved\n");
            save_inventory(repo);
            save_skills(repo);
            save_quests(repo);
    }
}

void get_click_on_leave(repo_t *repo, sfFloatRect rect,
    sfVector2f ms)
{
    if (sfFloatRect_contains(&rect, ms.x, ms.y) &&
        sfMouse_isButtonPressed(sfMouseLeft))
        repo->main_menu->id_main = true;
}

void get_click_ig(repo_t *repo, sfVector2f ms)
{
    if (repo->set->ev.type == sfEvtMouseButtonPressed) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            get_click_on_resume(repo,
                repo->ig_menu->rect[resume_ig].collider, ms);
            get_click_on_settings(repo,
                repo->ig_menu->rect[save_ig].collider, ms);
            get_click_on_leave(repo,
                repo->ig_menu->rect[leave_ig].collider, ms);
        }
    }
}
