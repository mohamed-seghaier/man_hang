#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#include "../utils/utils.h"
#include "../src/error.h"


#define TRUE 1
#define FALSE 0
#define EXIT exit(84)

typedef struct s_line {
    char    *filename;
    char    *file_content;
    char    **words;
    char    *word;
    int char_number;
    int fd;
} t_line;


//main.c
int main(int, char **);
void    help_handler(void);
void    game(t_line *);



#endif /* !MY_H_ */
