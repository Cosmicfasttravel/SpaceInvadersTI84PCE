#include "projectile.h"
#include "player.h"
#include "../../include/graphx.h"

struct projectile projectiles[MAX_PROJECTILE];

void shoot(uint16_t x, uint8_t y, int8_t dir) {
    for (auto i = 0; i < MAX_PROJECTILE; i++) {
        if (projectiles[i].active) continue;
        projectiles[i].active = true;
        projectiles[i].x = x;
        projectiles[i].y = y;
        projectiles[i].yDir = dir;
        return;
    }
}

void update_projectiles() {
    for (auto i = 0; i < MAX_PROJECTILE; i++) {
        if (!projectiles[i].active) continue;
        projectiles[i].prevX = projectiles[i].x;
        projectiles[i].prevY = projectiles[i].y;
        projectiles[i].x += projectiles[i].xDir;
        projectiles[i].y += projectiles[i].yDir;
    }
}

void draw_projectiles() {
    gfx_SetColor(255);
    for (auto i = 0; i < MAX_PROJECTILE; i++) {
        if (projectiles[i].y <= 1) projectiles[i].active = false;
        if (!projectiles[i].active) continue;
        gfx_FillCircle(projectiles[i].x, projectiles[i].y, projectiles[i].w);
    }
}

void clear_projectiles() {
    gfx_SetColor(0);
    for (auto i = 0; i < MAX_PROJECTILE; i++) {
        if (!projectiles[i].active) {
            gfx_FillCircle(projectiles[i].x, projectiles[i].y, projectiles[i].w);
            continue;
        }
        gfx_FillCircle(projectiles[i].prevX, projectiles[i].prevY, projectiles[i].w);

    }
}