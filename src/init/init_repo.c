/*
** EPITECH PROJECT, 2024
** init repo
** File description:
** init repo for rpg
*/

#include "../../include/rpg.h"

char **get_grid(char *coli)
{
    int fd = open(coli, O_RDONLY);
    struct stat sb;
    char *str = NULL;
    char **tab = NULL;

    stat(coli, &sb);
    str = malloc(sizeof(char) * (sb.st_size + 1));
    str[sb.st_size] = '\0';
    read(fd, str, sb.st_size);
    tab = str_to_array(str, "\n");
    close(fd);
    return tab;
}

static map_t *init_map(room_t *room)
{
    map_t *map = malloc(sizeof(map_t));

    map->coords.x = 0;
    map->coords.y = 0;
    map->sprite = create_spritet(room->path, (sfVector2f){M_SCALE, M_SCALE});
    map->sec_layer = create_spritet("./assets/maps/spawn/spawn2.png",
    (sfVector2f){M_SCALE, M_SCALE});
    map->collision = get_grid(room->colision);
    return map;
}

void set_t_2(set_t *set)
{
    set->transition = create_rectangle((sfVector2f){3000, 3000},
            (sfVector2f){0, 0}, sfBlack);
    set->png_text = sfTexture_createFromFile(
        "./assets/sprites/png/Robots.png", NULL);
    set->png_space = sfTexture_createFromFile(
        "./assets/sprites/png/space.png", NULL);
    set->png_sound = init_sound("./assets/sprites/png/robot_sound.ogg");
}

static set_t *init_set(void)
{
    set_t *set = malloc(sizeof(set_t));

    set->mode.width = 1920;
    set->mode.height = 1080;
    set->mode.bitsPerPixel = 32;
    set->despawn = 0;
    set->w = sfRenderWindow_create(set->mode, "BLAME!",
        sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(set->w, 60);
    set->clock = sfClock_create();
    set->png = sfClock_create();
    set->text = sfClock_create();
    set->trans_time = sfClock_create();
    set->debounce = sfClock_create();
    set->en_debounce = sfClock_create();
    set->transition_request = 0;
    set->death_request = 0;
    set_t_2(set);
    return set;
}

static main_menu_t *init_main_menu(void)
{
    main_menu_t *menu = malloc(sizeof(main_menu_t));

    menu->id_main = false;
    menu->id_settings = false;
    menu->id_window_size = false;
    menu->id_sound = false;
    menu->background = NULL;
    menu->font = sfFont_createFromFile("font/cyber_plein_font.otf");
    menu->rect = malloc(sizeof(rect_t) * 17);
    menu->text = malloc(sizeof(text_t) * 14);
    return menu;
}

static paral_t *init_paralax(repo_t *repo)
{
    paral_t *paral = malloc(sizeof(paral_t));
    sfImage *image = sfImage_createFromFile(
        "./assets/maps/vraibackground.png");

    paral->coo = (sfVector2f){repo->player->coords.x + 200,
    repo->player->coords.y + 200};
    paral->back = create_spritet(
        "./assets/maps/vraibackground.png", (sfVector2f){5, 5});
    sfSprite_setOrigin(paral->back->spr, (
        sfVector2f){sfImage_getSize(image).x / 2,
        sfImage_getSize(image).y / 2});
    sfSprite_setColor(paral->back->spr, (sfColor){51, 21, 65, 255});
    sfSprite_setPosition(paral->back->spr, paral->coo);
    sfImage_destroy(image);
    return paral;
}

static ig_menu_t *init_ingame_menu(void)
{
    ig_menu_t *menu = malloc(sizeof(ig_menu_t));

    menu->id_menu = false;
    menu->id_inv = false;
    menu->id_skill = false;
    menu->id_settings = false;
    menu->id_save = false;
    menu->id_load = false;
    menu->w_pos = (sfVector2f){0, 0};
    menu->w_scale = (sfVector2f){0, 0};
    menu->rect = malloc(sizeof(rect_t) * 5);
    menu->sprite = malloc(sizeof(sprite_ig_t) * 5);
    return menu;
}

repo_t *init_repo(void)
{
    repo_t *repo = malloc(sizeof(repo_t));
    int **matrice = generate_matrice_adjacente(100);

    repo->set = init_set();
    repo->full_dongeons = matrice_to_liste(matrice, 100, repo);
    repo->db = init_db();
    add_enemies(&(repo->full_dongeons), repo->db->enemies);
    repo->room = go_to_room(&repo->full_dongeons, 0);
    repo->player = init_player(repo);
    repo->map = init_map(repo->room);
    repo->view = 1.2;
    repo->paral = init_paralax(repo);
    repo->main_menu = init_main_menu();
    repo->ig_menu = init_ingame_menu();
    repo->help = init_help();
    repo->musics = init_musics();
    return repo;
}
