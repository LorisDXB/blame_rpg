/*
** EPITECH PROJECT, 2024
** gitaction-mirror
** File description:
** init_png
*/

#include "rpg.h"

char *string_rand(char *path)
{
    char *buff = file_to_buff(path);
    char **array = str_to_array(buff, "\n");
    int len = tablen(array);
    char *sentence = strdup(array[(rand() % len)]);

    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
    free(buff);
    return sentence;
}

static int y_rdm_png(void)
{
    int y = 0 + ((rand() % 26) * (832 / 26));

    return y;
}

static sfVector2f recup_pos_png(char *path)
{
    char *buff = file_to_buff(path);
    int x = 0;
    int y = 0;

    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == '\n') {
            y++;
            x = 0;
        }
        if (buff[i] == 'N')
            return ((sfVector2f){x * 160, y * 160});
        x++;
    }
}

void init_png_2(png_t *png)
{
    sfSprite_setTextureRect(png->sprite->spr, png->sprite->rect);
    sfSprite_setOrigin(png->sprite->spr,
    (sfVector2f){(192 / 8) / 2, (832 / 26) / 2});
    sfSprite_setPosition(png->sprite->spr, png->pos);
    png->trans = 1;
}

sprite_t *init_png_sprite(repo_t *repo, sfVector2f scale)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));

    sprite->spr = sfSprite_create();
    sfSprite_setTexture(sprite->spr, repo->set->png_text, 0);
    sprite->scl = scale;
    sfSprite_setScale(sprite->spr, sprite->scl);
    return sprite;
}

sprite_t *init_png_space(repo_t *repo, sfVector2f scale)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));

    sprite->spr = sfSprite_create();
    sfSprite_setTexture(sprite->spr, repo->set->png_space, 0);
    sprite->scl = scale;
    sfSprite_setScale(sprite->spr, sprite->scl);
    return sprite;
}

png_t *init_png(char *path, repo_t *repo)
{
    png_t *png = malloc(sizeof(png_t));

    png->pos = recup_pos_png(path);
    png->sound = repo->set->png_sound;
    png->text = init_text_png("./assets/fonts/ZazerSquare.otf",
    "./assets/sentence.txt");
    png->text->msg = string_rand("./assets/sentence.txt");
    sfText_setPosition(png->text->text, (sfVector2f){png->pos.x - ((strlen(
        png->text->msg) / 2) * 19), png->pos.y - ((832 / 26) * 5)});
    png->spa = init_png_space(repo,
    (sfVector2f){1.5, 1.5});
    sfSprite_setPosition(png->spa->spr, (sfVector2f){png->pos.x - ((
        192 / 8) * 1.5), png->pos.y - ((832 / 26) * 4)});
    png->sprite = init_png_sprite(repo,
    (sfVector2f){10, 10});
    png->sprite->rect = (sfIntRect){0, y_rdm_png(), 192 / 8, 832 / 26};
    init_png_2(png);
    return png;
}
