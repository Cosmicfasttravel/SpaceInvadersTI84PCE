#include "main.h"
#include "game.h"
#include <graphx.h>
#include <sys/util.h>
#include <sys/rtc.h>

int main() {
    srandom(rtc_Time());
    gfx_Begin();
    gfx_SetDrawBuffer();
    game_loop();
}
