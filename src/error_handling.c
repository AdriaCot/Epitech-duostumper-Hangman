/*
** EPITECH PROJECT, 2024
** hangman
** File description:
** error_handling.c
*/

#include "../my.h"

int check_word(char *line)
{
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '\t' || line[i] == ' ')
            return 84;
    }
    return 0;
}

void check_lines(char *filepath)
{
    FILE *file = fopen(filepath, "r");
    char *line = NULL;
    size_t size;

    if (file == NULL)
        exit(84);
    for (ssize_t read = getline(&line, &size, file);
        read != -1; read = getline(&line, &size, file)) {
        if (check_word(line) != 0) {
            free(line);
            fclose(file);
            exit(84);
        }
    }
    free(line);
    fclose(file);
}

int check_errors(int ac, char **av)
{
    if (ac < 2 || ac > 3) {
        fprintf(stderr, "Usage: %s <word_file>\n", av[0]);
        exit(84);
    }
    check_lines(av[1]);
    if (ac == 3) {
        if (atoi(av[2]) == 0)
            exit(84);
    }
    return 0;
}
