#include "../my.h/my.h"



int
p_error(int argc, char **argv) {
    if (!is_a_num(argv[2])) error_functions_send(2);
    if (!is_a_file(argv[1])) error_functions_send(3);
    return 1;
}

void
error_handler(int argc, char **argv) {
    if (argc != 3) error_from_argc(argc);
    else error_from_argv();
}

void
error_functions_send(int error_n) {
    ptab_t  error_tab[7];

    error_tab[0] = &too_less_arg_num;
    error_tab[1] = &too_much_arg_num;
    error_tab[2] = &not_a_num;
    error_tab[3] = &not_a_file;
    error_tab[4] = &bad_argument;
    error_tab[5] = &open_failure;
    
	error_tab[6] = NULL;

    (*error_tab[error_n])();
}

void
error_from_argc(int argc) {
    switch (argc) {
    case 1 : error_functions_send(0);
    case 2 : error_functions_send(0);
    default: error_functions_send(1);
    }
}

void
open_failure(void) {
    my_puterror("Erreur lors de l'ouverture du fichier. Veuillez entrer un nom de fichier existant.\n");
    EXIT;
}

void
error_from_argv(void) {
    error_functions_send(5);
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