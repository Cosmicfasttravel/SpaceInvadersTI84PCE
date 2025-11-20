#include "enemy.h"
#include "projectile.h"
#include "../../include/graphx.h"
#include "../../include/sys/util.h"

struct enemy {
    uint16_t x;
    uint8_t y;
    uint16_t ePrevX;
    uint8_t ePrevY;
    uint8_t hp;
    int8_t dir = 1;
    uint8_t size = 8;
    uint8_t shotFrameCounter = 0;
    uint8_t targetShotDelayFrames = 3;
    enemyType type;

    bool alive;
} enemy[MAX_ENEMIES];

void spawn_enemy(uint16_t x, uint8_t y, uint8_t hp, int8_t dir, enemyType type) {
    for (auto i = 0; i < MAX_ENEMIES; i++) {
        if (enemy[i].alive) continue;
        enemy[i].alive = true;
        enemy[i].x = x;
        enemy[i].y = y;
        enemy[i].hp = hp;
        enemy[i].dir = dir;
        enemy[i].type = type;
        return;
    }
}

void update_enemy() {
    static int movementFrameCounter = 0;
    constexpr int movementDelayFrames = 3;
    if (++movementFrameCounter < movementDelayFrames) return;
    movementFrameCounter = 0;
    for (auto i = 0; i < MAX_ENEMIES; i++) {
        if (!enemy[i].alive) continue;
        enemy[i].ePrevX = enemy[i].x;
        enemy[i].ePrevY = enemy[i].y;
        enemy[i].shotFrameCounter += 1;
        (enemy[i].type != TURRET) ? enemy[i].x += enemy[i].dir : enemy[i].x;
        if (enemy[i].x >= 315) enemy[i].dir *= -1;
        if (enemy[i].x <= 5) enemy[i].dir *= -1;
        if (enemy[i].type == ALIEN) {
            if (enemy[i].shotFrameCounter >= enemy[i].targetShotDelayFrames) {
                init_enemy_projectile(enemy[i].x + (enemy[i].size / 2), enemy[i].y, 1);
                enemy[i].shotFrameCounter = 0;
                enemy[i].targetShotDelayFrames = randInt(25, 75);
            }
        }
        if (enemy[i].type == TURRET) {
            if (enemy[i].shotFrameCounter >= enemy[i].targetShotDelayFrames) {
                init_enemy_projectile(enemy[i].x + (enemy[i].size / 2), enemy[i].y, 1);
                enemy[i].shotFrameCounter = 0;
                enemy[i].targetShotDelayFrames = randInt(3, 15);
            }
        }
        for (auto j = 0; j < MAX_PLAYER_PROJECTILE; j++) {
            if (!enemy[i].alive) continue;
            if (!playerProjectiles[j].active) continue;
            if ((playerProjectiles[j].x >= enemy[i].x && playerProjectiles[j].x <= enemy[i].x + enemy[i].size) &&
                (playerProjectiles[j].y <= enemy[i].y + enemy[i].size && playerProjectiles[j].y >= enemy[i].y)) {
                playerProjectiles[j].active = false;
                enemy[i].hp--;
                if (enemy[i].hp <= 0) enemy[i].alive = false;
            }
        }
    }
}

void draw_enemy() {
    for (auto i = 0; i < MAX_ENEMIES; i++) {
        if (!enemy[i].alive) continue;
        switch (enemy[i].hp) {
            case 1:
                gfx_SetColor(224);
                break;
            case 2:
                gfx_SetColor(230);
                break;
            case 3:
                gfx_SetColor(74);
            default:;
        }
        gfx_FillRectangle(enemy[i].x, enemy[i].y, enemy[i].size, enemy[i].size);
    }
}

void clear_enemy() {
    gfx_SetColor(0);
    for (auto i = 0; i < MAX_ENEMIES; i++) {
        if (!enemy[i].alive) {
            gfx_FillRectangle(enemy[i].x, enemy[i].y, enemy[i].size, enemy[i].size);
            continue;
        }
        gfx_FillRectangle(enemy[i].ePrevX, enemy[i].ePrevY, enemy[i].size, enemy[i].size);
    }
}
