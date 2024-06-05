/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** init_db.c
*/

#include "rpg.h"

weapon_t *init_wep(sprite_t *spr, char **ctmp, int id)
{
    weapon_t *wep = malloc(sizeof(weapon_t));

    wep->id = id;
    wep->spr = spr;
    wep->atk = atoi(ctmp[1]);
    wep->name = strdup(ctmp[0]);
    wep->speed = atoi(ctmp[2]);
    wep->cd = atof(ctmp[3]);
    wep->hitbox = NULL;
    wep->clock = NULL;
    wep->an = OFF;
    wep->next = NULL;
    return wep;
}

quest_t *init_quests(char **qtmp, sfFont *font, int id)
{
    quest_t *quest = malloc(sizeof(quest_t));

    quest->goal = strdup(qtmp[0]);
    quest->xp_rew = atoi(qtmp[1]);
    quest->status = atoi(qtmp[2]);
    quest->txt = sfText_create();
    sfText_setOrigin(quest->txt, (sfVector2f){-100, 700});
    sfText_setFont(quest->txt, font);
    sfText_setColor(quest->txt, sfWhite);
    sfText_setString(quest->txt, quest->goal);
    sfText_setScale(quest->txt, (sfVector2f){1, 1});
    quest->id = id;
    return quest;
}

db_t *init_db(void)
{
    db_t *db = malloc(sizeof(db_t));
    char *ctmp[5] = {"0", "0", "0", "0", "0"};
    char *qtmp[3] = {"0", "0", "0"};

    db->font = sfFont_createFromFile(INV_FONT);
    db->wep = init_wep(NULL, ctmp, 0);
    fetch_weps(db->wep);
    db->quest = fetch_quests(db->font);
    db->enemies = NULL;
    db->enemies = fetch_enemies(db->enemies);
    return db;
}
