#include "format.h"
#include <stdlib.h>
#include <string.h> 
#include <stdio.h>

/*
 *  SYNOPSIS
 *  #include "format.h"
 *  char *mov_c_fwd(int n) - moves the cursor n positions forward(to the right)
 *  char *mov_c_bwd(int n) - moves the cursor n positions backward(to the left)
 *  char *mov_c_up(int n) - moves the cursor n positions(lines) upward
 *  char *mov_c_down(int n) - moves the cursor n positions(lines) downward
 *  char *pos_c(int l, int c) - moves the cursor l lines and c columns
 * 
 *  DESCRIPTION
 *  This file contains functions used to manipulate the console cursor position - like pointers to the cursor
 *  
 *  RETURN VALUES
 *  A new string with the escape code(s)
*/ 

char *mov_c_fwd(int n)
{
    char *n_str = (char *)malloc(4);
    sprintf(n_str, "%d", n);
    char *str = (char *)malloc(10);
    strcpy(str, "\e[");
    strcat(str, n_str);
    strcat(str, "C");
    free(n_str);
    return str;
}

char *mov_c_bwd(int n)
{
    char *n_str = (char *)malloc(4);
    sprintf(n_str, "%d", n);
    char *str = (char *)malloc(10);
    strcpy(str, "\e[");
    strcat(str, n_str);
    strcat(str, "D");
    free(n_str);
    return str;
}

char *mov_c_up(int n)
{
    char *n_str = (char *)malloc(4);
    sprintf(n_str, "%d", n);
    char *str = (char *)malloc(10);
    strcpy(str, "\e[");
    strcat(str, n_str);
    strcat(str, "A");
    free(n_str);
    return str;
}

char *mov_c_down(int n)
{
    char *n_str = (char *)malloc(4);
    sprintf(n_str, "%d", n);
    char *str = (char *)malloc(10);
    strcpy(str, "\e[");
    strcat(str, n_str);
    strcat(str, "B");
    free(n_str);
    return str;
}

char *pos_c(int l, int c)
{
    char *str = (char *)malloc(l * 10 + c * 10);
    strcpy(str, l > 0 ? mov_c_down(l) : mov_c_up(l));
    strcat(str, c > 0 ? mov_c_fwd(c) : mov_c_bwd(c));
    return str;
}