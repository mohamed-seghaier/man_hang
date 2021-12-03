#include "../my.h/my.h"

int main(int argc, char **argv)
{
    t_line game_handle;
    if (argc == 2 && !strcmp(argv[1], "-h")) help_handler();
    else if (argc == 3 && p_error(argc, argv, &game_handle)) game(&game_handle);
    else error_handler(argc, argv);
    return 0;
}

void
help_handler(void) {
    write(1, "MAN HANG - HELP HANDLER\nPour lancer le jeu, veuillez respecter les regles suivantes:\n\t1 : Vous devez entrer dans le terminal une commande précise, respectant ce sens : ./man_hang \"nom_du_fichier\" nombre_de_lettres.\n\t2 : Vous devez entrer dans votre fichier une série de mots ne contenant que des lettres.\n\t3 : Le fichier ne doit pas être vide.\n\t4 : Le nombre entré en paramètre doit être plus petit que le plus petit des mots du fichier.\n\t\tQue la force soit avec vous.\nMan Hang - SEGHAIER Mohamed-Ali\n",508) ;
}
void
game(t_line *game_handler) {
    my_putstr(game_handler->word);
    my_putnbr(game_handler->char_number);
}

