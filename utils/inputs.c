#include "../my.h/my.h"

void
my_putchar(char c)
{
    write(1, &c, 1);
}

void
my_putstr(char *str)
{
    for(int i  = 0; str[i]; i += 1) my_putchar(str[i]);
}

void
my_putnbr(int nb) {
    if (nb < 0) {
        my_putchar('-');
        my_putnbr(nb * -1);
    }
    else if (nb > 9) {
        my_putnbr(nb / 10);
        my_putnbr(nb % 10);
    }
    else my_putchar(nb + 48);
}

int
my_showtab(char **tab) {
    if (tab == NULL) return -1;

    for (int i = 0; tab[i]; i += 1) my_putstr(tab[i]);

    return 0;
}

void
my_puterror(char *str) {
	write(2, str, my_strlen(str));
}