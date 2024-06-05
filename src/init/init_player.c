/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** init_player.c
*/

#include "../../include/rpg.h"

static bar_t *init_bar(char *path, sfColor color, sfVector2f pos)
{
    bar_t *bar = malloc(sizeof(bar_t));

    bar->sprite = create_spritet(path, (sfVector2f){2, 2});
    bar->back = create_rectangle((sfVector2f){30, 415}, pos, sfColor_fromRGB
        (100, 100, 100));
    sfRectangleShape_setOrigin(bar->back, (sfVector2f){0, 0});
    sfRectangleShape_setRotation(bar->back, 180);
    bar->rem = create_rectangle((sfVector2f){30, 415}, pos, color);
    sfRectangleShape_setOrigin(bar->rem, (sfVector2f){0, 0});
    sfRectangleShape_setRotation(bar->rem, 180);
    sfSprite_setPosition(bar->sprite->spr, pos);
    sfSprite_setOrigin(bar->sprite->spr, (sfVector2f){sfTexture_getSize
        (bar->sprite->tex).x / 2, sfTexture_getSize(bar->sprite->tex).y / 2});
    bar->clock = sfClock_create();
    return bar;
}

static support_t *init_sup(void)
{
    support_t *sup = malloc(sizeof(support_t));

    sup->spr = malloc(sizeof(sprite_t));
    sup->spr->spr = sfSprite_create();
    sup->spr->tex = sfTexture_createFromFile(MEDKIT_TEX, NULL);
    sfSprite_setTexture(sup->spr->spr, sup->spr->tex, 0);
    sup->spr->scl = (sfVector2f){3, 3};
    sup->uses_left = 2;
    return sup;
}

static int *init_keypress(void)
{
    int *ret = malloc(sizeof(int) * 5);

    ret[0] = 0;
    ret[1] = 0;
    ret[2] = 0;
    ret[3] = 0;
    ret[4] = 0;
    return ret;
}

static void init_player3(player_t *player)
{
    player->hpbar = init_bar(HPBAR_TEX, sfRed,
        (sfVector2f){sfSprite_getPosition(player->sprite->spr).x - 1100,
        sfSprite_getPosition(player->sprite->spr).y + 370});
    player->xpbar = init_bar(XPBAR_TEX, sfColor_fromRGB(0, 240, 255),
        (sfVector2f){sfSprite_getPosition(player->sprite->spr).x - 1000,
        sfSprite_getPosition(player->sprite->spr).y + 370});
    sfRectangleShape_setSize(player->xpbar->rem, (sfVector2f){30, 0});
    player->death = sfTexture_createFromFile(DEATH_TEX, NULL);
    player->dash = OFF;
}

static void init_player2(player_t *player)
{
    player->run = sfTexture_createFromFile(RUN_TEX, NULL);
    player->key_press = init_keypress();
    player->trans = init_text_png("./assets/fonts/AdventureRequest-j8W9.ttf",
    "I need a translator...");
    sfText_setString(player->trans->text, player->trans->msg);
    player->text = init_text_png("./assets/fonts/AdventureRequest-j8W9.ttf",
    "Press Z Q S D to move");
    player->png_trans = 0;
    player->text_c = sfClock_create();
    player->png = sfClock_create();
    sfText_setPosition(player->trans->text,
    (sfVector2f){player->coords.x - 50, player->coords.y - 50});
    sfText_setPosition(player->text->text,
    (sfVector2f){player->coords.x - 50, player->coords.y - 50});
    player->wait = sfClock_create();
    player->speak = 0;
    player->mouve = 0;
    init_player3(player);
}

player_t *init_player(repo_t *repo)
{
    player_t *player = malloc(sizeof(player_t));

    player->full_hp = P_HP;
    player->hp = P_HP;
    player->attack = 5;
    player->view = sfView_create();
    player->coords.x = 6200;
    player->coords.y = 5300;
    player->sprite = create_spritet(IDLE_TEX, (sfVector2f){P_SCALE, P_SCALE});
    sfSprite_setOrigin(player->sprite->spr,
        (sfVector2f){sfTexture_getSize(player->sprite->tex).x / 3.8 / 2.0,
        sfTexture_getSize(player->sprite->tex).y / 4.0 / 2.0});
    player->wep = wep_selector(1, &(repo->db->wep));
    player->sup = init_sup();
    player->inv = init_inventory(repo);
    player->skills = init_skills(repo);
    player->clock = sfClock_create();
    player->eq = WEP;
    init_player2(player);
    return player;
}
