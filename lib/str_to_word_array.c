/*
** EPITECH PROJECT, 2024
** str_to_word_array.c
** File description:
** strtowordarray
*/

#include "mylib.h"

static int delim(char c, char *delims)
{
    for (int i = 0; delims[i] != '\0'; i++) {
        if (c == delims[i] || c == '\0')
            return 1;
    }
    return 0;
}

static int word_count(const char *str, char *delims)
{
    int c = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (delim(str[i], delims) == 0 && delim(str[i + 1], delims) == 1)
            c++;
    }
    return c;
}

static int my_strlen_b(const char *str, char *delims)
{
    int s = 0;

    for (int i = 0; delim(str[i], delims) != 1; i++) {
        s++;
    }
    return s;
}

static char *my_strdup_arr(const char *str, char *delims)
{
    char *ret = malloc(sizeof(char) * (my_strlen_b(str, delims) + 1));
    int i = 0;

    ret[0] = '\0';
    for (i; delim(str[i], delims) != 1; i++) {
        ret[i] = str[i];
    }
    ret[i] = '\0';
    return ret;
}

char **str_to_array(char *str, char *delims)
{
    char **tab = malloc(sizeof(char *) * (word_count(str, delims) + 1));
    int og = 0;
    int i = 0;

    if (word_count(str, delims) == 1) {
        tab[0] = my_strdup(str);
        tab[1] = NULL;
        return tab;
    }
    while (str[i] != '\0') {
        if (delim(str[i], delims) == 0) {
            tab[og] = my_strdup_arr(&str[i], delims);
            i += my_strlen_b(&str[i], delims) - 1;
            og++;
        }
        i++;
    }
    tab[og] = NULL;
    return tab;
}
