/*
** EPITECH PROJECT, 2024
** gitaction-mirror
** File description:
** talk_png
*/

#include "rpg.h"

char *charcat(const char *str, char c)
{
    int len = strlen(str) + 1;
    char *new = malloc(sizeof(char) * (len + 1));

    for (int i = 0; str[i] != '\0'; i++)
        new[i] = str[i];
    new[len - 1] = c;
    new[len] = '\0';
    return new;
}

void text_machine_png(repo_t *repo)
{
    int len = strlen(repo->room->png->text->msg);
    static int i = 0;
    char *str;
    float sec =
        sfClock_getElapsedTime(repo->set->text).microseconds / 1000000.0;

    if (repo->room->png->space == 1) {
        if (sec >= 0.05 && i < len) {
            str = charcat(sfText_getString(repo->room->png->text->text),
            repo->room->png->text->msg[i]);
            sfText_setString(repo->room->png->text->text, str);
            free(str);
            sfClock_restart(repo->set->text);
            i++;
        }
    } else {
        i = 0;
        sfText_setString(repo->room->png->text->text, "");
    }
}

void show_text_png(repo_t *repo)
{
    if (repo->room->png->space == 1) {
        if (repo->room->png->trans == 0) {
            repo->db->quest[2]->status = ONGOING;
            save_quests(repo);
            sfText_setPosition(repo->player->trans->text,
            (sfVector2f){repo->player->coords.x - 200,
            repo->player->coords.y - 100});
            repo->player->png_trans = 1;
            sfRenderWindow_drawText(repo->set->w,
            repo->player->trans->text, NULL);
        } else
            repo->player->png_trans = 0;
        sfRenderWindow_drawText(repo->set->w,
        repo->room->png->text->text, NULL);
    }
    text_machine_png(repo);
}
