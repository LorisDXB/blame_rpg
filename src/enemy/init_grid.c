/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** init_grid.c
*/

#include "rpg.h"

static int **init_dist(int *start)
{
    int **dist = malloc(sizeof(int *) * S_GRID);

    for (int i = 0; i < S_GRID; i++) {
        dist[i] = malloc(sizeof(int) * S_GRID);
        for (int j = 0; j < S_GRID; j++)
            dist[i][j] = INT_MAX;
    }
    dist[start[0]][start[1]] = 0;
    return dist;
}

static bool **init_explored(void)
{
    bool **explored = malloc(sizeof(bool *) * S_GRID);

    for (int i = 0; i < S_GRID; i++) {
        explored[i] = malloc(sizeof(bool) * S_GRID);
        for (int j = 0; j < S_GRID; j++)
            explored[i][j] = false;
    }
    return explored;
}

static int **init_parent(void)
{
    int **parent = malloc(sizeof(int *) * S_GRID);

    for (int i = 0; i < S_GRID; i++) {
        parent[i] = malloc(sizeof(int) * S_GRID);
        for (int j = 0; j < S_GRID; j++)
            parent[i][j] = -1;
    }
    return parent;
}

grid_t *init_grid(int *start)
{
    grid_t *grid = malloc(sizeof(grid_t));

    grid->dist = init_dist(start);
    grid->explored = init_explored();
    grid->parent = init_parent();
    return grid;
}
