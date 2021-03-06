#ifndef ERROR_H_
#define ERROR_H_

#include "../my.h/my.h"

typedef	void	(*ptab_t)(void);
typedef struct s_line t_line;


#define LESS_ARG        0
#define MUCH_ARG        1
#define NOT_NUM         2
#define NOT_FILE        3
#define BAD_ARG         4
#define OPEN_FAIL       5
#define READ_FAIL       6
#define MALLOC_FAIL     7
#define SIZE_NUM        8
#define SPACE_ON_FILE   9
#define ONECHAR         10

#define NULL__          11

//errors_handler.c

void    error_handler(int, char **);
void    error_functions_send(int);
void    error_from_argc(int);
void    too_less_arg_num(void);
void    too_much_arg_num(void);
void    not_a_num(void);
void    error_from_argv(void);
void    bad_argument(void);
void    open_failure(void);
void    not_a_file(void);
void    read_failure(void);
void    malloc_failure(void);
void    size_number_error(void);
void    space_on_file(void);
void    one_char(void);
int p_error(int, char **, t_line *);

#endif /* !ERROR_H_ */
