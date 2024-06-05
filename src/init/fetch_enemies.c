/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** fetch_enemies.c
*/

#include "rpg.h"

static enemy_db_t *add_enemy(enemy_db_t *enemies, char *line, int id)
{
    char **info = str_to_array(line, ";");
    enemy_db_t *en = malloc(sizeof(enemy_db_t));

    en->enemy = init_enemy_db(info);
    en->id = id;
    en->next = enemies;
    enemies = en;
    free_array(info);
    return enemies;
}

static char *get_dict(void)
{
    int fd = open("dictionary/enemies.list", O_RDONLY);
    struct stat st;
    char *buff = NULL;

    stat("dictionary/enemies.list", &st);
    buff = malloc(sizeof(char) * (st.st_size));
    read(fd, buff, st.st_size);
    buff[st.st_size - 1] = '\0';
    close(fd);
    return buff;
}

enemy_db_t *fetch_enemies(enemy_db_t *enemies)
{
    char *buffer = get_dict();
    char **dict = str_to_array(buffer, "\n");

    for (int i = 0; dict[i] != NULL; i++)
        enemies = add_enemy(enemies, dict[i], i);
    return enemies;
}
