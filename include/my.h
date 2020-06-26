/*
** EPITECH PROJECT, 2018
** my_hunter.h
** File description:
** 
*/

#ifndef MY_H_
#define MY_H_
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <SFML/Window.h>
#include <SFML/System/Types.h>
#include <SFML/Config.h>
#include <SFML/System/Export.h>
#include <SFML/Graphics/Export.h>
#include <SFML/System/Time.h>

typedef struct s_hunter s_hunter;
struct s_hunter {
    sfRenderWindow *window;
    int width;
    int height;
    sfEvent event;
    sfIntRect rect;
    int offset;
    int max_value;
    sfTexture *font_texture;
    sfTexture *duck_texture;
    sfTexture *play_texture;
    sfTexture *yalp_texture;
    sfTexture *lose_texture;
    sfSprite *font_sprite;
    sfSprite *duck_sprite;
    sfSprite *play_sprite;
    sfSprite *yalp_sprite;
    sfSprite *lose_sprite;
    sfMusic *intro_mel;
    sfMusic *game_over;
    sfClock *clock;
    sfTime time;
    float seconds;
    int cond;
    int x;
    int y;
    int s;
    int f;
    int speed;
    int score;
    int game_stat;
    int duck_pos;
    sfVector2f duck_vec;
};

/*basic_fun.c*/
void my_putchar(char c);
int my_strlen(char *str);
void my_putstr(char *str);
void my_putnbr(int nb);

/*my_hunter.c*/
void hunter(s_hunter *p);
void clic(s_hunter *p);
void duck_move(s_hunter *p);
void game(s_hunter *p);
int main(int ac, char **av);

/*init.c*/
void cr_window(s_hunter *p);
void cr_tex_snd(s_hunter *p);
void cr_sprite(s_hunter *p);
void draw(s_hunter *p);
void destroy(s_hunter *p);

/*duck_clock.c*/
void var_init(s_hunter *p);
void duck_clock(s_hunter *p);
void duck_reset(s_hunter *p);
void duck_vector(s_hunter *p);

/*help.c*/
int help(int ac, char **av);

#endif /*MY_H_*/
