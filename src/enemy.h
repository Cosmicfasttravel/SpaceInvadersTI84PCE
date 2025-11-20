#ifndef ENEMY_H
#define ENEMY_H
#define MAX_ENEMIES 10
#include "../../include/stdint.h"
enum enemyType {
    ALIEN,
};
void spawn_enemy(uint16_t x, uint8_t y, uint8_t hp, int8_t dir, enemyType type);
void update_enemy();
void draw_enemy();
void clear_enemy();
#endif //ENEMY_H
