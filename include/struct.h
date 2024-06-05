/*
** EPITECH PROJECT, 2024
** parsing.h
** File description:
** parsing.h
*/

#ifndef MY_STRUCT_H_
    #define MY_STRUCT_H_
    #include "standard.h"
    #include "dongeon.h"

typedef struct text_s {
    sfVector2f pos;
    unsigned int size;
    char *msg;
    sfFont *font;
    sfText *text;
} text_t;

typedef struct sprite_ig_s {
    sfVector2f pos;
    sfVector2f scale;
    sfTexture *texture;
    sfSprite *sprite;
} sprite_ig_t;

typedef struct rect_s {
    sfVector2f scale;
    sfVector2f pos;
    sfColor color;
    sfFloatRect collider;
    sfRectangleShape *rectangle;
} rect_t;

typedef struct ig_menu_s {
    bool id_menu;
    bool id_inv;
    bool id_skill;
    bool id_settings;
    bool id_save;
    bool id_load;
    sfVector2f w_pos;
    sfVector2f w_scale;
    sfFont *font;
    rect_t *rect;
    text_t *text;
    sprite_ig_t *sprite;
} ig_menu_t;

typedef struct main_menu_s {
    bool id_main;
    bool id_settings;
    bool id_window_size;
    bool id_sound;
    sfFont *font;
    rect_t *rect;
    text_t *text;
    sfSprite *background;
} main_menu_t;

typedef struct grid_s {
    int **dist;
    bool **explored;
    int **parent;
} grid_t;

typedef struct sprite_s {
    sfSprite *spr;
    sfTexture *tex;
    sfVector2f scl;
    sfIntRect rect;
    int id;
} sprite_t;

typedef struct slash_s {
    int appear;
    sfClock *cooldown;
    sprite_t *sprite;
    sfClock *clock;
} slash_t;

typedef struct lifebar_s {
    sfVector2f pos;
    sfRectangleShape *hp_rem;
    sfRectangleShape *back;
    sfClock *clock;
} lifebar_t;

typedef struct enemy_s {
    char *name;
    int full_hp;
    int hp;
    int attack;
    float speed;
    float cd;
    sfVector2f coords;
    sprite_t *sprite;
    slash_t *slash;
    lifebar_t *lifebar;
    int xp_rew;
    sfCircleShape *range;
    sfCircleShape *detect;
    sfClock *clock;
} enemy_t;

typedef struct enemy_db_s {
    int id;
    enemy_t *enemy;
    struct enemy_db_s *next;
} enemy_db_t;

enum hotslot {
    WEP = 1,
    SUP = 2,
    EMP = 0
};

typedef struct support_s {
    sprite_t *spr;
    int uses_left;
} support_t;

enum status {
    PROC = 1,
    CD = 2,
    OFF = 0
};

enum invstatus {
    OPEN = 1,
    CLOSE = 0
};

typedef struct weapon_s {
    sprite_t *spr;
    int id;
    int atk;
    int speed;
    char *name;
    float cd;
    sfRectangleShape *hitbox;
    sfClock *clock;
    enum status an;
    struct weapon_s *next;
} weapon_t;

typedef struct skills_s {
    sfFont *font;
    sprite_t *spr;
    int name;
    int str;
    int fort;
    int agi;
    int cha;
    int lvl;
    int xp;
    int pts;
    sfTexture *b_tex;
    sprite_t **buttons;
    sfRectangleShape *hover;
    sfText *text;
} skills_t;

typedef struct inventory_s {
    sfFont *font;
    sprite_t *spr;
    weapon_t *content;
    sprite_t **items;
    sfRectangleShape *rect;
    sfText *text;
    sfText *drop;
    int drop_ck;
    enum invstatus status;
} inventory_t;

typedef struct bar_s {
    sprite_t *sprite;
    sfRectangleShape *back;
    sfRectangleShape *rem;
    sfClock *clock;
} bar_t;

typedef struct player_s {
    bar_t *hpbar;
    bar_t *xpbar;
    int full_hp;
    int hp;
    int attack;
    float speed;
    int *key_press;
    enum hotslot eq;
    enum status dash;
    sfVector2f coords;
    sfView *view;
    sprite_t *sprite;
    inventory_t *inv;
    skills_t *skills;
    sfTexture *run;
    sfTexture *death;
    sfClock *clock;
    weapon_t *wep;
    support_t *sup;
    text_t *trans;
    text_t *text;
    sfClock *wait;
    sfClock *text_c;
    sfClock *png;
    int speak;
    int mouve;
    int png_trans;
} player_t;

typedef struct map_s {
    sfVector2f coords;
    sprite_t *sprite;
    sprite_t *sec_layer;
    char **collision;
    char **col_org;
} map_t;

typedef struct sound_s {
    sfSound *sound;
    sfSoundBuffer *buff;
} sound_t;

typedef struct help_s {
    sprite_t *sprite;
    sfVector2f coo;
    int show;
} help_t;

typedef struct set_s {
    sfVideoMode mode;
    sfRenderWindow *w;
    int despawn;
    sfEvent ev;
    sfClock *clock;
    sfClock *debounce;
    sfClock *en_debounce;
    sfClock *trans_time;
    sfClock *png;
    sfClock *text;
    int transition_request;
    int death_request;
    sfRectangleShape *transition;
    sfTexture *png_text;
    sfTexture *png_space;
    sound_t *png_sound;
} set_t;

enum q_status {
    NOTFOUND = 0,
    ONGOING = 1,
    DONE = 2
};

typedef struct quest_s {
    char *goal;
    int xp_rew;
    int id;
    sfText *txt;
    enum q_status status;
} quest_t;

typedef struct db_s {
    sfFont *font;
    weapon_t *wep;
    quest_t **quest;
    enemy_db_t *enemies;
} db_t;

typedef struct paral_s {
    sprite_t *back;
    sfVector2f coo;
} paral_t;

typedef struct png_s {
    sprite_t *sprite;
    sprite_t *spa;
    text_t *text;
    sfVector2f pos;
    sound_t *sound;
    int affiche;
    int space;
    int trans;
} png_t;

typedef struct pos_s {
    int x;
    int y;
} pos_t;

typedef struct room_s {
    int index;
    char *name;
    char *path;
    char *colision;
    enemy_t **enemies;
    int door_1;
    int door_2;
    int door_3;
    int door_4;
    int nbr_door;
    png_t *png;
    int is_png;
    pos_t pos1;
    pos_t pos2;
    pos_t pos3;
    pos_t pos4;
    struct room_s *next;
} room_t;

typedef struct repo_s {
    int room_past;
    float view;
    player_t *player;
    room_t *full_dongeons;
    room_t *room;
    enemy_t *enemy;
    map_t *map;
    set_t *set;
    db_t *db;
    paral_t *paral;
    main_menu_t *main_menu;
    ig_menu_t *ig_menu;
    help_t *help;
    sound_t **musics;
} repo_t;

#endif
