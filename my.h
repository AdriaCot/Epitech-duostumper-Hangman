/*
** EPITECH PROJECT, 2023
** hangman
** File description:
** my.h
*/

#ifndef HANGMAN
    #define HANGMAN

    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <time.h>

int check_errors(int ac, char **av);

char *get_word_from_file(char *filename, char *word);

#endif
