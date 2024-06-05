/*
** EPITECH PROJECT, 2024
** rpg .h
** File description:
** rpg
*/

#ifndef MY_RPG_H_
    #define MY_RPG_H_

    #include "assets.h"
    #include "creation.h"
    #include "enemy.h"
    #include "init.h"
    #include "menu_ig.h"
    #include "menu_main.h"
    #include "parameters.h"
    #include "parsing.h"
    #include "standard.h"
    #include "struct.h"
    #include <time.h>
    #include "png.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <fcntl.h>
    #include <sys/stat.h>

void add_node(weapon_t **head, char *dicti, int id);
int check_inventory_bis(sfFloatRect rect, sfVector2f ms,
    repo_t *repo, int i);
int coll_update(repo_t *repo);
void destroy_game(repo_t *repo);
void destroy_spritet(sprite_t *sprite);
void draw_bars(sfRenderWindow *win, player_t *player);
void draw_item(repo_t *repo);
int draw_item_information(repo_t *repo);
void draw_item_sprites(sprite_t **ct, repo_t *repo);
void draw_player(repo_t *repo);
void draw_sprites(repo_t *repo);
void fade_transition(repo_t *repo);
weapon_t *fetch_inventory(repo_t *repo);
sprite_t **fetch_sprites(weapon_t **head);
void fetch_weps(weapon_t *wep);
void follow_mouse(repo_t *repo, sfSprite *sprite);
void free_array(char **array);
char **get_grid(char *coli);
weapon_t *get_list_index(weapon_t **head, int index);
int *get_position(sfVector2f coords);
void handle_clicks(repo_t *repo);
void handle_events(repo_t *repo, sfVector2f ms);
void handle_keys(repo_t *repo);
void handle_view(repo_t *repo);
inventory_t *init_inventory(repo_t *repo);
repo_t *init_repo(void);
void m1_cd(repo_t *repo);
void print_help(void);
char **recup_file_name(char *dir, char *end);
int robustness(int argc, char **argv);
void save_inventory(repo_t *repo);
void show_list(weapon_t **head);
void tp_player(repo_t *repo);
png_t *init_png(char *path, repo_t *repo);
void loop_rect_png(repo_t *repo);
void draw_png(repo_t *repo);
void show_text_png(repo_t *repo);
void zone_png(repo_t *repo);
void event_png(sfRenderWindow *window, sfEvent event, repo_t *repo);
void show_text_png(repo_t *repo);
int **create_matrice(int lenght);
int **add_link(int **matrice, int posA, int posB);
void show_matrice(int **matrice, int lenght);
int **generate_matrice_adjacente(int nbr_piece);
room_t *matrice_to_liste(int **matrice, int nbr_piece, repo_t *repo);
void show_liste(room_t *room);
void show_matrice(int **matrice, int lenght);
void save_dongeons(room_t *room);
void recup_dongeons(void);
void free_matrice(int **matrice, int nbr);
void free_liste(room_t *room);
room_t *room_to_room(room_t *first, int door, room_t **laby);
int **if_matrice(int *i, int *repate, int **matrice);
int verif_door(int **matrice, int nbr, int used);
char *choose_room(int nbr_door);
char *recup_colision_map(room_t *room);
room_t *recup_door_pos(room_t *room);
room_t *go_to_room(room_t **room, int id);
char *file_to_buff(char *path);
void draw_png(repo_t *repo);
text_t *init_text_png(char *path, char *sentence);
sound_t *init_sound(char *path);
void reset_keys(int *keys);
void check_skills_bis(sfFloatRect rect, sfVector2f ms, repo_t *repo, int i);
void idle_animation(repo_t *repo, int *ft);
void run_animation(repo_t *repo);
void movement_keys(repo_t *repo, int ck, int y, int x);
int use_wep(repo_t *repo);
sfRectangleShape *wep_hitbox_gen(weapon_t *wep);
weapon_t *wep_selector(int id, weapon_t **head);
void window_loop(repo_t *repo);
int wep_len(weapon_t **head);
void wep_deletor(weapon_t **head, int id);
void wep_deletor_index(weapon_t **head, int index);
skills_t *init_skills(repo_t *repo);
void fetch_skills(skills_t *sk);
void draw_skill_text(repo_t *repo);
void draw_button_sprites(sprite_t **ct, repo_t *repo);
int exp_calc(repo_t *repo);
void save_skills(repo_t *repo);
void draw_hover(repo_t *repo, sfSprite *button);
void detect_usb_key(repo_t *repo);
void post_death(enemy_t *enemy, repo_t *repo);
void dropped_weapon(repo_t *repo);
char *charcat(const char *str, char c);
char *string_rand(char *path);
void death_animation(repo_t *repo);
help_t *init_help(void);
void death_transition(repo_t *repo);
void show_qu_list(quest_t **head);
void draw_quests(repo_t *repo);
quest_t *init_quests(char **qtmp, sfFont *font, int id);
quest_t **fetch_quests(sfFont *font);
void save_quests(repo_t *repo);
weapon_t *add_inventory_node(weapon_t **head, repo_t *repo);
void quest_checks(repo_t *repo);
void affiche_help(repo_t *repo);
void dash_in_direction(repo_t *repo);
void dash_cd(repo_t *repo);
void dash_sound(repo_t *repo);
void reset_player(repo_t *repo);
void write_message(repo_t *repo, char *str);
int file_robustness(char *path);

#endif
