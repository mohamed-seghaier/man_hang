#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>


#include "../utils/utils.h"
#include "../src/error.h"


#define TRUE 1
#define FALSE 0
#define EXIT exit(84)
#define WIN exit(1)
#define LOOSE exit(1)

typedef struct s_line {
    char    *filename;
    char    *file_content;
    char    **words;
    char    *word;
    char    *hidden_word;
    char    **ascii;
    int char_number;
    int fd;
    int chances;
} t_line;


//main.c
int main(int, char **);
int is_finished(char *);
void    help_handler(void);
void    game_loop(t_line *);
void    hide_some_char(t_line *);
void    check_char(char *, t_line *);
void    step_success(int, t_line *);
void    finished(int);
void    step_failure(t_line *);

#endif /* !MY_H_ */
