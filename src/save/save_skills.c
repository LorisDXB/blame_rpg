/*
** EPITECH PROJECT, 2024
** save inventory
** File description:
** save for rpg
*/

#include "../../include/rpg.h"

static char *fill_skdata(skills_t *sk, int total_length)
{
    char *invdata = malloc(sizeof(char) * (total_length + 1));
    char buffer[30];

    invdata[0] = '\0';
    sprintf(buffer, "%d;", sk->str);
    strcat(invdata, buffer);
    sprintf(buffer, "%d;", sk->fort);
    strcat(invdata, buffer);
    sprintf(buffer, "%d;", sk->agi);
    strcat(invdata, buffer);
    sprintf(buffer, "%d;", sk->cha);
    strcat(invdata, buffer);
    sprintf(buffer, "%d;", sk->lvl);
    strcat(invdata, buffer);
    sprintf(buffer, "%d;", sk->xp);
    strcat(invdata, buffer);
    sprintf(buffer, "%d;", sk->pts);
    strcat(invdata, buffer);
    return invdata;
}

static char *get_sk_data(skills_t *skills)
{
    char *invdata = NULL;
    int total_length = 0;

    total_length += snprintf(NULL, 0, "%d;", skills->str);
    total_length += snprintf(NULL, 0, "%d;", skills->fort);
    total_length += snprintf(NULL, 0, "%d;", skills->agi);
    total_length += snprintf(NULL, 0, "%d;", skills->cha);
    total_length += snprintf(NULL, 0, "%d;", skills->lvl);
    total_length += snprintf(NULL, 0, "%d;", skills->xp);
    total_length += snprintf(NULL, 0, "%d;", skills->pts);
    invdata = fill_skdata(skills, total_length);
    return invdata;
}

void save_skills(repo_t *repo)
{
    FILE *file = fopen(SK_SVFILE, "w");
    char *str = get_sk_data(repo->player->skills);

    if (str == NULL) {
        fclose(file);
    } else {
        fwrite(str, 1, strlen(str), file);
        fclose(file);
    }
    free(str);
}
