/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** matrice_to_liste
*/

#include "../../include/rpg.h"

/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** matrice_to_liste
*/

#include "rpg.h"

static room_t *set_room(room_t *room, int nbr_room, int *line)
{
    int door = 0;

    room->door_1 = -1;
    room->door_2 = -1;
    room->door_3 = -1;
    room->door_4 = -1;
    for (int x = 0; x != nbr_room; x++) {
        if (line[x] == 1)
            door++;
        room->door_1 = (door == 1 && room->door_1 == -1) ? x : room->door_1;
        room->door_2 = (door == 2 && room->door_2 == -1) ? x : room->door_2;
        room->door_3 = (door == 3 && room->door_3 == -1) ? x : room->door_3;
        room->door_4 = (door == 4 && room->door_4 == -1) ? x : room->door_4;
    }
    room->nbr_door = door;
    return room;
}

static char *name_aleatoir(void)
{
    char nbr[] = {'0', '1', '2', '3', '4', '5',
    '6', '7', '8', '9'};
    char alpha[] = {'A', 'B', 'C', 'D', 'E', 'F',
    'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
    'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char lettre = alpha[(rand() % 26)];
    char *name = malloc(sizeof(char) * (5));

    name[0] = lettre;
    for (int i = 1; i != 5; i++) {
        name[i] = nbr[(rand() % 10)];
    }
    name[4] = '\0';
    return strdup(name);
}

void add_png(room_t *room, repo_t *repo)
{
    char *buff = file_to_buff(room->colision);

    room->name = name_aleatoir();
    room = recup_door_pos(room);
    room->is_png = 0;
    for (int i = 0; buff[i] != '\0'; i++)
        if (buff[i] == 'N')
            room->is_png = 1;
    if (room->is_png == 1)
        room->png = init_png(room->colision, repo);
}

void add_room(int *line, room_t **begin, int *j, repo_t *repo)
{
    room_t *room = malloc(sizeof(room_t) * (1));
    int nbr_room = j[1];
    int i = j[0];
    int door = 0;

    for (int x = 0; x != nbr_room; x++)
        if (line[x] == 1)
            door++;
    room->index = i;
    room = set_room(room, nbr_room, line);
    if (i == 0) {
        room->path = strdup("./assets/maps/spawn/spawn.png");
        room->colision = strdup("./assets/maps/spawn/colision.txt");
    } else {
        room->path = choose_room(door);
        room->colision = recup_colision_map(room);
    }
    room->next = *begin;
    add_png(room, repo);
    *begin = room;
}

room_t *go_to_room(room_t **room, int id)
{
    room_t *tmp = *room;

    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->index == id)
            return tmp;
    }
    return *room;
}

room_t *matrice_to_liste(int **matrice, int nbr_piece, repo_t *repo)
{
    room_t *room = NULL;
    int *j = malloc(sizeof(int) * 2);
    int i = 0;

    while (i != nbr_piece) {
        j[0] = i;
        j[1] = nbr_piece;
        add_room(matrice[i], &room, j, repo);
        i++;
    }
    return room;
}
