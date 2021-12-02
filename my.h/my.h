#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define TRUE 1
#define FALSE 0

//main.c
int main(void);

//utils.c
char *my_strcat(char *, char *);
int count_space(char *);
int count_malloc(char *, int);
char **my_strtowordtab(char *);
int my_strlen(char*);
int my_getnbr(char *);
void my_memset(char *, int);




//inputs.c
void    my_putchar(char);
void    my_putstr(char *);
void    my_putnbr(int);
int my_showtab(char **);
void    my_puterror(char *);


#endif /* !MY_H_ */
