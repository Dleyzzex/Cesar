/*
** EPITECH PROJECT, 2019
** error_gestion
** File description:
** manage errors
*/

#include <string.h>
#include "my.h"

bool is_letter(char c)
{
    if (c < 'A' || (c > 'Z' && c < 'a') || c > 'z')
        return (false);
    return (true);
}

static bool is_num(char *str)
{
    size_t i = 0;

    while (str[i] != '\0') {
        if (str[i] != '-' && (str[i] < '0' || str[i] > '9'))
            return (true);
        i++;
    }
    return (false);
}

char *manage_errors(int ac, char **av, char *str)
{
    if (ac != 4)
        return (NULL);
    if (strcmp(av[2], "/root") == 0)
        return (NULL);
    if (av[1][0] == '-' && av[1][1] == 'f')
        str = read_file(av[2]);
    if (av[1][0] == '-' && av[1][1] == 's')
        str = av[2];
    if (is_num(av[3]) == true)
        return (NULL);
    if (str[0] == ' ')
        return (NULL);
    return (str);
}
