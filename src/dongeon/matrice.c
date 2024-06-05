/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** matrice
*/

#include "rpg.h"

int **create_matrice(int lenght)
{
    int **matrice = malloc(sizeof(int *) * (lenght));

    for (int i = 0; i < lenght; i++) {
        matrice[i] = malloc(sizeof(int) * lenght);
    }
    for (int i = 0; i < lenght; i++) {
        for (int j = 0; j < lenght; j++) {
            matrice[i][j] = 0;
        }
    }
    return matrice;
}

void show_matrice(int **matrice, int lenght)
{
    for (int i = 0; i < lenght; i++) {
        for (int j = 0; j < lenght; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
}

int **add_link(int **matrice, int posA, int posB)
{
    matrice[posA][posB] = 1;
    matrice[posB][posA] = 1;
    return matrice;
}

void free_matrice(int **matrice, int nbr)
{
    for (int i = 0; i != nbr; i++) {
        free(matrice[i]);
    }
    free(matrice);
}
