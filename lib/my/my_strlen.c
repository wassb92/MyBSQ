/*
** EPITECH PROJECT, 2021
** bsq
** File description:
** strlen
*/

#include <stdlib.h>

int my_strlen(char *str)
{
    int i = 0;

    if (str == NULL)
        return i;

    for (; str[i] != '\0'; ++i);

    return i;
}

int tablen(char **map)
{
    int i = 0;

    if (map == NULL)
        return i;

    for (i = 0; map[i] != NULL; ++i);

    return i;
}