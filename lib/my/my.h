/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** header for libs
*/

#ifndef __MY_H__
#define __MY_H__

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Audio.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/JoystickIdentification.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <stdbool.h>

char **my_str_to_word_array_delim(const char *str, const char *separators);
int my_getnbr(char const *str);
int my_isneg(int n);
int my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
char *my_revstr (char *str);
char *my_strcat (char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest , char const *src);
int my_str_isnum (char const *str);
int my_strlen(char const *str);
char *my_strncat (char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest , char const *src, int n);
char *my_itoa(int number);
char **my_str_to_word_array(char *str, char *separator);

#endif