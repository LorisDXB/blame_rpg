/*
** EPITECH PROJECT, 2024
** robustness for rpg
** File description:
** robustness
*/

#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include "../include/rpg.h"

static int isnotnumber(char c)
{
    if (c < '0' || c > '9') {
        return 1;
    }
    return 0;
}

static char *read_file(char *path)
{
    int fd = open(path, O_RDONLY);
    struct stat sb;
    char *buffer = NULL;

    stat(path, &sb);
    buffer = malloc(sizeof(char) * (sb.st_size + 1));
    read(fd, buffer, sb.st_size);
    buffer[sb.st_size] = '\0';
    return buffer;
}

int file_robustness(char *path)
{
    char *fc = read_file(path);

    for (int i = 0; fc[i] != '\0'; i++) {
        if (fc[i] != ';' && fc[i] != '\n' && isnotnumber(fc[i]) == 1) {
            printf("FATAL ERROR: format error detected.\n");
            printf("%s: Got '%c' at column '%d'\n", path, fc[i], i);
            return 1;
        }
    }
    return 0;
}

void print_help(void)
{
    printf("// BLAME! \\\n");
    printf("// PLAY AND GET GOOD \\\n");
}

int check_files(void)
{
    char *dep[] = {"dictionary", "font", "include",
        "lib", "loadables", "src", "assets",
        "assets/maps", "assets/sprites", "assets/fonts"};
    DIR *dir;
    int depsize = sizeof(dep) / sizeof(dep[0]);

    for (int i = 0; i < depsize; i++) {
        dir = opendir(dep[i]);
        if (dir == NULL) {
            printf("FATAL ERROR: dependency <%s> missing.\n", dep[i]);
            return ENOENT;
        }
        closedir(dir);
    }
    if (file_robustness("loadables/inv.csv") == 1 ||
        file_robustness("loadables/sk.csv") == 1) {
        return ENOENT;
    }
    return 0;
}

int robustness(int argc, char **argv)
{
    if (argc > 2)
        return 84;
    if (check_files() == ENOENT)
        return 84;
    return 0;
}
