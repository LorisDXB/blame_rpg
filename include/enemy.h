/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** enemy.h
*/

#ifndef ENEMY_H_
    #define ENEMY_H_

    #include "parameters.h"
    #include "struct.h"

void add_enemies(room_t **full_dongeon, enemy_db_t *enemies_db);
void change_hpbar(player_t *player);
void change_xpbar(player_t *player);
void enemy_anim(enemy_t *enemy, sfVector2f next_coords);
void enemy_attack(repo_t *repo, enemy_t *enemy);
int enemy_attacked(repo_t *repo, enemy_t *enemy);
void enemy_hub(repo_t *repo, enemy_t **enemies);
void enemy_move(repo_t *repo, enemy_t *enemy);
int *find_path(char **collisions, int *start, int *end);
void free_enemies(enemy_t **enemies);
grid_t *init_grid(int *start);
void player_attacked(repo_t *repo, enemy_t *enemy);

#endif /* ENEMY_H_ */
