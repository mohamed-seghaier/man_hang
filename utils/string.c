#include "../my.h/my.h"



void
select_a_word(t_line *game_handler) {
	int i = (tab_size(game_handler->words));
    srand(time(NULL));
    game_handler->word = game_handler->words[(rand() % i)];
}

int
tab_size(char **tab) {
    int i = 0;
    for (i = 0; tab[i]; i += 1);
    return i;
}

char *
from_eol_to_space(char *str) {
    for(int i = 0; str[i]; i += 1) {
        if (str[i] == ' ') error_functions_send(9);
        if (str[i] == '\n') str[i] = ' ';
    }
    return str;
}

int
is_a_num(t_line *game_handler, char *str) {
    for (int i = 0; str[i]; i += 1) {
        if (str[i] < '0' || str[i] > '9') return 0;
    }
    game_handler->char_number = my_getnbr(str);
    if (count_size_elem(game_handler) == 0) return 0;
    return 1;
}

int
my_strlen(char *str) {
    
    int i = 0;
    for (; str[i]; i += 1);
    return i;
}

int
my_getnbr(char *str) {
    int neg = 1;
    int res = 0;
    int idx = 0;

    if (str[0]  == '-')  {
        neg *= -1;
        idx += 1;
    }
    for (;str[idx]; idx += 1) {
        res *= 10;
        res += str[idx] - '0';
    }
    return res * neg;
}

void
my_memset(char *str, int size) {
    for (int i = 0; i < size; i += 1) str[i] = 0;
}


//StrToWordTab_start

char
**my_strtowordtab(char *str) {
    int idx = 0;
    int i = 0;
    int j = 0;
    char **res = NULL;

    if ((res = malloc(sizeof(char *) * count_space(str) + 1)) == NULL) error_functions_send(7);
    if ((res[j] = malloc(sizeof(char) * count_malloc(str, 0))) == NULL) error_functions_send(7);
    for (; str[i]; i += 1) {
        if (str[i] != ' ') {
            res[j][idx] = str[i];
            idx += 1;
        } else {
            j += 1;
            if ((res[j] = malloc(sizeof(char) * count_malloc(str, j))) == NULL) error_functions_send(7);
            idx = 0;
        }
    }
    res[j + 1] = NULL;
    return res;
}

int
count_malloc(char *str, int idx) {
    if (str[idx] == ' ') idx += 1;
    for (; str[idx] != ' '; idx += 1);
    return idx;
}

int
count_space(char *str) {
    int j = 0;
    for (int i = 0; str[i]; i += 1) j += str[i] == ' ' ? 1 : 0;

    return j + 1;
}

//StrToWordTab_end


