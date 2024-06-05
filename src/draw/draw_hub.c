/*
** EPITECH PROJECT, 2024
** draw_hub for rpg
** File description:
** rpg
*/
#include "rpg.h"

static void draw_firstlayer(repo_t *repo)
{
    sfRenderWindow_drawSprite(repo->set->w, repo->paral->back->spr, NULL);
    sfRenderWindow_drawSprite(repo->set->w, repo->map->sprite->spr, NULL);
    return;
}

static void sub_draw_enemy(enemy_t *enemy, sfRenderWindow *win)
{
    if (enemy->hp > 0) {
        sfRenderWindow_drawSprite(win, enemy->sprite->spr,
            NULL);
        sfRenderWindow_drawRectangleShape(win,
            enemy->lifebar->back, NULL);
        sfRenderWindow_drawRectangleShape(win,
            enemy->lifebar->hp_rem, NULL);
        if (enemy->slash->appear == 1)
            sfRenderWindow_drawSprite(win,
                enemy->slash->sprite->spr, NULL);
    }
}

static void draw_enemy(enemy_t **enemies, sfRenderWindow *win)
{
    if (enemies == NULL)
        return;
    for (int i = 0; enemies[i] != NULL; i++)
        sub_draw_enemy(enemies[i], win);
}

static void draw_skills(repo_t *repo)
{
    sprite_t **ct = repo->player->inv->items;

    sfRenderWindow_drawSprite(repo->set->w,
        repo->player->skills->spr->spr, NULL);
    sfSprite_setPosition(repo->player->skills->spr->spr,
        (sfVector2f){repo->player->coords.x + 800,
        repo->player->coords.y + 50});
    draw_skill_text(repo);
    return;
}

static void draw_inventory(repo_t *repo)
{
    sprite_t **ct = repo->player->inv->items;

    sfRenderWindow_drawSprite(repo->set->w,
        repo->player->inv->spr->spr, NULL);
    sfSprite_setPosition(repo->player->inv->spr->spr,
        (repo->player->coords));
    if (repo->player->inv->content != NULL) {
        draw_item_sprites(ct, repo);
    }
    return;
}

static void draw_sprites_2(repo_t *repo)
{
    if (repo->room->is_png == 1) {
        draw_png(repo);
        show_text_png(repo);
        loop_rect_png(repo);
    }
    draw_bars(repo->set->w, repo->player);
    detect_usb_key(repo);
}

static void draw_sprites_second(repo_t *repo)
{
    static int ckagi = 0;

    if (repo->player->skills->agi == 10 && ckagi == 0) {
        ckagi++;
        write_message(repo, "    >The wind engolfs you.<");
    }
    if (repo->set->transition_request == 1)
        fade_transition(repo);
    if (repo->set->death_request == 1)
        death_transition(repo);
    if (repo->ig_menu->id_menu == true)
        draw_menu_ig(repo);
}

void draw_seclayer(repo_t *repo)
{
    if (repo->set->despawn != 1) {
        sfRenderWindow_drawSprite(repo->set->w,
        repo->map->sec_layer->spr, NULL);
    }
    affiche_help(repo);
}

void draw_sprites(repo_t *repo)
{
    draw_firstlayer(repo);
    draw_player(repo);
    if (repo->set->transition_request != 1)
        draw_enemy(repo->room->enemies, repo->set->w);
    if (repo->player->inv->drop_ck == 1)
        dropped_weapon(repo);
    draw_item(repo);
    draw_seclayer(repo);
    draw_sprites_2(repo);
    if (repo->player->inv->status == OPEN) {
        draw_inventory(repo);
        draw_skills(repo);
        draw_quests(repo);
    }
    draw_sprites_second(repo);
}
