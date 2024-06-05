/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** room_to_other
*/

#include "rpg.h"

int recup_door_id(room_t *room, int door)
{
    if (door == 1)
        return room->door_1;
    if (door == 2)
        return room->door_2;
    if (door == 3)
        return room->door_3;
    if (door == 4)
        return room->door_4;
    return -1;
}

room_t *room_to_room(room_t *first, int door, room_t **laby)
{
    int index_room = recup_door_id(first, door);
    room_t *tmp = *laby;

    while (tmp != NULL) {
        if (tmp->index == index_room)
            return tmp;
        tmp = tmp->next;
    }
}
