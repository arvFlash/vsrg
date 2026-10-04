#include "start.h"
#include "raylib.h"
#include "scaling.h"
#include "enums.h"
#include "structs.h"
#include "import.h"
#include <stdlib.h>

void StartMenu(GameState *state, Chart *chart, GameplayState *gp_state)
{
    ClearBackground(WHITE);
    ShowCursor();
    if(IsMouseButtonPressed(0)) {
        HideCursor();
        import_from_osu("data/map/", chart);

        gp_state->note_index = 0;
        gp_state->judgement_result = malloc(sizeof(JudgementResult) * chart->note_count);
        for(int i = 0; i < chart->note_count; i++) {
            gp_state->judgement_result[i].outcome = JUDGEMENT_PENDING;
        }
        for(int i = 0; i < chart->lanes; i++) {
            gp_state->held_note_index[i] = -1;
        }
        gp_state->judgement_vis = malloc(sizeof(int) * 301);
        for(int i = 0; i < 301; i++) {
            gp_state->judgement_vis[i] = 0;
        }
        gp_state->anchored_time = GetMusicTimePlayed(chart->song);
        gp_state->anchored_system_time = GetTime();
        *state = STATE_GAMEPLAY;
    }

    return;
}
