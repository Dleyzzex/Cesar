/*
** EPITECH PROJECT, 2019
** decrypt
** File description:
** decrypt message
*/

#include <stdio.h>
#include "my.h"

const char *reference = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

static size_t get_letter_index(size_t i, char c)
{
    while (reference[i] != 'Z') {
        if (c == reference[i])
            return (i);
        i++;
    }
    return (i);
}

static char is_key_positive_negative(int j, size_t i, int key)
{
    char letter;

    if (key > 0) {
        while (j < key) {
            i = ((reference[i] == 'Z') ? 0 : (i + 1));
            letter = reference[i];
            j++;
        }
    }
    if (key < 0) {
        while (j < (key * (-1))) {
            i = ((reference[i] == 'A') ? 25 : (i - 1));
            letter = reference[i];
            j++;
        }
    }
    return (letter);
}

static char change_letter(char c, int key)
{
    bool is_min = false;
    size_t i = 0;
    int j = 0;
    char letter;

    if (c >= 'a' && c <= 'z') {
        is_min = true;
        c -= 32;
    }
    i = get_letter_index(i, c);
    letter = is_key_positive_negative(j, i, key);
    if (is_min == true)
        return (letter + 32);
    return (letter);
}

static char *encrypt_str(char *str, int key, size_t i)
{
    if (key == 0)
        return (str);
    while (str[i] != '\0') {
        if (is_letter(str[i]) == true)
            str[i] = change_letter(str[i], key);
        i++;
    }
    return (str);
}

const char *encrypt(char *str, int key)
{
    size_t i = 0;
    const char *result = encrypt_str(str, key, i);

    if (result == NULL)
        return (NULL);
    printf("%s\n", result);
    return (result);
}
