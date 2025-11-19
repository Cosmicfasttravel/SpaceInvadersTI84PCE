#include "player.h"
#include "../../include/graphx.h"

struct player player;

void init_player() {
    player.x = 160;
    player.y = 200;
    player.w = 5;
    player.h = 5;
    player.lives = 3;
}
void draw_player() {
    gfx_SetColor(255);
    gfx_FillRectangle(player.x, player.y, player.w, player.h);
    gfx_SetColor(0);
}

void clear_player() {
    gfx_SetColor(0);
    gfx_FillRectangle(player.prevX, player.y, player.w, player.h);
    gfx_SetColor(255);
}
