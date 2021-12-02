#include "../my.h/my.h"



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

    if ((res = malloc(sizeof(char *) * count_space(str) + 1)) == NULL) return NULL;
    if ((res[j] = malloc(sizeof(char) * count_malloc(str, 0))) == NULL) return NULL;
    for (; str[i]; i += 1) {
        if (str[i] != ' ') {
            res[j][idx] = str[i];
            idx += 1;
        } else {
            j += 1;
            if ((res[j] = malloc(sizeof(char) * count_malloc(str, j))) == NULL) return NULL;
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



//GetNextLine_start

char
*my_strcat(char *src, char *dest)
{
	int	i = my_strlen(src);
	int	j = my_strlen(dest);
	int	k = 0;
	char	*tmp = malloc(sizeof(char) * (i + j) + 1);

	for (i = 0; src[i]; i += 1, k += 1)
		tmp[k] = src[i];
	for (i = 0; dest[i]; i += 1, k += 1)
		tmp[k] = dest[i];
	return (tmp);
}

char
*get_next_line() {
	char	tmp[2];
	char	*dest = "";
	int	i = 0;
	int	j = 0;

	my_memset(dest, my_strlen(dest));
	while ("Dali") {
		if ((read(0, tmp, 1)) == -1)
			return (j == 0 ? NULL : dest);
		if (tmp[i] == '\n')
			return (dest);
		if ((tmp[0]) == 0 || tmp[0] == '\04')
			return (NULL);
		dest = my_strcat(dest, tmp);
		j += 1;
	}
}
//GetNextLine_end

