#include "../my.h/my.h"

void
game_loop(t_line *game_handler) {
    char *str = NULL;
    game_handler->chances = 3;

    hide_some_char(game_handler);
    while("Dali") {
        my_putstr(game_handler->hidden_word);
        my_putstr("\nEntrez une lettre :\n");
        if ((str = get_next_line()) == ((void*)0)) error_functions_send(ONECHAR);
        if (strlen(str) == 1) check_char(str, game_handler);
        else if (strlen(str) > 1) my_puterror("Veuillez n'entrer qu'une lettre.\n");
        else my_puterror("Entrez au moins une lettre.\n");
    }
}

void
check_char(char *str, t_line *handle_game) {
    int i = 0;
    for (i = 0 ; handle_game->word[i]; i += 1) {
        if (str[0] == handle_game->word[i] && handle_game->hidden_word[i] == '_')  {
            step_success(i, handle_game);
            break;
        }
    }
    if (i == my_strlen(handle_game->hidden_word)) step_failure(handle_game);
}

void
step_failure(t_line *handle_game) {
    handle_game->chances -= 1;
    my_putstr("Cette lettre n'est pas dans le mot.\n");
    if (handle_game->chances == 0) {
        my_putstr("Vous n'avez plus de vies, vous avez perdu !\n");
        LOOSE;
    } else {
        my_putstr("Il vous reste ");
        my_putnbr(handle_game->chances);
        my_putstr(" vies.\n");
    }
}

void
step_success(int i, t_line *handle_game) {
    handle_game->hidden_word[i] = handle_game->word[i];
    if (is_finished(handle_game->hidden_word) == 1) finished(handle_game->chances);
}

int
is_finished(char *str) {
    for (int i = 0; str[i]; i += 1) {
        if (str[i] == '_') return FALSE;
    }
    return TRUE;
}

void
finished(int chances) {
    my_putstr("Bravo, vous avez réussi en ayant fait ");
    my_putnbr(3 - chances);
    my_putstr(" erreurs !\n");
    WIN;
}

void
hide_some_char(t_line *game_handler) {
    int i = 0;
    int randm = 0;

    srand(time(NULL));

    if ((game_handler->hidden_word = malloc(sizeof(char) * game_handler->char_number + 1)) == NULL) error_functions_send(MALLOC_FAIL);
    if ((strcpy(game_handler->hidden_word, game_handler->word)) == NULL) error_functions_send(MALLOC_FAIL);
    for (i = 0, randm = 0; i < game_handler->char_number;) {
        randm = rand() % strlen(game_handler->word);
        if(game_handler->hidden_word[randm] != '_') {
            game_handler->hidden_word[randm] = '_';
            i += 1;
        }
    }
}