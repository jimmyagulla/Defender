/*
** EPITECH PROJECT, 2020
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "my.h"

int is_next_separator(char *str, char *separator, int index)
{
    for (int n = 0; separator[n] != 0; n++)
        if (str[index + 1] == separator[n])
            return (1);
    return (0);
}

int get_nb_words(char *str, char *separator)
{
    int nb_words = 1;

    for (int index = 0; str[index] != 0; index++)
        for (int n = 0; separator[n] != 0; n++)
            if (str[index] == separator[n] && \
            is_next_separator(str, separator, index) == 0)
                nb_words++;
    nb_words++;
    return (nb_words);
}

int get_word_len(char *str, char *separators, int index, int count)
{
    for (int n = 0; separators[n]; n++) {
        if (str[index] == separators[n] || str[index + 1] == '\0') {
            return (count);
        }
    }
    return (0);
}

char **my_str_to_word_array(char *str, char *separators)
{
    int word = 0;
    int count = 0;
    int word_len = 0;
    int decale = 0;
    char **arr = malloc(sizeof(char *) * get_nb_words(str, separators));

    for (int i = 0; str[i] != 0; i++) {
        count++;
        word_len = get_word_len(str, separators, i, count);
        if (word_len != 0) {
            arr[word] = malloc(sizeof(char) * (word_len + 1));
            my_strncpy(arr[word], str + decale, count);
            arr[word][word_len] = 0;
            decale += count;
            word += 1;
            count = 0;
        }
    }
    arr[get_nb_words(str, separators) - 1] = NULL;
    return (arr);
}