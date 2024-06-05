/*
** EPITECH PROJECT, 2024
** post_death
** File description:
** for rpg
*/

#include "../../include/rpg.h"

static void player_gains(repo_t *repo, enemy_t *enemy)
{
    if (repo->player->hp > repo->player->full_hp - 15)
        repo->player->hp = repo->player->full_hp;
    if (repo->player->hp < repo->player->full_hp - 15)
        repo->player->hp += 15;
    if (repo->player->skills->lvl < 20)
        repo->player->skills->xp += enemy->xp_rew;
}

static char *wep_drop_msg(weapon_t **head)
{
    char *ret = NULL;
    weapon_t *tmp = *head;

    while (tmp->next != NULL)
        tmp = tmp->next;
    ret = malloc(sizeof(char) * (16 + strlen(tmp->name) + 1));
    sprintf(ret, "< you found a %s >", tmp->name);
    return ret;
}

void post_death(enemy_t *enemy, repo_t *repo)
{
    int drop_check = rand() % 5;
    weapon_t *toadd = NULL;

    enemy->hp = 0;
    player_gains(repo, enemy);
    if (drop_check == 1) {
        if (repo->player->inv->content == NULL) {
            repo->player->inv->content =
            add_inventory_node(&(repo->player->inv->content), repo);
        } else
            add_inventory_node(&(repo->player->inv->content), repo);
        repo->player->inv->items =
            fetch_sprites(&(repo->player->inv->content));
        sfText_setString(repo->player->inv->drop,
            wep_drop_msg(&(repo->player->inv->content)));
        repo->player->inv->drop_ck = 1;
        save_inventory(repo);
    }
    save_skills(repo);
}
