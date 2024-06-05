/*
** EPITECH PROJECT, 2024
** get_inv_content.c
** File description:
** get_inv_content
*/

#include "../../include/rpg.h"
#include "../../lib/mylib.h"

static char *get_inv(void)
{
    int fd = open("loadables/inv.csv", O_CREAT, 0600);
    struct stat st;
    char *buff = NULL;

    stat("loadables/inv.csv", &st);
    if (st.st_size == 0) {
        perror("inv.csv is empty");
        return NULL;
    }
    buff = malloc(sizeof(char) * (st.st_size));
    read(fd, buff, st.st_size);
    buff[st.st_size - 1] = '\0';
    close(fd);
    return buff;
}

static void add_inv_node(weapon_t **head, char *dicti, repo_t *repo)
{
    weapon_t *tmp = *head;

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = wep_selector(atoi(dicti), &(repo->db->wep));
    tmp->next->next = NULL;
}

weapon_t *fetch_inventory(repo_t *repo)
{
    char *buffer = get_inv();
    char **dict = NULL;
    weapon_t *ret = NULL;

    if (buffer == NULL) {
        return NULL;
    }
    dict = str_to_array(buffer, ";");
    ret = wep_selector(atoi(dict[0]), &(repo->db->wep));
    ret->next = NULL;
    for (int i = 1; dict[i] != NULL; i++) {
        add_inv_node(&(ret), dict[i], repo);
    }
    return ret;
}
