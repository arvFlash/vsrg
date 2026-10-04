#include "gameplay.h"
#include "enums.h"
#include "structs.h"
#include "raylib.h"
#include "scaling.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>



void Gameplay(GameState *state, Chart *chart, GameplayState *gp_state, Controls *controls, Skin *skin)
{
    float scale = GetScreenHeight() / 1080.0f;
    float size = 50.0f;
    float speed = 2.0f;
    float hit_pos = 100.0f; // units above screen border where note should be hit
    float gap = 10.0f; // units of space between lanes
    float lane_width = size * 2 + gap;
    float total_width = lane_width * chart->lanes - gap;
    float guide_thickness = 1.07; // guide circles line thickness
    int hit_threshold = 150.0; // max timing error in ms
    int bucket_size = 5;


    if(gp_state->anchored_time != GetMusicTimePlayed(chart->song)) {
        gp_state->anchored_time = GetMusicTimePlayed(chart->song);
        gp_state->anchored_system_time = GetTime();
    }
    float time = (gp_state->anchored_time + (GetTime() - gp_state->anchored_system_time)) * 1000;
    
    ClearBackground(BLACK);

    if(!IsMusicStreamPlaying(chart->song)) {
        PlayMusicStream(chart->song);
    }

    for(int i = 0; i < chart->lanes; i++) {
        float x = center_circ() - total_width * scale * 0.5f + (i * lane_width * scale) + (size * scale);
        DrawCircle(x, (1080 - hit_pos) * scale, size * scale, WHITE);
        DrawCircle(x, (1080 - hit_pos) * scale, size * scale / guide_thickness, BLACK);
    }


    for(int i = 0; i < chart->lanes; i++) {
        if(gp_state->held_note_index[i] != -1) {
            if(!IsKeyDown(controls->binds[chart->lanes].lane_keys[i])) {
                int delay = time - chart->notes[gp_state->held_note_index[i]].end_time_ms;
                if(abs(delay) < hit_threshold) {
                    gp_state->judgement_result[gp_state->held_note_index[i]].outcome = JUDGEMENT_HIT;
                    gp_state->judgement_result[gp_state->held_note_index[i]].release_delay_ms = delay;
                    gp_state->judgement_vis[(delay + hit_threshold) / bucket_size]++;
                    printf("hold: %d\n", delay);
                } else {
                    gp_state->judgement_result[gp_state->held_note_index[i]].outcome = JUDGEMENT_DROPPED;
                    printf("dropped\n");
                }
                chart->notes[gp_state->held_note_index[i]].state = NOTE_DONE;
                gp_state->held_note_index[i] = -1;
            }
        }
    }

    for(int i = 0; i < chart->lanes; i++) {
        if(IsKeyPressed(controls->binds[chart->lanes].lane_keys[i])) {
            int j = gp_state->note_index;
            while(j < chart->note_count) {
                if(chart->notes[j].lane == i) {
                    if(time - chart->notes[j].time_ms >= hit_threshold) {
                        gp_state->judgement_result[j].outcome = JUDGEMENT_MISSED;
                    } else if(gp_state->judgement_result[j].outcome == JUDGEMENT_PENDING && fabs(chart->notes[j].time_ms - time) < hit_threshold) {
                        break;
                    }
                }
                j++;
            }
            int delay = time - chart->notes[j].time_ms;
            if(abs(delay) <= hit_threshold) {
                if(chart->notes[j].end_time_ms > chart->notes[j].time_ms) {
                    if(chart->notes[j].state != NOTE_DONE) {
                        chart->notes[j].state = NOTE_HOLDING;
                        gp_state->held_note_index[chart->notes[j].lane] = j;
                    }
                } else {
                    chart->notes[j].state = NOTE_DONE;
                    gp_state->judgement_result[j].outcome = JUDGEMENT_HIT;
                }      
                gp_state->judgement_result[j].click_delay_ms = delay;
                printf("hit: %d\n", delay);
                gp_state->judgement_vis[(delay + hit_threshold) / bucket_size]++;
            }
        }
    }

    int i = gp_state->note_index;
    while(true) {
        bool is_ln = chart->notes[i].end_time_ms > chart->notes[i].time_ms;

        if(i >= chart->note_count) {
            break;
        }

        float position = ((chart->notes[i].time_ms - time) * speed) * -1 + 1080 - hit_pos;
        float x = center_circ() - total_width * scale * 0.5f + (chart->notes[i].lane * lane_width * scale) + (size * scale);
        float ln_position = position;
        if(is_ln) {
            ln_position = ((chart->notes[i].end_time_ms - time) * speed) * -1 + 1080 - hit_pos;
        }


        if(position < -size) {
            break;
        }

        if(ln_position > 1080 + size) {
            gp_state->note_index++;
            if(gp_state->judgement_result[i].outcome == JUDGEMENT_PENDING) {
                gp_state->judgement_result[i].outcome = JUDGEMENT_MISSED;
                printf("miss\n");
            }
            i++;
            continue;
        }

        if(chart->notes[i].state == NOTE_DONE) {
            i++;
            continue;
        }

        if(chart->notes[i].state == NOTE_HOLDING) {
            position = 1080 - hit_pos;
        }

        DrawCircle(x, position * scale, size * scale, skin->colors[chart->lanes].lane_colors[chart->notes[i].lane]);
        if(is_ln) {
            DrawCircle(x, ln_position * scale, size * scale, skin->colors[chart->lanes].lane_colors[chart->notes[i].lane]);
            DrawRectangle(x - size * scale, ln_position * scale, size * scale * 2, (position - ln_position) * scale, skin->colors[chart->lanes].lane_colors[chart->notes[i].lane]);
        }
        i++;
    }
    int max = 0;
    for(int i = 0; i < (hit_threshold * 2 + 1) / bucket_size; i++) {
        if(gp_state->judgement_vis[i] > max) {
            max = gp_state->judgement_vis[i];
        }
    }

    for(int i = 0; i < (hit_threshold * 2 + 1) / bucket_size; i++) {
        if(gp_state->judgement_vis[i] > 0) {
            float width = gp_state->judgement_vis[i] / (float)max * 200;
            DrawRectangleRec((Rectangle){right(0, width * scale), (390 + i * bucket_size) * scale, width * scale, bucket_size * scale}, BLUE);
        }
        if(i - hit_threshold / bucket_size == 0) {
            DrawRectangleRec((Rectangle){right(0, 50 * scale), (390 + i * bucket_size) * scale, 50 * scale, bucket_size * scale}, RED);
        }
        
    }

    if(GetMusicTimePlayed(chart->song) >= GetMusicTimeLength(chart->song) - 0.1) {
        *state = STATE_MENU;
        free(chart->notes);
        chart->notes = NULL;
        UnloadMusicStream(chart->song);
        return;
    }
    UpdateMusicStream(chart->song);
    return;
}
