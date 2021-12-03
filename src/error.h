#ifndef ERROR_H_
#define ERROR_H_

#include "../my.h/my.h"

typedef	void	(*ptab_t)(void);
typedef struct s_line t_line;


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
int p_error(int, char **, t_line *);

#endif /* !ERROR_H_ */
