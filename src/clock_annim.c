/*
** EPITECH PROJECT, 2018
** clock_annim.c
** File description:
** 
*/

#include "../include/my.h"

void var_init(s_hunter *p)
{
    p->game_stat = 1;
    p->offset = 110;
    p->max_value = 220;
    p->height = 1280;
    p->width = 769;
    p->cond = 0;
    p->score = 0;
    p->s = 0;
    p->speed = 15;
    p->f = 0;
}

void duck_clock(s_hunter *p)
{
    if (p->cond == 0) {
        p->clock = sfClock_create();
        p->cond = 1;
    }
    while (p->cond == 1) {
        p->time = sfClock_getElapsedTime(p->clock);
        p->seconds = p->time.microseconds / 100000.0;
        if (p->seconds > 1.0) {
            duck_vector(p);
            p->cond = 2;
        }
    }
    if (p->cond == 2) {
        sfClock_restart(p->clock);
        p->cond = 1;
    }
}

void duck_reset(s_hunter *p)
{
    p->duck_vec.x = 0;
    p->duck_vec.y = rand() % (p->width - p->rect.width);
    p->duck_pos = 0;
}

void duck_vector(s_hunter *p)
{
    p->duck_pos = p->duck_pos + p->speed;
    p->duck_vec.x = p->duck_pos;
    duck_move(p);
    if (p->duck_vec.x > p->height) {
        duck_reset(p);
        duck_vector(p);
    }
}
