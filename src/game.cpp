#include "game.h"

#include "../../include/graphx.h"

struct player player;
void game_loop() {
    //fps limiter
    timer_Enable(1, TIMER_32K, TIMER_0INT, TIMER_UP);

    init_player();
    gfx_FillScreen(0);
    while (true) {
        //fps
        uint32_t frame_start = timer_1_Counter;

        //clears
        clear_player();

        kb_Scan();
        if (kb_Data[7] & kb_Left && player.x > 5) {
            player.prevX = player.x;
            player.x -= 3;
        }
        if (kb_Data[7] & kb_Right && player.x < 315 - player.w) {
            player.prevX = player.x;
            player.x += 3;
        }
        if (player.x > 315) player.x = 315;
        if (player.x < 5) player.x = 5;
        //draws
        draw_player();
        gfx_BlitBuffer();
        // Wait for ~30 FPS (32768 ticks per second / 30 = ~1092 ticks)
        while ((timer_1_Counter - frame_start) < 546);
    }
}
