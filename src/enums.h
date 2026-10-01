#ifndef ENUMS_H
#define ENUMS_H

typedef enum {
    STATE_MENU,
    STATE_SONG_SELECT,
    STATE_GAMEPLAY,
    STATE_PAUSED,
    STATE_RESULTS
} GameState;

typedef enum {
    NOTE_PENDING,
    NOTE_HOLDING,
    NOTE_DONE
} NoteState;

typedef enum {
    JUDGEMENT_PENDING,
    JUDGEMENT_HIT,
    JUDGEMENT_DROPPED
} JudgementOutcome;

#endif
