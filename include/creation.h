/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** creation.h
*/

#ifndef CREATION_H_
    #define CREATION_H_

    #include "standard.h"
    #include "struct.h"

sfCircleShape *create_circle(float radius, sfVector2f pos);
sfRectangleShape *create_rectangle(sfVector2f size, sfVector2f pos,
    sfColor color);
sprite_t *create_spritet(char *path, sfVector2f scale);

#endif /* CREATION_H_ */
