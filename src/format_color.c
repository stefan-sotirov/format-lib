#include "format.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* 
 *  SYNOPSIS
 *  #include "format.h"
 *  char *str_color(char *s, const char *c) - colors the entire string
 *  char *str_n_color(char *s, const char *c, int n) - colors n characters from the beginning of the string 
 *  char *str_interv_color(char *s, const char *c, int i, int j) - colors an interval within a string
 *  char *str_index_color(char *s, const char *c, int i) - colors the character on a given index
 *  char *str_char_color(char *s, const char *c, char ch) - colors every found character within a string
 * 
 *  DESCRIPTION
 *  The str_color() family of functions takes strings and colors them according to the passed ANSI escape codes
 *  The codes are listed in ANSI_color_codes.h
 * 
 *  RETURN VALUES
 *  A new string with the escape codes
 */

char *str_color(char *s, const char *c)
{
    char *str = (char *)malloc(strlen(s) + strlen(c) + strlen(reset) + 1);
    strcpy(str, c);
    strcat(str, s);
    strcat(str, reset);
    return str;
}

char *str_n_color(char *s, const char *c, int n)
{
    char *str = (char *)malloc(strlen(s) + strlen(c) + strlen(reset) + 1);
    strcat(str, c);
    strncat(str, s, n);
    strcat(str, reset);
    strcat(str, &s[n]);
    return str;
}

char *str_interv_color(char *s, const char *c, int i, int j)
{
    char *str = (char *)malloc(strlen(s) + strlen(c) + strlen(reset) + 1);
    strncpy(str, s, i);
    strcat(str, c);
    strncat(str, &s[i], j - i + 1);
    strcat(str, reset);
    strcat(str, &s[j + 1]);
    return str;
}

char *str_index_color(char *s, const char *c, int i)
{
    char *str = (char *)malloc(strlen(s) + strlen(c) + strlen(reset) + 1);
    strncpy(str, s, i);
    strcat(str, c);
    strncat(str, &s[i], 1);
    strcat(str, reset);
    strcat(str, &s[i + 1]);
    return str;
}

char *str_char_color(char *s, const char *c, char ch)
{
    int s_len = strlen(s), c_len = strlen(c), res_len = strlen(reset);
    char *str = (char *)malloc(s_len + c_len + res_len + 1);
    int last = -1, i, j = 1;
    for (i = 0; i <= s_len; ++i)
    {
        if (s[i] == ch)
        {
            str = (char *)realloc(str, s_len + j * c_len + j++ * res_len + 1);
            int dif = i - last > 1 ? i - last - 1 : 0;
            strncat(str, &s[last + 1], dif);
            last = i;
            strcat(str, c);
            strncat(str, &s[i], 1);
            strcat(str, reset);
        }
    }
    strcat(str, &s[last + 1]);
    return str;
}