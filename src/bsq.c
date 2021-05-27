/*
** EPITECH PROJECT, 2021
** bsq
** File description:
** bsq
*/

#include "my.h"
#include "bsq.h"

static int deminer(int left, int top, int topleft)
{
    if (left <= top && left <= topleft)
        return left;
    if (top <= left && top <= topleft)
        return top;
    if (topleft <= top && topleft <= left)
        return topleft;
}

static int **convert_char_to_int(char **map)
{
    int **tab = malloc(sizeof(int *) * tablen(map) + mal);

    for (int i = 1; map[i] != NULL; ++i) {
        tab[i] = malloc(sizeof(int) * my_strlen(map[i]) + mal);
        for (int t = 0; map[i][t] != '\0'; ++t) {
            map[i][t] == '.' ? tab[i][t] = 1 : 0;
            map[i][t] == 'o' ? tab[i][t] = 0 : 0;
        }
    }
    return tab;
}

static int **find_biggest_square(char **map, int **tab, bsq_t *bsq)
{
    int dem = 0;

    for (int i = 2; map[i] != NULL; ++i) {
        for (int t = 1; map[i][t] != '\0'; ++t) {
            dem = deminer(tab[i][t - 1], tab[i - 1][t], tab[i - 1][t - 1]);
            tab[i][t] == 0 ? dem = 0 : 0;
            tab[i][t] += dem;
            if (tab[i][t] > bsq->biggest) {
                bsq->biggest = tab[i][t];
                bsq->y = i;
                bsq->x = t;
            }
        }
    }
    return tab;
}

static void draw_biggest_square(char **map, bsq_t *bsq, int i, int t)
{
    if (i > bsq->y - bsq->biggest && i <= bsq->y 
        && t > bsq->x - bsq->biggest && t <= bsq->x)
        map[i][t] = 'x';
}

void bsq(char **map, bsq_t *bsq)
{
    int **tab = find_biggest_square(map, convert_char_to_int(map), bsq);

    for (int i = 1; map[i] != NULL; ++i) {
        for (int t = 0; map[i][t] != '\0'; ++t)
            draw_biggest_square(map, bsq, i, t);
        write(1, map[i], my_strlen(map[i]));
        write(1, "\n", 1);
        my_free_array(map, tab, i);
    }
    my_free(map, tab);
}