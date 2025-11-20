#include "projectile.h"
#include "player.h"
#include "../../include/graphx.h"

projectile playerProjectiles[MAX_PLAYER_PROJECTILE];
projectile enemyProjectiles[MAX_ENEMY_PROJECTILES];

void init_player_projectile(uint16_t x, uint8_t y, int8_t dir) {
    for (auto i = 0; i < MAX_PLAYER_PROJECTILE; i++) {
        if (playerProjectiles[i].active) continue;
        playerProjectiles[i].active = true;
        playerProjectiles[i].x = x;
        playerProjectiles[i].y = y;
        playerProjectiles[i].yDir = dir;
        return;
    }
}

void init_enemy_projectile(uint16_t x, uint8_t y, int8_t dir) {
    for (auto i = 0; i < MAX_ENEMY_PROJECTILES; i++) {
        if (enemyProjectiles[i].active) continue;
        enemyProjectiles[i].active = true;
        enemyProjectiles[i].x = x;
        enemyProjectiles[i].y = y;
        enemyProjectiles[i].yDir = dir;
        return;
    }
}

void update_player_projectiles() {
    for (auto i = 0; i < MAX_PLAYER_PROJECTILE; i++) {
        if (!playerProjectiles[i].active) continue;
        playerProjectiles[i].pPrevX = playerProjectiles[i].x;
        playerProjectiles[i].pPrevY = playerProjectiles[i].y;
        playerProjectiles[i].x += playerProjectiles[i].xDir;
        playerProjectiles[i].y += playerProjectiles[i].yDir;
        if (playerProjectiles[i].y <= 1) playerProjectiles[i].active = false;
    }
}
void update_enemy_projectiles() {
    for (auto i = 0; i < MAX_ENEMY_PROJECTILES; i++) {
        if (!enemyProjectiles[i].active) continue;
        enemyProjectiles[i].pPrevX = enemyProjectiles[i].x;
        enemyProjectiles[i].pPrevY = enemyProjectiles[i].y;
        enemyProjectiles[i].x += enemyProjectiles[i].xDir;
        enemyProjectiles[i].y += enemyProjectiles[i].yDir;
        if (enemyProjectiles[i].y <= 1) enemyProjectiles[i].active = false;
    }
}

void draw_player_projectiles() {
    gfx_SetColor(6);
    for (auto i = 0; i < MAX_PLAYER_PROJECTILE; i++) {
        if (!playerProjectiles[i].active) continue;
        gfx_FillRectangle(playerProjectiles[i].x, playerProjectiles[i].y, playerProjectiles[i].w, playerProjectiles[i].h);
    }
}

void draw_enemy_projectiles() {
    gfx_SetColor(6);
    for (auto i = 0; i < MAX_ENEMY_PROJECTILES; i++) {
        if (!enemyProjectiles[i].active) continue;
        gfx_FillRectangle(enemyProjectiles[i].x, enemyProjectiles[i].y, enemyProjectiles[i].w, enemyProjectiles[i].h);
    }
}

void clear_player_projectiles() {
    gfx_SetColor(0);
    for (auto i = 0; i < MAX_PLAYER_PROJECTILE; i++) {
        if (!playerProjectiles[i].active){
            gfx_FillRectangle(playerProjectiles[i].x, playerProjectiles[i].y, playerProjectiles[i].w, playerProjectiles[i].h);
            continue;
        }
        gfx_FillRectangle(playerProjectiles[i].pPrevX, playerProjectiles[i].pPrevY, playerProjectiles[i].w, playerProjectiles[i].h);

    }
}

void clear_enemy_projectiles() {
    gfx_SetColor(0);
    for (auto i = 0; i < MAX_ENEMY_PROJECTILES; i++) {
        if (!enemyProjectiles[i].active){
            gfx_FillRectangle(enemyProjectiles[i].x, enemyProjectiles[i].y, enemyProjectiles[i].w, enemyProjectiles[i].h);
            continue;
        }
        gfx_FillRectangle(enemyProjectiles[i].pPrevX, enemyProjectiles[i].pPrevY, enemyProjectiles[i].w, enemyProjectiles[i].h);

    }
}