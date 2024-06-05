/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** tools_dongeons
*/

#include "rpg.h"

char *recup_colision_map(room_t *room)
{
    int len = (strlen(room->path) - 4) + 14;
    char *path = malloc(sizeof(char) * (len));
    int j = 0;
    char *add = strdup("_colision.txt");

    for (int i = 0; i != strlen(room->path) - 4; i++)
        path[i] = room->path[i];
    for (int i = strlen(room->path) - 4; i != strlen(add) + strlen(room->path)
        - 4; i++) {
        path[i] = add[j];
        j++;
    }
    path[(strlen(room->path) - 4) + (strlen(add))] = '\0';
    free(add);
    return path;
}

int **if_matrice(int *i, int *repate, int **matrice)
{
    *i = 0;
    *repate = 0;
    return matrice;
}

int verif_door(int **matrice, int nbr, int used)
{
    int count = 0;

    for (int x = 0; x != nbr; x++) {
        if (matrice[used][x] == 1) {
            count++;
        }
    }
    if (count == 4)
        return 1;
    return 0;
}

void show_liste(room_t *room)
{
    while (room != NULL) {
        printf("\nroom id = %d\n", room->index);
        printf("name = %s\n", room->name);
        printf("path = %s\n------\n", room->path);
        printf("door 1: %d\ndoor 2: %d\ndoor 3: %d\ndoor 4: %d\n",
        room->door_1, room->door_2, room->door_3, room->door_4);
        room = room->next;
    }
}

void free_liste(room_t *room)
{
    room_t *tmp = room;

    while (room != NULL) {
        tmp = room;
        free(tmp->name);
        free(tmp->path);
        free_enemies(tmp->enemies);
        room = room->next;
        free(tmp);
    }
}
