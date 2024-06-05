/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** room_selection
*/

#include "rpg.h"

static void free_array_room(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}

static char *room_1door(void)
{
    char **door = recup_file_name("./assets/maps/1door/", ".png");
    int len = tablen(door);
    char *choose = strdup(door[rand() % len + 1]);

    free_array_room(door);
    return choose;
}

static char *room_2door(void)
{
    char **door = recup_file_name("./assets/maps/2door/", ".png");
    int len = tablen(door);
    char *choose = strdup(door[rand() % len + 1]);

    free_array_room(door);
    return choose;
}

static char *room_3door(void)
{
    char **door = recup_file_name("./assets/maps/3door/", ".png");
    int len = tablen(door);
    char *choose = strdup(door[rand() % len + 1]);

    free_array_room(door);
    return choose;
}

static char *room_4door(void)
{
    char **door = recup_file_name("./assets/maps/4door/", ".png");
    int len = tablen(door);
    char *choose = strdup(door[rand() % len + 1]);

    free_array_room(door);
    return choose;
}

char *choose_room(int nbr_door)
{
    if (nbr_door == 1)
        return room_1door();
    if (nbr_door == 2)
        return room_2door();
    if (nbr_door == 3)
        return room_3door();
    if (nbr_door == 4)
        return room_4door();
}
