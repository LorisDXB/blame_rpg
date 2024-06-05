/*
** EPITECH PROJECT, 2024
** click hub
** File description:
** hub
*/

#include "../include/rpg.h"

static int check_equipped(repo_t *repo)
{
    if (repo->player->eq == WEP) {
        use_wep(repo);
    }
    if (repo->player->eq == SUP) {
        return 0;
    }
    if (repo->player->eq == EMP) {
        return 0;
    }
    return 0;
}

static int check_skills(repo_t *repo)
{
    sfFloatRect rect;
    sfVector2i org = sfMouse_getPositionRenderWindow(repo->set->w);
    sfVector2f ms = sfRenderWindow_mapPixelToCoords(repo->set->w, org, NULL);

    for (int i = 0; repo->player->skills->buttons[i] != NULL; i++) {
        rect = sfSprite_getGlobalBounds(repo->player->skills->buttons[i]->spr);
        if (sfFloatRect_contains(&rect, ms.x, ms.y)) {
            draw_hover(repo, repo->player->skills->buttons[i]->spr);
        }
        if (sfMouse_isButtonPressed(sfMouseLeft) &&
            sfFloatRect_contains(&rect, ms.x, ms.y)) {
            check_skills_bis(rect, ms, repo, i);
            return 1;
        }
    }
    return 0;
}

static int check_inventory(repo_t *repo)
{
    sfFloatRect rect;
    sfVector2i org = sfMouse_getPositionRenderWindow(repo->set->w);
    sfVector2f ms = sfRenderWindow_mapPixelToCoords(repo->set->w, org, NULL);

    for (int i = 0; repo->player->inv->items[i] != NULL; i++) {
        rect = sfSprite_getGlobalBounds(repo->player->inv->items[i]->spr);
        if (sfMouse_isButtonPressed(sfMouseLeft) &&
            sfFloatRect_contains(&rect, ms.x, ms.y)) {
            repo->player->wep = wep_selector(repo->player->inv->items[i]->id,
                &(repo->db->wep));
            return 1;
        }
        if (check_inventory_bis(rect, ms, repo, i) == 1)
            return 1;
    }
    return 0;
}

void handle_clicks(repo_t *repo)
{
    if ((sfMouse_isButtonPressed(sfMouseLeft) == sfTrue ||
        repo->player->wep->an == PROC) && repo->player->hp >= 0 &&
        repo->player->inv->status == CLOSE) {
        check_equipped(repo);
    }
    if (repo->player->inv->status == OPEN) {
        if (repo->player->inv->content != NULL) {
            check_inventory(repo);
            draw_item_information(repo);
        }
        check_skills(repo);
    }
}
