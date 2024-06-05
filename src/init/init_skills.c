/*
** EPITECH PROJECT, 2024
** init_skills
** File description:
** for rpg
*/

#include "../../include/rpg.h"

static sprite_t *init_sprite(void)
{
    sprite_t *ret = malloc(sizeof(sprite_t));
    sfFloatRect bounds = {0, 0};

    ret->spr = sfSprite_create();
    ret->scl = (sfVector2f){1.7, 1.3};
    ret->tex = sfTexture_createFromFile(SK_TEX, 0);
    sfSprite_setTexture(ret->spr, ret->tex, 0);
    sfSprite_setScale(ret->spr, ret->scl);
    bounds = sfSprite_getLocalBounds(ret->spr);
    sfSprite_setOrigin(ret->spr,
            (sfVector2f){bounds.width / 2, bounds.height / 2});
    return ret;
}

static sfRectangleShape *init_rectangle(void)
{
    sfRectangleShape *ret = sfRectangleShape_create();
    sfFloatRect bounds;

    sfRectangleShape_setSize(ret, (sfVector2f){40, 40});
    bounds = sfRectangleShape_getLocalBounds(ret);
    sfRectangleShape_setOrigin(ret,
        (sfVector2f){bounds.width / 2, bounds.height / 2});
    sfRectangleShape_setFillColor(ret, sfColor_fromRGBA(60, 60, 60, 155));
    sfRectangleShape_setOutlineThickness(ret, 2);
    sfRectangleShape_setOutlineColor(ret, sfBlack);
    return ret;
}

static sfText *init_text(sfFont *font)
{
    sfText *ret = sfText_create();

    sfText_setScale(ret, (sfVector2f){0.8, 0.7});
    sfText_setOrigin(ret, (sfVector2f){0, 0});
    sfText_setColor(ret, sfBlack);
    sfText_setFont(ret, font);
    return ret;
}

static sprite_t *init_item_sprite(sfTexture *tex, int id)
{
    sprite_t *ret = malloc(sizeof(sprite_t));
    sfFloatRect bounds = {0, 0};

    ret->spr = sfSprite_create();
    ret->scl = (sfVector2f){0.25, 0.25};
    ret->tex = tex;
    ret->id = id;
    sfSprite_setTexture(ret->spr, ret->tex, 0);
    sfSprite_setScale(ret->spr, ret->scl);
    bounds = sfSprite_getLocalBounds(ret->spr);
    sfSprite_setOrigin(ret->spr,
        (sfVector2f){bounds.width / 2, bounds.height / 2});
    return ret;
}

sprite_t **init_buttons(skills_t *sk)
{
    sprite_t **ret = malloc(sizeof(sprite_t *) * (4 + 1));
    int i = 0;

    for (i = 0; i < 4; i++) {
        ret[i] = init_item_sprite(sk->b_tex, i);
    }
    ret[i] = NULL;
    return ret;
}

skills_t *init_skills(repo_t *repo)
{
    skills_t *sk = malloc(sizeof(skills_t));

    sk->font = sfFont_createFromFile(INV_FONT);
    sk->hover = init_rectangle();
    sk->text = init_text(sk->font);
    sk->spr = malloc(sizeof(sprite_t));
    sk->spr = init_sprite();
    sk->name = 34;
    sk->b_tex = sfTexture_createFromFile(BUTTON_TEX, NULL);
    fetch_skills(sk);
    sk->buttons = init_buttons(sk);
    return sk;
}
