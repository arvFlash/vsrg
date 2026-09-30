#include "start.h"
#include "raylib.h"
#include "scaling.h"
#include "enums.h"
#include "structs.h"
#include <stdlib.h>

void StartMenu(GameState *state, Chart *chart, GameplayState *gp_state)
{
    // float scale = GetScreenHeight() / 1080.0f;
    ClearBackground(WHITE);
    if(IsMouseButtonPressed(0)) {
        chart->note_count = 16;
        chart->notes = malloc(sizeof(Note) * chart->note_count);
        chart->song = LoadMusicStream("data/120bpm.wav");
        chart->lanes = 4;
        gp_state->note_index = 0;
        chart->notes[0].time_ms = 500;
        chart->notes[0].end_time_ms = 0;
        chart->notes[0].lane = 0;
        chart->notes[0].hit = false;

        chart->notes[1].time_ms = 1000;
        chart->notes[1].end_time_ms = 0;
        chart->notes[1].lane = 1;
        chart->notes[1].hit = false;

        chart->notes[2].time_ms = 1500;
        chart->notes[2].end_time_ms = 0;
        chart->notes[2].lane = 2;
        chart->notes[2].hit = false;

        chart->notes[3].time_ms = 2000;
        chart->notes[3].end_time_ms = 0;
        chart->notes[3].lane = 3;
        chart->notes[3].hit = false;

        chart->notes[4].time_ms = 2500;
        chart->notes[4].end_time_ms = 0;
        chart->notes[4].lane = 0;
        chart->notes[4].hit = false;

        chart->notes[5].time_ms = 3000;
        chart->notes[5].end_time_ms = 0;
        chart->notes[5].lane = 1;
        chart->notes[5].hit = false;

        chart->notes[6].time_ms = 3500;
        chart->notes[6].end_time_ms = 0;
        chart->notes[6].lane = 2;
        chart->notes[6].hit = false;

        chart->notes[7].time_ms = 4000;
        chart->notes[7].end_time_ms = 0;
        chart->notes[7].lane = 3;
        chart->notes[7].hit = false;

        chart->notes[8].time_ms = 4500;
        chart->notes[8].end_time_ms = 0;
        chart->notes[8].lane = 0;
        chart->notes[8].hit = false;

        chart->notes[9].time_ms = 5000;
        chart->notes[9].end_time_ms = 0;
        chart->notes[9].lane = 1;
        chart->notes[9].hit = false;

        chart->notes[10].time_ms = 5500;
        chart->notes[10].end_time_ms = 0;
        chart->notes[10].lane = 2;
        chart->notes[10].hit = false;

        chart->notes[11].time_ms = 6000;
        chart->notes[11].end_time_ms = 0;
        chart->notes[11].lane = 3;
        chart->notes[11].hit = false;

        chart->notes[12].time_ms = 6500;
        chart->notes[12].end_time_ms = 0;
        chart->notes[12].lane = 0;
        chart->notes[12].hit = false;

        chart->notes[13].time_ms = 7000;
        chart->notes[13].end_time_ms = 0;
        chart->notes[13].lane = 1;
        chart->notes[13].hit = false;

        chart->notes[14].time_ms = 7000;
        chart->notes[14].end_time_ms = 0;
        chart->notes[14].lane = 2;
        chart->notes[14].hit = false;

        chart->notes[15].time_ms = 7500;
        chart->notes[15].end_time_ms = 8500;
        chart->notes[15].lane = 3;
        chart->notes[15].hit = false;

        *state = STATE_GAMEPLAY;
        return;
    }
}
