#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "../../include/stdint.h"
#define MAX_PROJECTILE 32
struct projectile {
    uint16_t x;
    uint8_t y;
    int8_t xDir;
    int8_t yDir;
    uint8_t w = 1;
    uint8_t h;
    uint16_t prevX;
    uint8_t prevY;
    bool active;
};
extern struct projectile projectiles[MAX_PROJECTILE];

void shoot(uint16_t x, uint8_t y, int8_t dir);
void update_projectiles();
void draw_projectiles();
void clear_projectiles();

#endif //PROJECTILE_H
