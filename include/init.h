/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** init.h
*/

#ifndef INIT_H_
    #define INIT_H_

    #include "struct.h"

enemy_db_t *fetch_enemies(enemy_db_t *enemies);
void fetch_weps(weapon_t *wep);
db_t *init_db(void);
enemy_t *init_enemy(enemy_db_t *enemies_db, int random);
enemy_t *init_enemy_db(char **info);
inventory_t *init_inventory(repo_t *repo);
sound_t **init_musics(void);
player_t *init_player(repo_t *repo);
repo_t *init_repo(void);
weapon_t *init_wep(sprite_t *spr, char **ctmp, int id);

#endif /* INIT_H_ */
