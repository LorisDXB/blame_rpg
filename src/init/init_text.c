/*
** EPITECH PROJECT, 2024
** rpg-loryce.gode
** File description:
** init_text
*/

#include "../../include/rpg.h"

sfText *get_text(sfVector2f pos, unsigned int size, char *msg, sfFont *font)
{
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setPosition(text, pos);
    sfText_setString(text, msg);
    sfText_setFillColor(text, sfColor_fromRGB(188, 19, 254));
    sfText_setCharacterSize(text, size);
    return text;
}
