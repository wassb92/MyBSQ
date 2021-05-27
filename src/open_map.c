/*
** EPITECH PROJECT, 2021
** bsq
** File description:
** open and read map
*/

#include "bsq.h"
#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static void my_free_map(char **map)
{
    for (int i = 0; map[i] != NULL; ++i)
        free(map[i]);
    free(map);
}

static void get_clean_tab(char **map)
{
    for (int i = 0; map[i] != NULL; ++i)
        if (map[i][0] == '\0') {
            free(map[i]);
            map[i] = NULL;
        }
}

static int is_bad_map(char **map)
{
    for (int i = 1; map[i] != NULL; ++i) {
        for (int t = 0; map[i][t] != '\0'; ++t)
            if (map[i][t] != '.'  && map[i][t] != 'o' &&
                map[i][t] != '\n' && map[i][t] != '\0') {
            my_free_map(map);
            return error;
        }
    }
    if (atoi(map[0]) != tablen(map) - 2) {
        my_free_map(map);
        return error;
    }
    return 0;
}

char **open_map(char const *filepath)
{
    struct stat file;
    stat(filepath, &file);
    char *buffer = malloc(sizeof(char) * (file.st_size) + mal);
    char **map = NULL;
    int my_open = open(filepath, O_RDONLY);
    ssize_t my_read = 0;

    if (my_open == error || buffer == NULL)
        return NULL;
    my_read = read(my_open, buffer, file.st_size);
    if (my_read == error)
        return NULL;
    buffer[file.st_size] = '\0';
    map = str_to_array(buffer, '\n');
    if (map == NULL || is_bad_map(map) == error) {
        free(buffer);
        return NULL;
    }
    get_clean_tab(map);
    free(buffer);
    return map;
}