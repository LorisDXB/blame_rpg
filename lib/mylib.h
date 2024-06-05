/*
** EPITECH PROJECT, 2023
** mylib.h
** File description:
** mylib.h
*/

#ifndef MYLIB
    #define MYLIB
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <string.h>

int my_atoi(char *str);
void my_putchar(char c);
int my_putstr(char const *str, int counter);
void my_strcat(char *dest, const char *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
unsigned long my_strlen(char const *str);
int my_strncmp(char const *s1, char const *s2);
char **my_tabcpy(char ***tab2, int tablen);
char *my_strdup(char const *src);
int tablen(char **array);
char *my_getnbr(int number);
char **str_to_array(char *str, char *delims);

#endif
