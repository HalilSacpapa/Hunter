/*
** EPITECH PROJECT, 2018
** help.c
** File description:
** 
*/

#include "../include/my.h"

int help(int ac, char **av)
{
    if (av[1][1] == 'h' && ac == 2) {
        my_putstr("***Welcome to Duck Hunt !***");
        my_putchar('\n');
        my_putchar('\n');
        my_putstr(" Shoot ducks with the cursor.");
        my_putchar('\n');
        my_putstr("Ducks speed up every 10 kills");
        my_putchar('\n');
        my_putstr("    You only got 5 lives.");
        my_putchar('\n');
        my_putchar('\n');
        my_putstr("***Good luck and have fun !***");
        return (0);
    }
    return (84);
}
