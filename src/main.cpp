#include "main.h"
#include "game.h"
#include <graphx.h>
int main() {
    gfx_Begin();
    gfx_SetDrawBuffer();
    game_loop();
}