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
is_a_file(t_line *game_handler) {
    if ((game_handler->fd = open(game_handler->filename, O_RDONLY)) == -1)  {
		close(game_handler->fd);
		error_functions_send(5);
	}
	return 1;
}

int
is_file_empty(t_line *game_handler) {
	struct stat st;

	if (game_handler->filename == NULL) error_functions_send(7);
	if ((stat(game_handler->filename, &st)) == -1) error_functions_send(6);
	if ((game_handler->file_content = malloc (sizeof(char) * st.st_size)) == NULL) error_functions_send(7);
	if (read(game_handler->fd, game_handler->file_content, st.st_size) == -1) error_functions_send(6);
	game_handler->file_content = from_eol_to_space(game_handler->file_content);
	game_handler->words = my_strtowordtab(game_handler->file_content);
	select_a_word(game_handler);
	return 1;
}

int
count_size_elem(t_line *game_handler) {
	for (int i = 0; game_handler->words[i]; i += 1) {
		if (my_strlen(game_handler->words[i]) < game_handler->char_number) error_functions_send(8);
	}
	if (game_handler->char_number == 0) error_functions_send(8);
	return 1;
}