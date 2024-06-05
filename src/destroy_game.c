/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** destroy_game.c
*/

#include "rpg.h"

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        if (array[i])
            free(array[i]);
    }
    free(array);
}

void destroy_spritet(sprite_t *sprite)
{
    if (sprite) {
        if (sprite->spr)
            sfSprite_destroy(sprite->spr);
        if (sprite->tex)
            sfTexture_destroy(sprite->tex);
        free(sprite);
    }
}

static void destroy_player(player_t *player)
{
    if (player) {
        if (player->view)
            sfView_destroy(player->view);
        if (player->sprite)
            destroy_spritet(player->sprite);
        free(player);
    }
}

static void destroy_map(map_t *map)
{
    if (map) {
        if (map->sprite)
            destroy_spritet(map->sprite);
        if (map->collision)
            free_array(map->collision);
        free(map);
    }
}

static void destroy_set(set_t *set)
{
    if (set) {
        if (set->clock)
            sfClock_destroy(set->clock);
        if (set->w)
            sfRenderWindow_destroy(set->w);
        free(set);
    }
}

static void destroy_musics(sound_t **musics)
{
    for (int i = 0; i < 3; i++) {
        sfSoundBuffer_destroy(musics[i]->buff);
        sfSound_destroy(musics[i]->sound);
        free(musics[i]);
    }
    free(musics);
}

void destroy_game(repo_t *repo)
{
    if (repo) {
        destroy_player(repo->player);
        destroy_map(repo->map);
        destroy_set(repo->set);
        destroy_musics(repo->musics);
        free(repo);
    }
}
