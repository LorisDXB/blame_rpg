/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** init_musics.c
*/

#include "rpg.h"

static sound_t *init_music(char *path)
{
    sound_t *music = malloc(sizeof(sound_t));

    music->buff = sfSoundBuffer_createFromFile(path);
    music->sound = sfSound_create();
    sfSound_setBuffer(music->sound, music->buff);
    sfSound_setLoop(music->sound, sfTrue);
    return music;
}

sound_t **init_musics(void)
{
    sound_t **musics = malloc(sizeof(sound_t) * 3);

    musics[0] = init_music(HIPSHOP_ZIC);
    musics[1] = init_music(DAFALLS_ZIC);
    musics[2] = init_music(BUTTON_SFX);
    sfSound_setLoop(musics[2]->sound, sfFalse);
    sfSound_setVolume(musics[2]->sound, 1000);
    return musics;
}
