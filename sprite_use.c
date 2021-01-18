/*
** EPITECH PROJECT, 2018
** sprite_use.c
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

int move_rect(sfIntRect *rect, int offset, sfClock *clock)
{
    int max_value = 600;
    float time = 0;

    time = sfClock_getElapsedTime(clock).microseconds;
    if (time >= 100000) {
        rect->left = rect->left + offset;
        if (rect->left >= max_value) {
            rect->left = rect->left - max_value;
        }
        sfClock_restart(clock);
    }
}

int setposofsprite(spr_t *first)
{
    int r = (rand() % 700);
    sfVector2f reposition2 = {10, r};

    sfSprite_setPosition(first->sprite, reposition2);
    return (1);
}

int analyse_events(sfRenderWindow *window, spr_t *first, sfVector2f pos)
{
    sfEvent event;
    int k = 0;
    sfVector2i pospush;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(window);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            pospush = sfMouse_getPositionRenderWindow(window);
            if ((pospush.x <= pos.x + 150) && (pospush.x >= pos.x) &&
                (pospush.y >= pos.y) && (pospush.y <= pos.y + 150)) {
                k = setposofsprite(first);
            }
        }
        if (k == 1)
            return (1);
    }
}

void reees(sfVector2f *vector, sfSprite *losse)
{
    sfSprite_destroy(losse);
    vector->x = 0.2;
}

int lose(sfRenderWindow *window, spr_t *first, sfVector2f *vector)
{
    sfSprite *restart;
    sfTexture *rest;
    sfVector2f posi = {0, -100};
    sfVector2f pos = {10, 300};
    sfVector2i pospush;

    rest = sfTexture_createFromFile("restar.png", NULL);
    restart = sfSprite_create();
    sfSprite_setTexture(restart, rest, sfTrue);
    sfSprite_setPosition(restart, posi);
    sfRenderWindow_drawSprite(window, restart, NULL);
    analyse_events(window, first, (pos));
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        pospush = sfMouse_getPositionRenderWindow(window);
        if ((pospush.x <= 1087) && (pospush.x >= 316) &&
            (pospush.y >= 250) && (pospush.y <= 450)) {
            reees(vector, restart);
            return (1);
        }
        if ((pospush.x <= 940) && (pospush.x >= 496) &&
            (pospush.y >= 488) && (pospush.y <= 600)) {
            sfRenderWindow_close(window);
        }
    }
}
