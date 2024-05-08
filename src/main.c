/*
** EPITECH PROJECT, 2024
** hangman
** File description:
** main.c
*/

#include "../my.h"

static int get_tries_nbr(char **av)
{
    int i = 0;

    for (i = 0; av[i] != NULL; i++);
    if (i == 2) {
        return 10;
    } else {
        return atoi(av[2]);
    }
}

static void print_game(char *hidden_word, int tries)
{
    printf("%s\n", hidden_word);
    printf("Tries: %d\n\n", tries);
}

static int check_letter(char c, char *word, char **hidden)
{
    int counter = 0;

    for (int i = 0; i < strlen(word); i++) {
        if (c == word[i]) {
            (*hidden)[i] = word[i];
            counter++;
        }
    }
    if (counter != 0)
        return 1;
    printf("%c: is not in this word\n", c);
    return 0;
}

static int modify_hidden_string(char *word, char **hidden_word)
{
    char *line = NULL;
    ssize_t read;
    size_t size;
    int result;

    printf("Your letter: ");
    read = getline(&line, &size, stdin);
    if (line == NULL || read == -1) {
        free(word);
        free(*hidden_word);
        exit(84);
    }
    if (read != 2) {
        printf("Invalid input\n");
        free(line);
        return 1;
    }
    result = check_letter(line[0], word, hidden_word);
    free(line);
    return result;
}

char *make_hidden_word(char *word)
{
    char *hidden_word = malloc(sizeof(char) * (strlen(word) + 1));

    if (hidden_word == NULL) {
        free(word);
        exit(84);
    }
    for (int i = 0; i < strlen(word); i++)
        hidden_word[i] = '*';
    hidden_word[strlen(word)] = '\0';
    return hidden_word;
}

void game_loop(char *word, int tries)
{
    char *hidden_word = make_hidden_word(word);

    print_game(hidden_word, tries);
    while (tries != 0) {
        tries += modify_hidden_string(word, &hidden_word);
        tries--;
        print_game(hidden_word, tries);
        if (strcmp(word, hidden_word) == 0) {
            printf("Congratulations!\n");
            free(hidden_word);
            return;
        }
        if (tries == 0)
            printf("You lost!\n");
    }
}

int main(int ac, char *av[])
{
    int error = check_errors(ac, av);
    char *word = NULL;
    int tries = get_tries_nbr(av);

    word = get_word_from_file(av[1], word);
    game_loop(word, tries);
    free(word);
    return 0;
}
