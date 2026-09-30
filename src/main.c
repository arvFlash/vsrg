#include "raylib.h"
#include "start.h"
#include "gameplay.h"
#include "scaling.h"
#include "enums.h"
#include <stdlib.h>


int main(int argc, char *argv[])
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 450, "vsrg");
    SetTargetFPS(0);
    InitAudioDevice();
    SetMasterVolume(1.0);

    Controls controls;
    controls.binds[4].lane_keys[0] = KEY_D;
    controls.binds[4].lane_keys[1] = KEY_F;
    controls.binds[4].lane_keys[2] = KEY_J;
    controls.binds[4].lane_keys[3] = KEY_K;
    

    GameState state = STATE_MENU;
    Chart chart;
    GameplayState gp_state;
    
    while(!WindowShouldClose()) {
        BeginDrawing();
        DrawFPS(0, 0);

        // DrawRectangleRec((Rectangle){left(250 * scale), 490 * scale, 100 * scale, 100 * scale}, RED);
        // DrawRectangleRec((Rectangle){right(250 * scale, 100 * scale), 490 * scale, 100 * scale, 100 * scale}, BLUE);
        // DrawRectangleRec((Rectangle){center(100 * scale), 490 * scale, 100 * scale, 100 * scale}, PURPLE);
        // DrawRectangleRec((Rectangle){center(100 * scale) + 100 * scale, 490 * scale, 100 * scale, 100 * scale}, ORANGE);
        // DrawRectangleRec((Rectangle){center(100 * scale) - 100 * scale, 490 * scale, 100 * scale, 100 * scale}, ORANGE);
        
        switch(state) {
            case STATE_MENU:
                StartMenu(&state, &chart, &gp_state);
                break;
            case STATE_GAMEPLAY:
                Gameplay(&state, &chart, &gp_state, &controls);
                break;
            default:
                ClearBackground(BLACK);
                break;
            }
        
        EndDrawing();
    }
    CloseWindow();
    CloseAudioDevice();
    free(chart.notes);
    UnloadMusicStream(chart.song);
    return 0;
}
