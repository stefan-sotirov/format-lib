#include "format.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 *  SYNOPSYS
 *  #include "format.h"
 *  char *str_n_push_pos_h(char *s, int n) - pushes a string n positions forward horizontally
 *  char *str_n_pull_pos_h(char *s, int n) - pushes a string n positions backward horizontally
 *  char *str_center_pos_h(char *s, int w) - centers a string within a give width
 *  char *str_leftmost_pos(char *s, int w) - pushes a string to the leftmost limit of a given width
 *  char *str_rightmost_pos(char *s, int w) - pushes a string to the rightmost limit of a given width
 *  char *str_n_push_pos_v(char *s, int n) - pushes a string n positions forward vertically
 *  char *str_n_pull_pos_v(char *s, int n) - pushes a string n positions backward vertically
 *  char *str_center_pos_v(char *s, int h) - centers a string within a give height
 *  char *str_upmost_pos(char *s, int h) - pushes a string to the upmost limit of a given height
 *  char *str_downmost_pos(char *s, int h) - pushes a string to the downmost limit of a given height
 * 
 *  DESCRIPTION
 *  The str_pos() family of functions takes string and an int and changes the string's position according to the function
 *  
 *  RETURN VALUE
 *  A new string with the changed positions
 */

char *str_n_push_pos_h(char *s, int n)
{
    int s_len = strlen(s);
    char *str = (char *)malloc(s_len + n + 1);
    int i;
    for (i = 0; i < n; ++i)
    {
        str[i] = ' ';
    }
    str[i] = '\0';
    strcat(str, s);
    return str;
}

char *str_n_pull_pos_h(char *s, int n)
{
    int i;
    for (i = 0; i < n; ++i)
    {
        if (s[i] != ' ')
        {
            break;
        }
    }
    char *str = (char *)malloc(strlen(s) - i + 1);
    strcpy(str, &s[i]);
    return str;
}

char *str_center_pos_h(char *s, int w)
{
    int s_len = strlen(s);
    int c = w / 2 - s_len / 2 - s_len;
    return (str_n_push_pos_h(s, c));
}

char *str_leftmost_pos(char *s, int w)
{
    return (str_n_pull_pos_h(s, w));
}

char *str_rightmost_pos(char *s, int w)
{
    int c = w - strlen(s);
    return (str_n_push_pos_h(s, c));
}

char *str_n_push_pos_v(char *s, int n)
{
    int s_len = strlen(s);
    char *str = (char *)malloc(s_len + n + 1);
    int i;
    for (i = 0; i < n; ++i)
    {
        str[i] = '\n';
    }
    str[i] = '\0';
    strcat(str, s);
    return str;
}

char *str_n_pull_pos_v(char *s, int n)
{
    int i;
    for (i = 0; i < n; ++i)
    {
        if (s[i] != '\n')
        {
            break;
        }
    }
    char *str = (char *)malloc(strlen(s) - i + 1);
    strcpy(str, &s[i]);
    return str;
}

char *str_center_pos_v(char *s, int h)
{
    return (str_n_push_pos_v(s, h / 2));
}

char *str_upmost_pos(char *s, int h)
{
    return (str_n_pull_pos_v(s, h));
}

char *str_downmost_pos(char *s, int h)
{
    return (str_n_push_pos_v(s, h - 1));
}