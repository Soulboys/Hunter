/*
** EPITECH PROJECT, 2018
** include.h
**File Descripton
**
*/
#ifndef MUL_MY_HUNTER_2018_INCLUDE_H
#define MUL_MY_HUNTER_2018_INCLUDE_H


#define MAX_WIDTH (1400)
#define MAX_LENGTH (800)

typedef struct spr_s {
    sfClock *clock;
    sfSprite *sprite;
    sfTexture *texture;
} spr_t;

void reees(sfVector2f *vector, sfSprite *losse);
int analyse_events(sfRenderWindow *window, spr_t *first, sfVector2f pos);
int move_rect(sfIntRect *rect, int offset, sfClock *clock);
int setposofsprite(spr_t *first);
int lose(sfRenderWindow *window, spr_t *first, sfVector2f *vector);
int getInt(sfRenderWindow *window, spr_t *first, sfIntRect*rect, spr_t
*background, sfVector2f *vector);

#endif