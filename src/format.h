#ifndef FORMAT_H
#define FORMAT_H

#include "ANSI_color_codes.h"

/* format_color.c */
char *str_color(char *, const char *);
char *str_n_color(char *, const char *, int);
char *str_interv_color(char *, const char *, int, int);
char *str_index_color(char *, const char *, int);
char *str_char_color(char *, const char *, char);


/* format_position.c */
char *str_n_push_pos_v(char *, int);
char *str_n_pull_pos_v(char *, int);
char *str_center_pos_v(char *, int);
char *str_leftmost_pos(char *, int);
char *str_rightmost_pos(char *, int);

char *str_n_push_pos_h(char *, int);
char *str_n_pull_pos_h(char *, int);
char *str_center_pos_h(char *, int);
char *str_upmost_pos(char *, int);
char *str_downmost_pos(char *, int);


/* cursor.c */
char *pos_c(int l, int c);
char *mov_c_fwd(int n);
char *mov_c_bwd(int n);
char *mov_c_up(int n);
char *mov_c_down(int n);
#define c_scr() "\e[2J" /* clears screen and sets cursor to [0,0] */
#define c_scr_up() "\e[1J" /* clears screen from cursor to the beginning */
#define c_scr_down() "\e[0J" /* clears screen from cursor to the end */

#endif /* FORMAT_H */