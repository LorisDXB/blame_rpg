/*
** EPITECH PROJECT, 2024
** main for rpg
** File description:
** main for rpg
*/

#include "../include/rpg.h"

int main(int argc, char *argv[])
{
    repo_t *repo;

    if (robustness(argc, argv) == 84)
        return 84;
    srand(time(NULL));
    repo = init_repo();
    if (argc == 2 && strcmp(argv[1], "-h") == 0) {
        print_help();
        return 0;
    }
    main_menu(repo);
    destroy_game(repo);
    return 0;
}
