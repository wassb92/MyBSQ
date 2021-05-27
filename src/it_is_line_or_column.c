/*
** EPITECH PROJECT, 2021
** bsq
** File description:
** if map isn't a square
*/

#include "my.h"

static void one_line(char **map)
{
    int count = 0;

    for (int i = 1; map[i] != NULL; ++i) {
        for (int t = 0; map[i][t] != '\0'; ++t)
            if (map[i][t] == '.' && count == 0) {
                map[i][t] = 'x';
                ++count;
            }
        write(1, map[i], my_strlen(map[i]));
        free(map[i]);
    }
    write(1, "\n", 1);
    free(map[0]);
    free(map);
}

static void one_column(char **map)
{
    int count = 0;

    for (int i = 1; map[i] != NULL; ++i) {
        if (map[i][0] == '.' && count == 0) {
            map[i][0] = 'x';
            ++count;
        }
        write(1, map[i], my_strlen(map[i]));
        free(map[i]);
        write(1, "\n", 1);
    }
    free(map[0]);
    free(map);
}

int map_is_not_a_square(char **map)
{
    if (map[2] == NULL) {
        one_line(map);
        return 1;
    }
    if (map[1][1] == 0) {
        one_column(map);
        return 1;
    }
    return 0;
}