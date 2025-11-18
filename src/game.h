#ifndef GAME_H
#define GAME_H
#include "player.h"
#include <sys/timers.h>
#include <stdint.h>
#include <graphx.h>
#include <keypadc.h>

struct player {
    uint16_t x;
    uint16_t y;
    uint8_t w;
    uint8_t h;
    uint16_t prevX;
    uint8_t lives;
};
extern struct player player;
void game_loop();
#endif //GAME_H
