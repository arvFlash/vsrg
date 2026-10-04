#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdint.h>
#include "raylib.h"
#include "enums.h"

#define MAX_LANES 10

typedef struct {
    uint32_t time_ms;
    uint32_t end_time_ms;
    uint8_t lane;
    NoteState state;
} Note;

typedef struct {
    Note *notes;
    uint8_t lanes;    
    Music song;
    uint64_t note_count;
    uint32_t offset_ms;
} Chart;

typedef struct {
    JudgementOutcome outcome;
    float click_delay_ms;
    float release_delay_ms;
} JudgementResult;


typedef struct {
    uint32_t note_index;
    int held_note_index[MAX_LANES];
    JudgementResult *judgement_result;
    float anchored_time;
    float anchored_system_time;
    int *judgement_vis;
} GameplayState;

typedef struct {
    int lane_keys[MAX_LANES];
} KeyBinds;

typedef struct {
    KeyBinds binds[MAX_LANES + 1];
} Controls;

typedef struct {
    Color lane_colors[MAX_LANES];
} LaneColors;

typedef struct {
    LaneColors colors[MAX_LANES + 1];
} Skin;

#endif
