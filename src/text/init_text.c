/*
** EPITECH PROJECT, 2024
** gitaction-mirror
** File description:
** init_text
*/

#include "rpg.h"

text_t *init_text_png(char *path, char *sentence)
{
    text_t *text = malloc(sizeof(text_t));

    text->font = sfFont_createFromFile(path);
    text->text = sfText_create();
    sfText_setFont(text->text, text->font);
    sfText_setString(text->text, "");
    text->msg = strdup(sentence);
    return text;
}
