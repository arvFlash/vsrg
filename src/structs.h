#include <stdint.h>
#include "raylib.h"
#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct {
    uint32_t time_ms;
    uint32_t end_time_ms;
    uint8_t lane;
    bool hit;
} Note;

typedef struct {
    Note *notes;
    uint8_t lanes;    
    Music song;
    uint64_t note_count;
} Chart;

typedef struct {
    uint32_t note_index;
} GameplayState;

typedef struct {
    int lane_keys[10];
} KeyBinds;

typedef struct {
    KeyBinds binds[11];
} Controls;

#endif
