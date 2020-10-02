#ifndef FORMAT_H
#define FORMAT_H

#include "ANSI_color_codes.h"

/* format_color.c */
char *str_color(char *, const char *);
char *str_n_color(char *, const char *, int);
char *str_interv_color(char *, const char *, int, int);
char *str_index_color(char *, const char *, int);
char *str_char_color(char *, const char *, char);


#endif /* FORMAT_H */