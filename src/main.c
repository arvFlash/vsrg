#include "raylib.h"
#include "start.h"
#include "gameplay.h"
#include "scaling.h"
#include "enums.h"


int main(int argc, char *argv[])
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 450, "vsrg");
    SetTargetFPS(720);
    InitAudioDevice();
    SetMasterVolume(1.0);

    Controls controls;
    controls.binds[4].lane_keys[0] = KEY_D;
    controls.binds[4].lane_keys[1] = KEY_F;
    controls.binds[4].lane_keys[2] = KEY_J;
    controls.binds[4].lane_keys[3] = KEY_K;
    
    controls.binds[7].lane_keys[0] = KEY_A;
    controls.binds[7].lane_keys[1] = KEY_S;
    controls.binds[7].lane_keys[2] = KEY_D;
    controls.binds[7].lane_keys[3] = KEY_SPACE;
    controls.binds[7].lane_keys[4] = KEY_J;
    controls.binds[7].lane_keys[5] = KEY_K;
    controls.binds[7].lane_keys[6] = KEY_L;

    Skin skin;
    skin.colors[4].lane_colors[0] = WHITE;
    skin.colors[4].lane_colors[1] = WHITE;
    skin.colors[4].lane_colors[2] = WHITE;
    skin.colors[4].lane_colors[3] = WHITE;

    skin.colors[7].lane_colors[0] = WHITE;
    skin.colors[7].lane_colors[1] = BLUE;
    skin.colors[7].lane_colors[2] = WHITE;
    skin.colors[7].lane_colors[3] = YELLOW;
    skin.colors[7].lane_colors[4] = WHITE;
    skin.colors[7].lane_colors[5] = BLUE;
    skin.colors[7].lane_colors[6] = WHITE;

    GameState state = STATE_MENU;
    Chart chart;
    GameplayState gp_state;
    JudgementResult judgement_result;
    
    while(!WindowShouldClose()) {
        BeginDrawing();
        DrawFPS(0, 0);

        switch(state) {
            case STATE_MENU:
                StartMenu(&state, &chart, &gp_state);
                break;
            case STATE_GAMEPLAY:
                Gameplay(&state, &chart, &gp_state, &controls, &skin);
                break;
            default:
                ClearBackground(BLACK);
                break;
            }
        
        EndDrawing();
    }
    CloseWindow();
    CloseAudioDevice();
    return 0;
}
