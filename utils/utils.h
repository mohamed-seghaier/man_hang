

#ifndef UTILS_H_
#define UTILS_H_

#include "../my.h/my.h"


//string.c
int is_a_num(char *);
int my_strlen(char*);
int my_getnbr(char *);
int count_space(char *);
int count_malloc(char *, int);
char *my_strcat(char *, char *);
char **my_strtowordtab(char *);
void my_memset(char *, int);



//inputs_f.c
void    my_putchar(char);
void    my_putstr(char *);
void    my_putnbr(int);
void    my_puterror(char *);
int my_showtab(char **);

//files_handler.c
char    *get_next_line(void);
char *my_strcat(char *, char *);
int is_a_file(char *);
#endif /* !UTILS_H_ */
