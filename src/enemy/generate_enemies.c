/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** generate_enemies.c
*/

#include "rpg.h"

static int sub_count_en(char **collision, int i)
{
    int count = 0;

    for (int j = 0; collision[i][j] != '\0'; j++) {
        if (collision[i][j] == 'E')
            count++;
    }
    return count;
}

static int count_en(char **collision)
{
    int count = 0;

    for (int i = 0; collision[i] != NULL; i++)
        count += sub_count_en(collision, i);
    return count;
}

static int count_en_db(enemy_db_t *enemies_db)
{
    int count = 0;
    enemy_db_t *tmp = enemies_db;

    while (tmp) {
        count++;
        tmp = tmp->next;
    }
    return count;
}

static enemy_t *get_enemy_coords(enemy_t *enemy, int i, int j)
{
    sfVector2f coords = {j * 155, i * 155};

    enemy->coords = coords;
    sfSprite_setPosition(enemy->sprite->spr, coords);
    sfCircleShape_setPosition(enemy->range, coords);
    sfCircleShape_setPosition(enemy->detect, coords);
    enemy->lifebar->pos = (sfVector2f){coords.x, coords.y + sfSprite_getOrigin
        (enemy->sprite->spr).y / 2 + 20};
    sfRectangleShape_setPosition(enemy->lifebar->back, enemy->lifebar->pos);
    sfRectangleShape_setPosition(enemy->lifebar->hp_rem, enemy->lifebar->pos);
    return enemy;
}

static enemy_t **sub_generate_enemies(enemy_t **enemies, char **collision,
    int i, int *index)
{
    for (int j = 0; collision[i][j] != '\0'; j++) {
        if (collision[i][j] == 'E') {
            enemies[*index] = get_enemy_coords(enemies[*index], i, j);
            *index += 1;
        }
    }
    return enemies;
}

enemy_t **generate_enemies(enemy_db_t *enemies_db, char *path_col)
{
    char **collision = get_grid(path_col);
    enemy_t **enemies = malloc(sizeof(enemy_t *) * (count_en(collision) + 1));
    int random = 0;
    int index = 0;

    if (count_en(collision) == 0)
        return NULL;
    for (int i = 0; i < count_en(collision); i++) {
        random = rand() % count_en_db(enemies_db);
        enemies[i] = init_enemy(enemies_db, random);
    }
    for (int i = 0; collision[i] != NULL; i++)
        enemies = sub_generate_enemies(enemies, collision, i, &index);
    enemies[count_en(collision) - 1] = NULL;
    free_array(collision);
    return enemies;
}

void add_enemies(room_t **full_dongeon, enemy_db_t *enemies_db)
{
    room_t *tmp = *full_dongeon;

    while (tmp) {
        tmp->enemies = generate_enemies(enemies_db, tmp->colision);
        tmp = tmp->next;
    }
}
