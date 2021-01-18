/*
** EPITECH PROJECT, 2018
** Delivery
** File description:
** my_ hunter
*/

#include <stdio.h>
#include <time.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/VideoMode.h>
#include <SFML/Window/WindowHandle.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/System/Time.h>
#include <math.h>
#include "include/my.h"

int movesinus(sfVector2f *vector, int i, sfClock *clo, float *times)
{
    *times = sfClock_getElapsedTime(clo).microseconds;
    if (*times >= 900000) {
        if (i == 0) {
            vector->y = 0.2;
            i = 1;
        }
        else {
            vector->y = -0.2;
            i = 0;
        }
        sfClock_restart(clo);
    }
    return (i);
}

int menu(sfRenderWindow *window, spr_t *first)
{
    sfVector2i pospush;
    sfVector2f pos;

    analyse_events(window, first, (pos));
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        pospush = sfMouse_getPositionRenderWindow(window);
        if ((pospush.x <= 950) && (pospush.x >= 480) &&
            (pospush.y >= 150) && (pospush.y <= 400)) {
            return (1);
        }
        if ((pospush.x <= 950) && (pospush.x >= 480) &&
            (pospush.y >= 450) && (pospush.y <= 700)) {
            sfRenderWindow_close(window);
        }
    }
}

int display_window(sfRenderWindow *window, spr_t *first, sfIntRect *rect,
                   spr_t *background)
{
    sfClock *clo;
    int loose = 0;
    int lo = 2;
    int tmp = 0;
    sfVector2f vector = {0.2, 0};
    float *times;
    int i = 0;

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        if (lo == 0) {
            i = movesinus(&vector, i, &clo, &times);
            tmp = getInt(window, first, rect, background, &vector);
            loose = tmp + loose;
            if (loose == 3) {
                lo = 1;
            }
        }
        if (lo == 1) {
            sfRenderWindow_drawSprite(window, background->sprite, NULL);
            if (lose(window, first, &vector) == 1) {
                lo = 0;
                loose = 0;
            }
        }
        if (lo == 2) {
            sfRenderWindow_drawSprite(window, background->sprite, NULL);
            if (menu(window, first) == 1) {
                lo = 0;
                background->texture = sfTexture_createFromFile("screen.jpg", NULL);
                sfSprite_setTexture(background->sprite, background->texture,
                        sfTrue);
            }
        }
    }
    return (0);
}

int create_window(spr_t *first, spr_t *background)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {MAX_WIDTH, MAX_LENGTH, 32};
    sfMusic *music;
    sfIntRect rect = {0, 0, 150, 150};
    sfVector2f position = {10, 100};

    background->texture = sfTexture_createFromFile(
            "screen2.png", NULL);
    background->sprite = sfSprite_create();
    first->texture = sfTexture_createFromFile("twit.png", NULL);
    first->sprite = sfSprite_create();
    sfSprite_setPosition(first->sprite, position);
    window = sfRenderWindow_create(video_mode, "My Window",
                                   sfDefaultStyle | sfClose, NULL);
    music = sfMusic_createFromFile("wii-sports-wii-sports-theme.ogg");
    sfSprite_setTexture(first->sprite, first->texture, sfTrue);
    sfSprite_setTexture(background->sprite, background->texture, sfTrue);
    sfMusic_play(music);
    display_window(window, first, &rect, background);
    sfSprite_destroy(background->sprite);
    sfSprite_destroy(first->sprite);
    sfRenderWindow_destroy(window);
    return (0);
}

int init_game(spr_t *first)
{
    first->clock = sfClock_create();
}

int main(void)
{
    spr_t *first = malloc(sizeof(spr_t));
    spr_t *background = malloc(sizeof(spr_t));
    init_game(first);
    create_window(first, background);
    return (0);
}
