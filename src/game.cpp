#include "game.h"
#include <sys/timers.h>
#include <graphx.h>
#include <keypadc.h>

void game_loop() {

    //fps limiter
    timer_Enable(1, TIMER_32K, TIMER_0INT, TIMER_UP);

    init_player();
    gfx_FillScreen(0);

    uint16_t prev_keys = 0;

    while (true) {
        //fps
        uint32_t frame_start = timer_1_Counter;

        //clears
        clear_player();
        clear_projectiles();

        kb_Scan();
        uint16_t current_keys = kb_Data[7] | kb_Data[6];

        if (kb_Data[7] & kb_Left && player.x > 5) {
            player.prevX = player.x;
            player.x -= 3;
        }
        if (kb_Data[7] & kb_Right && player.x < 315 - player.w) {
            player.prevX = player.x;
            player.x += 3;
        }
        if ((current_keys & kb_Up) && !(prev_keys & kb_Up)) {
            shoot(player.x + (player.w/2), player.y - 5, -1);
        }
        if (kb_Data[6] & kb_Clear){ gfx_End(); return; }
        if (player.x > 315) player.x = 315;
        if (player.x < 5) player.x = 5;

        //updates
        update_projectiles();
        //draws
        draw_projectiles();
        draw_player();
        gfx_BlitBuffer();

        prev_keys = current_keys;
        // Wait for 60 FPS (32768 ticks per second / 60)
        while ((timer_1_Counter - frame_start) < 546);
    }
}
