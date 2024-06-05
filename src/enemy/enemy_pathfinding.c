/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** enemy_pathfinding.c
*/

#include "rpg.h"

static void free_grid(grid_t *grid)
{
    for (int i = 0; i < S_GRID; i++) {
        free(grid->dist[i]);
        free(grid->parent[i]);
        free(grid->explored[i]);
    }
    free(grid->dist);
    free(grid->parent);
    free(grid->explored);
    free(grid);
}

static int *sub_closest(grid_t *grid, int i, int *min, int *min_index)
{
    for (int j = 0; j < S_GRID; j++) {
        if (grid->explored[i][j] == false && grid->dist[i][j] <= *min) {
            *min = grid->dist[i][j];
            min_index[0] = i;
            min_index[1] = j;
        }
    }
    return min_index;
}

static int *closest(grid_t *grid)
{
    int min = INT_MAX;
    int *min_index = malloc(sizeof(int) * 2);

    for (int i = 0; i < S_GRID; i++) {
        min_index = sub_closest(grid, i, &min, min_index);
    }
    return min_index;
}

static void print_path(int **parent, int x, int y)
{
    if (parent[x][y] == -1) {
        printf("(%d, %d) ", x, y);
        return;
    }
    print_path(parent, parent[x][y] / S_GRID, parent[x][y] % S_GRID);
    printf("(%d, %d) ", x, y);
}

static void print_solution(int **dist, int **parent, int *start, int *end)
{
    printf("Path from (%d, %d) to (%d, %d):\n", start[0], start[1],
        end[0], end[1]);
    printf("Distance: %d\n", dist[end[0]][end[1]]);
    printf("Path: ");
    print_path(parent, end[0], end[1]);
    printf("\n");
}

static int *find_next_move(int *next_move, int **parent, int x, int y)
{
    if (parent[x][y] == -1)
        return next_move;
    next_move[0] = x;
    next_move[1] = y;
    find_next_move(next_move, parent, parent[x][y] / S_GRID,
        parent[x][y] % S_GRID);
}

static void sub_find_path(grid_t *grid, char **collisions,
    int *u, int dx)
{
    int nx;
    int ny;

    for (int dy = -1; dy <= 1; dy++) {
        nx = u[0] + dx;
        ny = u[1] + dy;
        if (nx >= 0 && nx < S_GRID && ny >= 0 && ny < S_GRID &&
            !grid->explored[nx][ny] && collisions[nx][ny] == 'O' &&
            grid->dist[u[0]][u[1]] != INT_MAX && grid->dist[u[0]][u[1]]
            + 1 < grid->dist[nx][ny]) {
            grid->parent[nx][ny] = u[0] * S_GRID + u[1];
            grid->dist[nx][ny] = grid->dist[u[0]][u[1]] + 1;
        }
    }
}

int *find_path(char **collisions, int *start, int *end)
{
    grid_t *grid = init_grid(start);
    int *u;
    int *next_move = malloc(sizeof(int) * 2);

    for (int count = 0; count < S_GRID * S_GRID - 1; count++) {
        u = closest(grid);
        grid->explored[u[0]][u[1]] = true;
        if (u[0] == end[0] && u[1] == end[1])
            break;
        for (int dx = -1; dx <= 1; dx++)
            sub_find_path(grid, collisions, u, dx);
    }
    next_move = find_next_move(next_move, grid->parent, end[0], end[1]);
    free_grid(grid);
    return next_move;
}
