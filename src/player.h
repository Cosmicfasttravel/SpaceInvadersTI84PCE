#ifndef PLAYER_H
#define PLAYER_H
#include <stdint.h>

#include "game.h"
void init_player();
void draw_player();
void clear_player();

struct player {
    uint16_t x;
    uint16_t y;
    uint8_t w;
    uint8_t h;
    uint16_t plPrevX;
    uint8_t lives;
};
extern struct player player;
#endif //PLAYER_H
