#include "./utils.h"


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
*get_next_line(void) {
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

int
is_a_file(char *filename) {
	int	fd;
    if ((fd = open(filename, O_RDONLY)) == -1)  {
		close(fd);
		error_functions_send(5);
	} else close(fd);
	return 1;
}