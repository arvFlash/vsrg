#include "start.h"
#include "raylib.h"
#include "scaling.h"
#include "enums.h"
#include "structs.h"
#include <stdlib.h>

void StartMenu(GameState *state, Chart *chart, GameplayState *gp_state)
{
    return;
}

/*
void StartMenu(GameState *state, Chart *chart, GameplayState *gp_state)
{
    // float scale = GetScreenHeight() / 1080.0f;
    ClearBackground(WHITE);
    ShowCursor();
    if(IsMouseButtonPressed(0)) {
        HideCursor();
        chart->note_count = 16;
        chart->notes = malloc(sizeof(Note) * chart->note_count);
        chart->song = LoadMusicStream("data/120bpm.wav");
        chart->lanes = 4;
        for(int i = 0; i < chart->lanes; i++) {
            gp_state->held_note_index[i] = -1;
        }
        gp_state->note_index = 0;
        gp_state->judgement_result = malloc(sizeof(JudgementResult) * chart->note_count);
        for(int i = 0; i < chart->note_count; i++) {
            gp_state->judgement_result[i].outcome = JUDGEMENT_PENDING;
        }

        chart->notes[0].time_ms = 500;
        chart->notes[0].end_time_ms = 0;
        chart->notes[0].lane = 0;
        chart->notes[0].state = NOTE_PENDING;

        chart->notes[1].time_ms = 1000;
        chart->notes[1].end_time_ms = 0;
        chart->notes[1].lane = 1;
        chart->notes[1].state = NOTE_PENDING;

        chart->notes[2].time_ms = 1500;
        chart->notes[2].end_time_ms = 0;
        chart->notes[2].lane = 2;
        chart->notes[2].state = NOTE_PENDING;

        chart->notes[3].time_ms = 2000;
        chart->notes[3].end_time_ms = 0;
        chart->notes[3].lane = 3;
        chart->notes[3].state = NOTE_PENDING;

        chart->notes[4].time_ms = 2500;
        chart->notes[4].end_time_ms = 0;
        chart->notes[4].lane = 0;
        chart->notes[4].state = NOTE_PENDING;

        chart->notes[5].time_ms = 3000;
        chart->notes[5].end_time_ms = 0;
        chart->notes[5].lane = 1;
        chart->notes[5].state = NOTE_PENDING;

        chart->notes[6].time_ms = 3500;
        chart->notes[6].end_time_ms = 0;
        chart->notes[6].lane = 2;
        chart->notes[6].state = NOTE_PENDING;

        chart->notes[7].time_ms = 4000;
        chart->notes[7].end_time_ms = 0;
        chart->notes[7].lane = 3;
        chart->notes[7].state = NOTE_PENDING;

        chart->notes[8].time_ms = 4500;
        chart->notes[8].end_time_ms = 0;
        chart->notes[8].lane = 0;
        chart->notes[8].state = NOTE_PENDING;

        chart->notes[9].time_ms = 5000;
        chart->notes[9].end_time_ms = 0;
        chart->notes[9].lane = 1;
        chart->notes[9].state = NOTE_PENDING;

        chart->notes[10].time_ms = 5500;
        chart->notes[10].end_time_ms = 0;
        chart->notes[10].lane = 2;
        chart->notes[10].state = NOTE_PENDING;

        chart->notes[11].time_ms = 6000;
        chart->notes[11].end_time_ms = 0;
        chart->notes[11].lane = 3;
        chart->notes[11].state = NOTE_PENDING;

        chart->notes[12].time_ms = 6500;
        chart->notes[12].end_time_ms = 0;
        chart->notes[12].lane = 0;
        chart->notes[12].state = NOTE_PENDING;

        chart->notes[13].time_ms = 7000;
        chart->notes[13].end_time_ms = 0;
        chart->notes[13].lane = 1;
        chart->notes[13].state = NOTE_PENDING;

        chart->notes[14].time_ms = 7000;
        chart->notes[14].end_time_ms = 0;
        chart->notes[14].lane = 2;
        chart->notes[14].state = NOTE_PENDING;

        chart->notes[15].time_ms = 7500;
        chart->notes[15].end_time_ms = 8500;
        chart->notes[15].lane = 3;
        chart->notes[15].state = NOTE_PENDING;

        *state = STATE_GAMEPLAY;
        return;
    }
}
*/
