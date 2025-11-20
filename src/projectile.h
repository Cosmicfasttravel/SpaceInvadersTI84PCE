#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "../../include/stdint.h"
#define MAX_PLAYER_PROJECTILE 2
#define MAX_ENEMY_PROJECTILES 20



void init_player_projectile(uint16_t x, uint8_t y, int8_t dir);
void init_enemy_projectile(uint16_t x, uint8_t y, int8_t dir);

void update_player_projectiles();
void draw_player_projectiles();
void clear_player_projectiles();

void update_enemy_projectiles();
void draw_enemy_projectiles();
void clear_enemy_projectiles();

#endif //PROJECTILE_H
