#include "../my.h/my.h"

int main(int argc, char **argv)
{
    if (argc == 2 && !strcmp(argv[1], "-h")) help_handler();
    else if (argc == 3 && p_error(argc, argv)) game(argc, argv);
    else error_handler(argc, argv);
    return 0;
}

void
help_handler(void) {
    write(1, "MAN HANG - HELP HANDLER\nPour lancer le jeu, veuillez respecter les regles suivantes:\n\t1 : Vous devez entrer dans le terminal une commande précise, respectant ce sens : ./man_hang \"nom_du_fichier\" nombre_de_lettres.\n\t2 : Le nombre de lettres à trouver doit être de taille inférieur au nombre de lettres dans le mot.\n\t3 : Les mots de mois de cinq caractères ne seront pas pris en compte, le jeu commence à 5 et n\'a aucune limite de caractère.\n\t\tQue la force soit avec vous.\nMan Hang - SEGHAIER Mohamed-Ali\n",512) ;
}
void
game(int argc, char **argv) {
    my_putstr("good");
}

