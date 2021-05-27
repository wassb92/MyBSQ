/*
** EPITECH PROJECT, 2021
** bsq
** File description:
** bsq
*/

#ifndef BSQ_H_
# define BSQ_H_

typedef struct bsq_s {
    int x;
    int y;
    int biggest;
}bsq_t;

/* Const values */

static const int mal = 1;
static const int error = -1;
static const int good = 0;
static const int exit_error = 84;


/* Prototypes */

char **open_map(char const *filepath);
void bsq(char **map, bsq_t *bsq);
int map_is_not_a_square(char **map);


/* Utils */

void my_free_array(char **map, int **tab, int i);
void my_free(char **map, int **tab);


#endif /* !BSQ_H_ */