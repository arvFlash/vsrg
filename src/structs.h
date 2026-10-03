#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdint.h>
#include "raylib.h"
#include "enums.h"

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
    int held_note_index[10];
    JudgementResult *judgement_result;
} GameplayState;

typedef struct {
    int lane_keys[10];
} KeyBinds;

typedef struct {
    KeyBinds binds[11];
} Controls;

typedef struct {
    Color lane_colors[10];
} LaneColors;

typedef struct {
    LaneColors colors[11];
} Skin;

#endif
