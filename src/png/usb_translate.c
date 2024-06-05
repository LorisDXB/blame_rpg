/*
** EPITECH PROJECT, 2024
** gitaction-mirror
** File description:
** usb_translate
*/

#include "rpg.h"

void detect_usb_key(repo_t *repo)
{
    if (strcmp(repo->player->wep->name, "translator") == 0) {
        if (repo->room->is_png == 1 && repo->room->png->trans == 0) {
            sfFont_destroy(repo->room->png->text->font);
            repo->room->png->text->font =
            sfFont_createFromFile(
                "./assets/fonts/AdventureRequest-j8W9.ttf");
            sfText_setFont(repo->room->png->text->text,
            repo->room->png->text->font);
            repo->room->png->trans = 1;
        }
    } else {
        if (repo->room->is_png == 1 && repo->room->png->trans == 1) {
            sfFont_destroy(repo->room->png->text->font);
            repo->room->png->text->font =
            sfFont_createFromFile("./assets/fonts/ZazerSquare.otf");
            sfText_setFont(repo->room->png->text->text,
            repo->room->png->text->font);
            repo->room->png->trans = 0;
        }
    }
}
