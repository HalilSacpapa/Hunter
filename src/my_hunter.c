/*
** EPITECH PROJECT, 2018
** my_hunter.c
** File description:
** 
*/

#include "../include/my.h"

void hunter(s_hunter *p)
{
    cr_window(p);
    cr_tex_snd(p);
    sfMusic_play(p->intro_mel);
    var_init(p);
    while (sfRenderWindow_isOpen(p->window)) {
        while (sfRenderWindow_pollEvent(p->window, &p->event)) {
            if (p->event.type == sfEvtClosed)
                sfRenderWindow_close(p->window);
        }
        clic(p);
        //game(p);
        duck_clock(p);
        duck_vector(p);
        draw(p);
    }
    destroy(p);
}

void clic(s_hunter *p)
{
    if (p->event.type == sfEvtMouseButtonPressed) {
        p->x = p->event.mouseButton.x - p->duck_vec.x;
        p->y = p->event.mouseButton.y - p->duck_vec.y;
        if (p->x < p->rect.width && p->x > 0 && p->y < p->rect.height && p->y > 0) {
            p->score++;
            my_putstr("score: ");
            my_putnbr(p->score);
            my_putchar('\n');
            duck_reset(p);
        } else {
            p->f++;
            my_putstr("miss !");
            my_putchar('\n');
            if (p->f == 5) {
                my_putstr("Nice game !");
                my_putchar('\n');
                my_putstr("Your final score is: ");
                my_putnbr(p->score);
                my_putchar('\n');
            }
        }
        if (p->score == p->s + 10) {
            p->speed = p->speed + 10;
            p->s = p->s + 10;
        }
    }
}

void duck_move(s_hunter *p)
{
    if (p->rect.left >= p->max_value)
	p->rect.left = 0;
    else
        p->rect.left = p->rect.left + p->offset;
    sfSprite_setTextureRect(p->duck_sprite, p->rect);
    sfSprite_setPosition(p->duck_sprite, p->duck_vec);
}

/*void game(s_hunter *p)
{
    if (p->game_stat == 1) {
        duck_clock(p);
        duck_vector(p);
    } else if (p->game_stat == 2) {
        p->game_stat = 2;
        game(p);
    }
    }*/

int main(int ac, char **av)
{
    if (ac == 2) {
        help(ac, av);
        return (0);
    }
    s_hunter p;
    hunter(&p);
    return (0);
}
