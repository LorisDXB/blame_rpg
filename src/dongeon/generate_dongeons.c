/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** generate_dongeons
*/

#include "rpg.h"

static int count_i(int *i)
{
    int count = 0;

    while (i[count] != -1) {
        count++;
    }
    return count;
}

static int *add_used(int *used, int k)
{
    int len = count_i(used) + 1;
    int *i = malloc(sizeof(int) * (len + 1));
    int j = 0;

    while (j != (len - 1)) {
        i[j] = used[j];
        j++;
    }
    i[j] = k;
    i[j + 1] = -1;
    free(used);
    return i;
}

static int *remov_not_used(int *not_used, int k)
{
    int nbr = count_i(not_used);
    int *i = malloc(sizeof(int) * (nbr));
    int j = 0;
    int l = 0;

    while (j != nbr) {
        if (not_used[j] != k) {
            i[l] = not_used[j];
            l++;
        }
        j++;
    }
    i[l] = -1;
    free(not_used);
    return i;
}

static int *set_not_used(int nbr_piece)
{
    int *i = malloc(sizeof(int) * (nbr_piece));
    int index = 0;
    int j = 1;

    while (index != nbr_piece) {
        if (j != nbr_piece) {
            i[index] = j;
            j++;
        }
        index++;
    }
    i[nbr_piece - 1] = -1;
    return i;
}

static int count_remove_used(int **matrice, int nbr_piece, int *used)
{
    int count = 0;
    int i = 0;

    for (int y = 0; used[y] != -1; y++) {
        for (int x = 0; x != nbr_piece; x++) {
            count += (matrice[used[y]][x] == 1) ? 1 : 0;
        }
        if (count == 4)
            i++;
        count = 0;
    }
    return i;
}

int *remove_used_four_door(int *used, int **m, int nbr)
{
    int len = count_i(used);
    int remove = count_remove_used(m, nbr, used);
    int *new = malloc(sizeof(int) * (len - remove + 1));
    int i = 0;
    int j = 0;

    while (used[i] != -1) {
        if (verif_door(m, nbr, used[i]) == 0 && j < (len - remove + 1)) {
            new[j] = used[i];
            j++;
        }
        i++;
    }
    if (j == (len - remove + 1))
        new[(len - remove)] = -1;
    else
        new[j] = -1;
    free(used);
    return new;
}

int **path_create(int **used, int **not_used, int **matrice, int a)
{
    static int repate = 0;
    static int i = 0;
    int b;

    if (repate == 0)
        repate = (rand() % (5 - 3 + 1)) + 3;
    if (i == repate)
        return if_matrice(&i, &repate, matrice);
    if (count_i(*not_used) == 0)
        return if_matrice(&i, &repate, matrice);
    b = not_used[0][(rand() % (count_i(*not_used)))];
    matrice = add_link(matrice, a, b);
    *not_used = remov_not_used(*not_used, b);
    if (i != repate)
        *used = add_used(*used, b);
    i++;
    return path_create(used, not_used, matrice, b);
}

int **add_path(int **matrice, int *used, int nbr_piece)
{
    int a;
    int b;
    int i = 0;

    while (i != (nbr_piece / 5)) {
        used = remove_used_four_door(used, matrice, nbr_piece);
        a = used[(rand() % (count_i(used) - 1))];
        b = used[(rand() % (count_i(used) - 1))];
        while (a == b)
            b = used[(rand() % (count_i(used) - 1))];
        matrice = add_link(matrice, a, b);
        i++;
    }
    free(used);
    return matrice;
}

int **generate_matrice_adjacente(int nbr_piece)
{
    int **matrice = create_matrice(nbr_piece);
    int *used = malloc(sizeof(int) * (1));
    int *not_used = set_not_used(nbr_piece);
    int spawn = 0;

    used[0] = -1;
    matrice = path_create(&used, &not_used, matrice, spawn);
    while (count_i(not_used) != 0) {
        used = remove_used_four_door(used, matrice, nbr_piece);
        spawn = used[rand() % ((count_i(used) - 1) + 1)];
        matrice = path_create(&used, &not_used, matrice, spawn);
    }
    matrice = add_path(matrice, used, nbr_piece);
    free(not_used);
    return matrice;
}
