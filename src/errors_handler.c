#include "../my.h/my.h"



int
p_error(int argc, char **argv, t_line *game_handle) {
    if ((game_handle->filename = malloc(sizeof(char) * strlen(argv[1]) + 1)) == NULL) error_functions_send(MALLOC_FAIL);
    if ((strcpy(game_handle->filename, argv[1])) == NULL) EXIT;
    if (!is_a_file(game_handle)) error_functions_send(NOT_FILE);
    if (!is_file_empty(game_handle)) error_functions_send(READ_FAIL);
    if (!is_a_num(game_handle, argv[2])) error_functions_send(NOT_NUM);
    return 1;
}

void
error_handler(int argc, char **argv) {
    if (argc != 3) error_from_argc(argc);
    else error_from_argv();
}

void
error_functions_send(int error_n) {
    ptab_t  error_tab[11];

    error_tab[LESS_ARG] = &too_less_arg_num;
    error_tab[MUCH_ARG] = &too_much_arg_num;
    error_tab[NOT_NUM] = &not_a_num;
    error_tab[NOT_FILE] = &not_a_file;
    error_tab[BAD_ARG] = &bad_argument;
    error_tab[OPEN_FAIL] = &open_failure;
    error_tab[READ_FAIL] = &read_failure;
    error_tab[MALLOC_FAIL] = &malloc_failure;
    error_tab[SIZE_NUM] = &size_number_error;
    error_tab[SPACE_ON_FILE] = &space_on_file;
    error_tab[ONECHAR] = &one_char;
    
	error_tab[NULL__] = NULL;

    (*error_tab[error_n])();
}

void
one_char(void) {
    my_puterror("Erreur lors de l'entrée d'une lettre.\n");
    EXIT;
}

void
read_failure(void) {
    my_puterror("Erreur lors de la lecture de votre fichier. Veuillez vérifier son contenu.\n");
    EXIT;
}

void
space_on_file(void) {
    my_puterror("Espaces interdits dans le fichier.\n");
    EXIT;
}

void
error_from_argc(int argc) {
    switch (argc) {
    case 1 : error_functions_send(LESS_ARG);
    case 2 : error_functions_send(LESS_ARG);
    default: error_functions_send(MUCH_ARG);
    }
}

void
open_failure(void) {
    my_puterror("Erreur lors de l'ouverture du fichier. Veuillez entrer un nom de fichier existant.\n");
    EXIT;
}

void
error_from_argv(void) {
    error_functions_send(OPEN_FAIL);
}

void
bad_argument(void) {
    my_puterror("Mauvais arguments entrés.\n");
    EXIT;
}

void
too_less_arg_num(void) {
    my_puterror("Nombre d'arguments insuffisant pour lancer le jeu.\n");
    EXIT;
}

void
too_much_arg_num(void) {
    my_puterror("Nombre d'arguments trop important pour lancer le jeu.\n");
    EXIT;
}

void
not_a_num(void) {
    my_puterror("Caractère interdit. Veuillez n'entrer que des caractères numériques dans le paramètre numéro 2.\n");
    EXIT;
}

void
not_a_file(void) {
    my_puterror("Error lors de l'ouverture du fichier. Veuillez entrer un nom de fichier existant.\n");
    EXIT;
}

void
malloc_failure(void) {
    my_puterror("Erreur lors de l'allocation de mémoire.\n");
    EXIT;
}

void
size_number_error(void) {
    my_puterror("Erreur sur le nombre envoyé en paramètre. Veuillez entrer un nombre plus petit ou différent de 0.\n");
    EXIT;
}