/*
** EPITECH PROJECT, 2018
** read file
** File description:
** foo
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

char *read_file(char *filepath)
{
    struct stat file;
    char *buffer = " ";
    int fd = 0;
    size_t size = 0;

    if (stat(filepath, &file) == -1)
        return (NULL);
    if ((fd = open(filepath, O_RDONLY)) == -1)
        return NULL;
    if (!(buffer = malloc(sizeof(char) * (file.st_size + 1))))
        return NULL;
    if (!(file.st_mode & S_IROTH))
        return (NULL);
    size = read(fd, buffer, file.st_size);
    buffer[size] = '\0';
    close(fd);
    return (buffer);
}
