/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** recup_door_pos
*/

#include "rpg.h"

char *file_to_buff(char *path)
{
    FILE *fd;
    struct stat sb;
    char *buff;

    fd = fopen(path, "r+");
    lstat(path, &sb);
    buff = malloc(sizeof(char) * (sb.st_size + 1));
    fread(buff, sizeof(*buff), sb.st_size, fd);
    buff[sb.st_size] = '\0';
    fclose(fd);
    return buff;
}

void whats_door(room_t *room, int door, int x, int y)
{
    if (door == 1) {
        room->pos1.x = x;
        room->pos1.y = y;
    }
    if (door == 2) {
        room->pos2.x = x;
        room->pos2.y = y;
    }
    if (door == 3) {
        room->pos3.x = x;
        room->pos3.y = y;
    }
    if (door == 4) {
        room->pos4.x = x;
        room->pos4.y = y;
    }
}

room_t *recup_door_pos(room_t *room)
{
    char *buff = file_to_buff(room->colision);
    int y = 0;
    int x = 0;
    int door = 0;

    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == '\n') {
            y++;
            x = 0;
        }
        if (buff[i] == 'D') {
            door++;
            whats_door(room, door, x - 1, y);
        }
        x++;
    }
    return room;
}
