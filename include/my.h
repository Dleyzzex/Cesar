/*
** EPITECH PROJECT, 2018
** my
** File description:
** for prototypes
*/

#ifndef MY_H
#define MY_H

#include <sys/stat.h>
#include <stdlib.h>
#include <stdbool.h>

/* Stumper */

char *decrypt_file(char **av);
char *read_file(char *filepath);
const char *encrypt(char *str, int key);
char *manage_errors(int ac, char **av, char *str);
bool is_letter(char c);

#endif
