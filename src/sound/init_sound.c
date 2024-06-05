/*
** EPITECH PROJECT, 2024
** gitaction-mirror
** File description:
** init_sound
*/

#include "rpg.h"

sound_t *init_sound(char *path)
{
    sound_t *sound = malloc(sizeof(sound_t));

    sound->sound = sfSound_create();
    sound->buff = sfSoundBuffer_createFromFile(path);
    sfSound_setBuffer(sound->sound, sound->buff);
    return sound;
}
