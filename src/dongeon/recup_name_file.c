/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** recup_name_file
*/

#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int verif_file(char *name, char *end)
{
    int len = strlen(name);
    int j = 0;

    if (len < strlen(end)) {
        return 1;
    }
    for (int i = (len - strlen(end)); name[i] != '\0'; i++) {
        if (end[j] != name[i])
            return 1;
        j++;
    }
    return 0;
}

static int nbr_file(char *direct, char *end)
{
    DIR *d;
    struct dirent *dir;
    int count = 0;

    d = opendir(direct);
    if (!d)
        return 0;
    dir = readdir(d);
    while (dir != NULL) {
        if (dir->d_type == DT_REG && verif_file(dir->d_name, end) == 0)
            count++;
        dir = readdir(d);
    }
    closedir(d);
    return count;
}

static char *my_strcat_2(char *str, char *cmp)
{
    int len = strlen(str) + strlen(cmp);
    char *new = malloc(sizeof(char) * (len + 1));
    int t = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        new[t] = str[i];
        t++;
    }
    for (int i = 0; cmp[i] != '\0'; i++) {
        new[t] = cmp[i];
        t++;
    }
    new[t] = '\0';
    return new;
}

static char **feed_array_file(char **array, char *direct, char *end)
{
    DIR *d;
    struct dirent *dir;
    int i = 0;

    d = opendir(direct);
    if (!d) {
        return 0;
    }
    dir = readdir(d);
    while (dir != NULL) {
        if (dir->d_type == DT_REG && verif_file(dir->d_name, end) == 0) {
            array[i] = strdup(my_strcat_2(direct, dir->d_name));
            i++;
        }
        dir = readdir(d);
    }
    closedir(d);
    return array;
}

char **recup_file_name(char *dir, char *end)
{
    int len = nbr_file(dir, end);
    char **array = malloc(sizeof(char *) * (len + 1));

    array = feed_array_file(array, dir, end);
    array[len] = NULL;
    return array;
}
