/*
** EPITECH PROJECT, 2024
** hangman
** File description:
** get_word.c
*/

#include "../my.h"

int count_words_number(char *filename)
{
    FILE *file = fopen(filename, "r");
    size_t size;
    char *line = NULL;
    int counter = 0;

    if (file == NULL)
        exit(84);
    while (getline(&line, &size, file) != -1)
        counter++;
    free(line);
    fclose(file);
    return counter;
}

char *clean_line(char *line, ssize_t read)
{
    int len = strlen(line);

    if (line[len - 1] == '\n') {
        line[len - 1] = '\0';
    }
    return line;
}

int get_random_number(int min, int max)
{
    int random_num;
    int result;
    int range;

    srand(time(NULL));
    random_num = rand();
    range = max - min;
    result = min + (random_num % range);
    return result;
}

void check_file_not_null(FILE *file)
{
    if (file == NULL)
        exit(84);
}

char *get_word_from_file(char *filename, char *word)
{
    FILE *file = fopen(filename, "r");
    size_t size;
    int line_nbr;
    int random;
    ssize_t read;

    check_file_not_null(file);
    line_nbr = count_words_number(filename);
    random = get_random_number(0, line_nbr);
    line_nbr = 0;
    for (read = getline(&word, &size, file);
        read != -1; read = getline(&word, &size, file)) {
        if (line_nbr == random)
            break;
        line_nbr++;
    }
    word = clean_line(word, read);
    fclose(file);
    return word;
}
