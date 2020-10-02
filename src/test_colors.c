#include <stdio.h>
#include <stdlib.h>
#include "format.h"
#include <string.h>

int main()
{
    char *s = str_color("hello", BLU_B);
    char *ss = str_n_color("hello", RED_B, 2);
    char *s1 = str_interv_color("hello", GRN_B, 1, 3);
    char *s2 = str_index_color("hello", BLK_B, 4);
    char *ss1 = str_char_color("hello", YEL_B, 'l');
    printf("%s %s %s %s %s\n", s, ss, s1, s2, ss1);
    free(s);
    free(ss);
    free(s1);
    free(s2);
    free(ss1);
    return 0;
}