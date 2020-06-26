/*
** EPITECH PROJECT, 2018
** init.c
** File description:
** 
*/

#include "../include/my.h"

void cr_window(s_hunter *p)
{
    sfVideoMode mode = {1280, 769, 32};

    p->window = sfRenderWindow_create(mode, "Duck Hunt", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(p->window, 30);
}

void cr_tex_snd(s_hunter *p)
{
    p->font_texture = sfTexture_createFromFile("pic/back.png", NULL);
    p->duck_texture = sfTexture_createFromFile("pic/duck.png", NULL);
    p->play_texture = sfTexture_createFromFile("pic/play.png", NULL);
    p->yalp_texture = sfTexture_createFromFile("pic/yalp.png", NULL);
    p->lose_texture = sfTexture_createFromFile("pic/game_over.png", NULL);

    cr_sprite(p);

    p->rect.top = 0;
    p->rect.left = 0;
    p->rect.width = 110;
    p->rect.height = 110;

    p->intro_mel = sfMusic_createFromFile("song/intro_song.ogg");
    p->game_over = sfMusic_createFromFile("song/game_over.ogg");
}

void cr_sprite(s_hunter *p)
{
    p->font_sprite = sfSprite_create();
    p->duck_sprite = sfSprite_create();
    p->play_sprite = sfSprite_create();
    p->yalp_sprite = sfSprite_create();
    p->lose_sprite = sfSprite_create();

    sfSprite_setTexture(p->font_sprite, p->font_texture, sfTrue);
    sfSprite_setTexture(p->duck_sprite, p->duck_texture, sfTrue);
    sfSprite_setTexture(p->play_sprite, p->play_texture, sfTrue);
    sfSprite_setTexture(p->yalp_sprite, p->yalp_texture, sfTrue);
    sfSprite_setTexture(p->lose_sprite, p->lose_texture, sfTrue);
}

void draw(s_hunter *p)
{
    sfRenderWindow_clear(p->window, sfBlack);
    sfRenderWindow_drawSprite(p->window, p->lose_sprite, NULL);
    sfRenderWindow_drawSprite(p->window, p->font_sprite, NULL);
    sfRenderWindow_drawSprite(p->window, p->duck_sprite, NULL);
    sfRenderWindow_display(p->window);
}

void destroy(s_hunter *p)
{
    sfRenderWindow_destroy(p->window);
    sfTexture_destroy(p->font_texture);
    sfTexture_destroy(p->duck_texture);
    sfTexture_destroy(p->play_texture);
    sfTexture_destroy(p->yalp_texture);
    sfTexture_destroy(p->lose_texture);
    sfSprite_destroy(p->font_sprite);
    sfSprite_destroy(p->duck_sprite);
    sfSprite_destroy(p->play_sprite);
    sfSprite_destroy(p->yalp_sprite);
    sfSprite_destroy(p->lose_sprite);
    sfMusic_destroy(p->intro_mel);
    sfMusic_destroy(p->game_over);
}
