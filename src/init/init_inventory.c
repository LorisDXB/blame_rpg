/*
** EPITECH PROJECT, 2024
** init_inventory
** File description:
** init_invetory
*/

#include "../../include/rpg.h"

static sprite_t *init_sprite(void)
{
    sprite_t *ret = malloc(sizeof(sprite_t));
    sfFloatRect bounds = {0, 0};

    ret->spr = sfSprite_create();
    ret->scl = (sfVector2f){1.9, 1.9};
    ret->tex = sfTexture_createFromFile(INV_TEX, 0);
    sfSprite_setTexture(ret->spr, ret->tex, 0);
    sfSprite_setScale(ret->spr, ret->scl);
    bounds = sfSprite_getLocalBounds(ret->spr);
    sfSprite_setOrigin(ret->spr,
        (sfVector2f){bounds.width / 2, bounds.height / 2});
    return ret;
}

static sprite_t *init_item_sprite(sfTexture *tex, int id)
{
    sprite_t *ret = malloc(sizeof(sprite_t));
    sfFloatRect bounds = {0, 0};

    ret->spr = sfSprite_create();
    ret->scl = (sfVector2f){1.65, 1.65};
    ret->tex = tex;
    ret->id = id;
    sfSprite_setTexture(ret->spr, ret->tex, 0);
    sfSprite_setScale(ret->spr, ret->scl);
    sfSprite_setRotation(ret->spr, -45);
    bounds = sfSprite_getLocalBounds(ret->spr);
    sfSprite_setOrigin(ret->spr,
        (sfVector2f){bounds.width / 2, bounds.height / 2});
    return ret;
}

sprite_t **fetch_sprites(weapon_t **head)
{
    sprite_t **ret = malloc(sizeof(sprite_t *) * (wep_len(head) + 1));
    int i = 0;
    weapon_t *tmp = NULL;

    for (i = 0; i < wep_len(head); i++) {
        tmp = get_list_index(head, i + 1);
        ret[i] = init_item_sprite(tmp->spr->tex, tmp->id);
    }
    ret[i] = NULL;
    return ret;
}

static sfRectangleShape *init_rectangle(void)
{
    sfRectangleShape *ret = sfRectangleShape_create();
    sfFloatRect bounds;

    sfRectangleShape_setSize(ret, (sfVector2f){234, 114});
    bounds = sfRectangleShape_getLocalBounds(ret);
    sfRectangleShape_setOrigin(ret, (sfVector2f){-15, -25});
    sfRectangleShape_setFillColor(ret, sfColor_fromRGB(128, 128, 128));
    sfRectangleShape_setOutlineThickness(ret, 2);
    sfRectangleShape_setOutlineColor(ret, sfBlack);
    return ret;
}

static sfText *init_text(sfFont *font, sfVector2f org,
    sfVector2f scl, sfColor rgb)
{
    sfText *ret = sfText_create();

    sfText_setScale(ret, org);
    sfText_setOrigin(ret, scl);
    sfText_setColor(ret, rgb);
    sfText_setFont(ret, font);
    return ret;
}

inventory_t *init_inventory(repo_t *repo)
{
    inventory_t *inv = malloc(sizeof(inventory_t));

    inv->font = sfFont_createFromFile(INV_FONT);
    inv->rect = init_rectangle();
    inv->text = init_text(inv->font, (sfVector2f){0.66, 0.66},
        (sfVector2f){-35, -45}, sfBlack);
    inv->drop = init_text(inv->font, (sfVector2f){1, 1},
        (sfVector2f){80, 0}, sfWhite);
    sfText_setString(inv->drop, "< you found a weapon! >");
    inv->drop_ck = 0;
    inv->spr = malloc(sizeof(sprite_t));
    inv->spr = init_sprite();
    inv->content = fetch_inventory(repo);
    if (inv->content != NULL)
        inv->items = fetch_sprites(&(inv->content));
    inv->status = CLOSE;
    return inv;
}
