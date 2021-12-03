

#ifndef UTILS_H_
#define UTILS_H_

#include "../my.h/my.h"

typedef struct s_line t_line;

//string.c
int is_a_num(t_line *, char *);
int my_strlen(char*);
int my_getnbr(char *);
int count_space(char *);
int count_malloc(char *, int);
int tab_size(char **);
char    *my_strcat(char *, char *);
char    **my_strtowordtab(char *);
char    *from_eol_to_space(char *);
void    my_memset(char *, int);
void    select_a_word(t_line *);



//inputs_f.c
void    my_putchar(char);
void    my_putstr(char *);
void    my_putnbr(int);
void    my_puterror(char *);
int my_showtab(char **);

//files_handler.c
char    *get_next_line(void);
char *my_strcat(char *, char *);
int is_a_file(t_line *);
int is_file_empty(t_line *);
#endif /* !UTILS_H_ */
