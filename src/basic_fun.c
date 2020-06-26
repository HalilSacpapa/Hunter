/*
** EPITECH PROJECT, 2018
** basic_fun.c
** File description:
** 
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}

void my_putnbr(int nb)
{
    if (nb > 9)
        my_putnbr(nb / 10);
    my_putchar(nb % 10 + '0');
}
