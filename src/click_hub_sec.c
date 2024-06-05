/*
** EPITECH PROJECT, 2024
** click_hub_sec
** File description:
** second click_hub
*/

#include "../include/rpg.h"

static void upd_skills(int i, repo_t *repo)
{
    if (i == 0 && repo->player->skills->str < 50) {
        repo->player->skills->str += 1;
        repo->player->skills->pts--;
    }
    if (i == 1 && repo->player->skills->fort < 50) {
        repo->player->skills->fort += 1;
        repo->player->hp += 2;
        repo->player->full_hp += 2;
        repo->player->skills->pts--;
    }
    if (i == 2 && repo->player->skills->agi < 50) {
        repo->player->skills->agi += 1;
        repo->player->skills->pts--;
    }
    if (i == 3 && repo->player->skills->cha < 50) {
        repo->player->skills->cha += 1;
        repo->player->skills->pts--;
    }
}

void check_skills_bis(sfFloatRect rect, sfVector2f ms, repo_t *repo, int i)
{
    int debounce = 200;
    sfTime elapsed;

    elapsed = sfClock_getElapsedTime(repo->set->debounce);
    if (sfTime_asMilliseconds(elapsed) > debounce &&
        repo->player->skills->pts > 0) {
        upd_skills(i, repo);
        save_skills(repo);
        sfClock_restart(repo->set->debounce);
    }
}

int check_inventory_bis(sfFloatRect rect, sfVector2f ms, repo_t *repo, int i)
{
    int debounce = 200;
    sfTime elapsed;

    if (sfMouse_isButtonPressed(sfMouseRight) &&
            sfFloatRect_contains(&rect, ms.x, ms.y)) {
        elapsed = sfClock_getElapsedTime(repo->set->debounce);
        if (sfTime_asMilliseconds(elapsed) > debounce) {
            wep_deletor_index(&(repo->player->inv->content), i + 1);
            repo->player->inv->items =
                fetch_sprites(&(repo->player->inv->content));
            save_inventory(repo);
            sfClock_restart(repo->set->debounce);
            return 1;
        }
    }
    return 0;
}
