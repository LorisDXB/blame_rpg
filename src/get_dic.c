/*
** EPITECH PROJECT, 2024
** get dictionary
** File description:
** for rpg
*/

#include "../include/rpg.h"
#include "../lib/mylib.h"

static char *get_wep_dict(void)
{
    int fd = open("dictionary/wep.list", O_RDONLY);
    struct stat st;
    char *buff = NULL;

    stat("dictionary/wep.list", &st);
    if (st.st_size == 0) {
        perror("wep.list is empty");
        return NULL;
    }
    buff = malloc(sizeof(char) * (st.st_size));
    read(fd, buff, st.st_size);
    buff[st.st_size - 1] = '\0';
    close(fd);
    return buff;
}

static char *get_qu_dict(void)
{
    int fd = open("dictionary/quests.list", O_RDONLY);
    struct stat st;
    char *buff = NULL;

    stat("dictionary/quests.list", &st);
    if (st.st_size == 0) {
        perror("quests.list is empty");
        return NULL;
    }
    buff = malloc(sizeof(char) * (st.st_size));
    read(fd, buff, st.st_size);
    buff[st.st_size - 1] = '\0';
    close(fd);
    return buff;
}

void fetch_weps(weapon_t *wep)
{
    char *buffer = get_wep_dict();
    char **dict = str_to_array(buffer, "\n");

    for (int i = 0; dict[i] != NULL; i++) {
        add_node(&wep, dict[i], i + 1);
    }
}

static char *get_skills_dict(void)
{
    int fd = open("loadables/sk.csv", O_RDONLY | O_CREAT, 0600);
    struct stat st;
    char *buff = NULL;

    stat("loadables/sk.csv", &st);
    if (st.st_size == 0) {
        perror("sk.csv is empty");
        return NULL;
    }
    buff = malloc(sizeof(char) * (st.st_size));
    read(fd, buff, st.st_size);
    buff[st.st_size - 1] = '\0';
    close(fd);
    return buff;
}

static char **empty_dict(void)
{
    char **ret = malloc(sizeof(char *) * 8);
    int i = 0;

    for (i = 0; i < 7; i++) {
        ret[i] = strdup("0");
    }
    ret[i] = NULL;
    return ret;
}

void fetch_skills(skills_t *sk)
{
    char *buffer = get_skills_dict();
    char **dict = NULL;

    if (buffer == NULL) {
        dict = empty_dict();
    } else {
        dict = str_to_array(buffer, ";");
    }
    sk->str = atoi(dict[0]);
    sk->fort = atoi(dict[1]);
    sk->agi = atoi(dict[2]);
    sk->cha = atoi(dict[3]);
    sk->lvl = atoi(dict[4]);
    sk->xp = atoi(dict[5]);
    sk->pts = atoi(dict[6]);
}

quest_t **fetch_quests(sfFont *font)
{
    char *buffer = get_qu_dict();
    char **dict = str_to_array(buffer, "\n");
    char **tmp = NULL;
    int len = tablen(dict) + 1;
    quest_t **ret = malloc(sizeof(quest_t *) * (len + 1));
    int i = 0;

    for (i = 0; i < len; i++) {
        tmp = str_to_array(dict[i], ";");
        ret[i] = init_quests(tmp, font, i + 1);
    }
    ret[i] = NULL;
    return ret;
}
