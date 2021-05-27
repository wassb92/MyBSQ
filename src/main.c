/*
** EPITECH PROJECT, 2021
** BSQ
** File description:
** main
*/

#include "bsq.h"
#include <stdlib.h>
#include <unistd.h>

void my_free_array(char **map, int **tab, int i)
{
    free(map[i]);
    free(tab[i]);
}

void my_free(char **map, int **tab)
{
    free(map[0]);
    free(tab);
    free(map);
}

static int error_handling(int ac, char **av)
{
    if (ac != 2) {
        write(1, "Miss an argument\n", 17);
        return error;
    }
    return good;
}

int main(int ac, char **av)
{
    char **map = NULL;
    bsq_t data_bsq;
    data_bsq.biggest = 0;
    data_bsq.x = 0;
    data_bsq.y = 0;

    if (error_handling(ac, av) == error)
        return exit_error;
    map = open_map(av[1]);
    if (map == NULL)
        return 84;
    if (map_is_not_a_square(map) == 1)
        return good;
    bsq(map, &data_bsq);
    return good;
}