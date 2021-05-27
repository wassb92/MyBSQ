/*
** EPITECH PROJECT, 2021
** bsq
** File description:
** str to array
*/

#include "bsq.h"
#include <stdlib.h>

int my_strlen(char *str);

char **str_to_array(char *str, char c)
{
    char **array = NULL;
    int args = 1;
    int d;
    int a = 0;

    for (int i = 0; str[i] != '\0'; ++i)
        str[i] == c ? ++args : 0;
    array = malloc(sizeof(char *) * (args + mal));
    if (array == NULL || args == 1)
        return NULL;
    for (int b = 0; b < args; ++b, ++a) {
        array[b] = malloc(sizeof(char) * (my_strlen(str) + mal));
        for (d = 0; str[a] != c && str[a] != '\0'; ++d, ++a)
            array[b][d] = str[a];
        array[b][d] = '\0';
    }
    array[args] = NULL;
    return array;
}