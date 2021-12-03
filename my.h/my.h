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




//main.c
int main(int, char **);
void    help_handler(void);
void    game(int, char **);



#endif /* !MY_H_ */
