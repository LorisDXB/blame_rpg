/*
** EPITECH PROJECT, 2024
** tablen
** File description:
** tablen
*/

#include "mylib.h"
#include <stdlib.h>

int tablen(char **array)
{
    int length = 0;

    for (int i = 0; array[i] != NULL; i++)
        length = i;
    return length;
}
