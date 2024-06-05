/*
** EPITECH PROJECT, 2024
** key hub for rpg
** File description:
** key hub
*/

#include "../include/rpg.h"

static pos_t which_door(repo_t *repo)
{
    if (repo->room_past == repo->room->door_1)
        return repo->room->pos1;
    if (repo->room_past == repo->room->door_2)
        return repo->room->pos2;
    if (repo->room_past == repo->room->door_3)
        return repo->room->pos3;
    if (repo->room_past == repo->room->door_4)
        return repo->room->pos4;
}

static void sub_tp_player(repo_t *repo, pos_t pos_door)
{
    if (repo->map->collision[pos_door.y - 1][pos_door.x] != '#') {
        repo->player->coords = (sfVector2f){pos_door.x * 160,
            (pos_door.y - 1) * 160};
        repo->paral->coo = repo->player->coords;
        sfSprite_setPosition(repo->paral->back->spr, repo->paral->coo);
        return;
    }
}

void tp_player(repo_t *repo)
{
    pos_t pos_door = which_door(repo);

    if (repo->map->collision[pos_door.y][pos_door.x + 1] != '#') {
        repo->player->coords = (sfVector2f){(pos_door.x + 1) * 160,
            pos_door.y * 160};
        return;
    }
    if (repo->map->collision[pos_door.y + 1][pos_door.x] != '#') {
        repo->player->coords = (sfVector2f){pos_door.x * 160,
            (pos_door.y + 1) * 160};
        return;
    }
    if (repo->map->collision[pos_door.y][pos_door.x - 1] != '#') {
        repo->player->coords = (sfVector2f){(pos_door.x - 1) * 160,
            pos_door.y * 160};
        return;
    }
    sub_tp_player(repo, pos_door);
}

static void change_room_sprite(repo_t *repo, int door)
{
    repo->set->transition_request = 1;
    repo->room_past = repo->room->index;
    repo->room = room_to_room(repo->room, door, &repo->full_dongeons);
    coll_update(repo);
}

static void player_on_door(repo_t *repo, int x, int y)
{
    if (repo->room->pos1.x == x && repo->room->pos1.y == y)
        change_room_sprite(repo, 1);
    if (repo->room->nbr_door > 1)
        if (repo->room->pos2.x == x && repo->room->pos2.y == y)
            change_room_sprite(repo, 2);
    if (repo->room->nbr_door > 2)
        if (repo->room->pos3.x == x && repo->room->pos3.y == y)
            change_room_sprite(repo, 3);
    if (repo->room->nbr_door > 3)
        if (repo->room->pos4.x == x && repo->room->pos4.y == y)
            change_room_sprite(repo, 4);
}

static void handle_movements(repo_t *repo)
{
    int y = floor(repo->player->coords.y / 160);
    int x = floor(repo->player->coords.x / 160);
    int ck = repo->set->transition_request;

    movement_keys(repo, ck, y, x);
    player_on_door(repo, x, y);
}

static void handle_dash(repo_t *repo)
{
    if (sfKeyboard_isKeyPressed(sfKeyA) && repo->player->dash != CD
        || repo->player->dash == PROC) {
        if (repo->player->skills->agi < 10 || repo->set->death_request == 1) {
            write_message(repo, ">the wind isn't called forth.<");
            return;
        }
        if (repo->player->dash == OFF) {
            sfClock_restart(repo->set->debounce);
            dash_sound(repo);
        }
        repo->player->dash = PROC;
        dash_in_direction(repo);
    }
    if (repo->player->dash == CD)
        dash_cd(repo);
}

static void handle_requests(repo_t *repo, int debounce, sfTime elapsed)
{
    if (sfKeyboard_isKeyPressed(sfKeyNum2)) {
        repo->player->eq = SUP;
    }
    if (sfKeyboard_isKeyPressed(sfKeyNum1)) {
        repo->player->eq = WEP;
    }
    handle_dash(repo);
    if (sfKeyboard_isKeyPressed(sfKeyNum3)) {
        repo->player->eq = EMP;
    }
    if (sfKeyboard_isKeyPressed(sfKeyE)) {
        elapsed = sfClock_getElapsedTime(repo->set->debounce);
        if (sfTime_asMilliseconds(elapsed) > debounce) {
            repo->player->inv->status =
            (repo->player->inv->status == CLOSE) ? OPEN : CLOSE;
            sfClock_restart(repo->set->debounce);
        }
    }
}

void handle_keys(repo_t *repo)
{
    int debounce = 200;
    sfTime elapsed;

    reset_keys(repo->player->key_press);
    if (repo->set->death_request != 1)
        handle_movements(repo);
    handle_requests(repo, debounce, elapsed);
}
