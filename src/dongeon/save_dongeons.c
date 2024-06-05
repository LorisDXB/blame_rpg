/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** save_dongeons
*/

#include "rpg.h"

void recup_dongeons(void)
{
    char path[] = "dng.sv";
    FILE *fd;
    room_t *room = NULL;
    room_t *tmp;

    fd = fopen(path, "r");
    while (fread(tmp, sizeof(room_t), 1, fd) > 0) {
        tmp->next = room;
        room = tmp;
    }
    printf("------------------------\n");
    show_liste(room);
}

void save_dongeons(room_t *room)
{
    FILE *fd;

    remove("dng.sv");
    fd = fopen("dng.sv", "a");
    while (room != NULL) {
        fwrite(room, sizeof(room_t), 1, fd);
        room = room->next;
    }
}
