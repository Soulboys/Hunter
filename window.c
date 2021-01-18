/*
** EPITECH PROJECT, 2018
** window.c
**File Descripton
**
*/

#include <stdio.h>
#include <time.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <math.h>
#include "include/my.h"


int getInt(sfRenderWindow *window, spr_t *first, sfIntRect
*rect, spr_t *background, sfVector2f *vector)
{
    int loose = 0;
    int i = 0;
    int offset = 150;
    sfVector2f pos;

    (pos) = sfSprite_getPosition(first->sprite);
    sfSprite_move(first->sprite, (*vector));
    sfRenderWindow_drawSprite(window, background->sprite, NULL);
    sfSprite_setTextureRect(first->sprite, *rect);
    sfRenderWindow_drawSprite(window, first->sprite, NULL);
    i = analyse_events(window, first, (pos));
    move_rect(rect, offset, first->clock);
    if (i == 1) {
        (vector)->x = (vector)->x + 0.1;
    }
    if ((pos).x > 1500) {
        loose = 1;
        setposofsprite(first);
    }
    return (loose);
}
