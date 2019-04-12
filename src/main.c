    /*
** EPITECH PROJECT, 2019
** main
** File description:
** main for duo stumper
*/

#include <stdio.h>
#include "my.h"

void flag_h(void)
{
    printf("Usage:\n\n./ceasar -f filename key ");
    printf("Or ./ceasar -s \"string\" key\n");
}

int main(int ac, char **av)
{
    char *str = " ";

    if (av[1][0] == '-' && av[1][1] == 'h') {
        flag_h();
        exit(0);
    }
    if ((str = manage_errors(ac, av, str)) == NULL)
        return (84);
    if (encrypt(str, atoi(av[3])) == NULL)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'f')
        free(str);
    return (0);
}
