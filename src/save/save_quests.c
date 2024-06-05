/*
** EPITECH PROJECT, 2024
** save_quests
** File description:
** save_quests
*/

#include "../../include/rpg.h"

static char *fill_questdata(quest_t **quest, int total_length)
{
    char *questdata = malloc(sizeof(char) * (total_length + 1));
    char buffer[30];

    questdata[0] = '\0';
    for (int i = 0; quest[i] != NULL; i++) {
        sprintf(buffer, "%s;%d;%d\n", quest[i]->goal, quest[i]->xp_rew,
            quest[i]->status);
        strcat(questdata, buffer);
    }
    return questdata;
}

static char *get_quest_data(quest_t **quest)
{
    char *questdata = NULL;
    int total_length = 0;

    if (quest == NULL)
        return NULL;
    for (int i = 0; quest[i] != NULL; i++) {
        total_length += snprintf(NULL, 0, "%s;%d;%d\n", quest[i]->goal,
            quest[i]->xp_rew, quest[i]->status);
    }
    questdata = fill_questdata(quest, total_length);
    return questdata;
}

void save_quests(repo_t *repo)
{
    FILE *file = fopen(QU_SVFILE, "w");
    char *str = get_quest_data(repo->db->quest);

    if (str == NULL) {
        fclose(file);
    } else {
        fwrite(str, 1, strlen(str), file);
        fclose(file);
    }
    free(str);
}
