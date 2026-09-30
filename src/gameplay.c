#include "gameplay.h"
#include "enums.h"
#include "structs.h"
#include "raylib.h"
#include "scaling.h"
#include <stdlib.h>



void Gameplay(GameState *state, Chart *chart, GameplayState *gp_state, Controls *controls)
{
    float scale = GetScreenHeight() / 1080.0f;
    float size = 50.0f;
    float speed = 1.0f;
    float hit_pos = 100.0f; // units above screen border where note should be hit
    float gap = 10.0f; // units of space between lanes
    float lane_width = size * 2 + gap;
    float total_width = lane_width * chart->lanes - gap;
    float guide_thickness = 1.05; // guide circles line thickness

    ClearBackground(BLACK);

    if(!IsMusicStreamPlaying(chart->song)) {
        PlayMusicStream(chart->song);
    }

    for(int i = 0; i < chart->lanes; i++) {
        float x = center_circ() - total_width * scale * 0.5f + (i * lane_width * scale) + (size * scale);
        DrawCircle(x, (1080 - hit_pos) * scale, size * scale * guide_thickness, WHITE);
        DrawCircle(x, (1080 - hit_pos) * scale, size * scale, BLACK);
    }

    float time = GetMusicTimePlayed(chart->song) * 1000;
    int i = gp_state->note_index;
    while(true) {


        if(i >= chart->note_count) {
            break;
        }

        float position = ((chart->notes[i].time_ms - time) * speed) * -1 + 1080 - hit_pos;
        float x = center_circ() - total_width * scale * 0.5f + (chart->notes[i].lane * lane_width * scale) + (size * scale);

        if(position < -size) {
            break;
        }

        if(position > 1080 + size) {
            gp_state->note_index++;
            i++;
            continue;
        }
        

        DrawCircle(x, position * scale, size * scale, WHITE);
        i++;
    }

    if(GetMusicTimePlayed(chart->song) >= GetMusicTimeLength(chart->song) - 0.1) {
        *state = STATE_MENU;
        free(chart->notes);
        UnloadMusicStream(chart->song);
        return;
    }
    UpdateMusicStream(chart->song);
    return;
}
