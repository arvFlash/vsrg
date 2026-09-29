#include "raylib.h"

typedef enum {
    STATE_MENU,
    STATE_SONG_SELECT,
    STATE_GAMEPLAY,
    STATE_PAUSED,
    STATE_RESULTS
} GameState;

typedef struct {
    GameState state;
    
} Game;


static inline float right(float margin, float width)
{
    return GetScreenWidth() -  margin - width;
}

static inline float left(float margin)
{
    return margin;
}

static inline float center(float width)
{
    return (GetScreenWidth() - width) / 2.0f;
}

int main(int argc, char *argv[])
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 450, "vsrg");
    SetTargetFPS(1200);

    while(!WindowShouldClose()) {
        BeginDrawing();
        float scale = GetScreenHeight() / 1080.0f;
        ClearBackground(WHITE);
        DrawFPS(0, 0);

        DrawRectangleRec((Rectangle){left(250 * scale), 490 * scale, 100 * scale, 100 * scale}, RED);
        DrawRectangleRec((Rectangle){right(250 * scale, 100 * scale), 490 * scale, 100 * scale, 100 * scale}, BLUE);
        DrawRectangleRec((Rectangle){center(100 * scale), 490 * scale, 100 * scale, 100 * scale}, PURPLE);
        DrawRectangleRec((Rectangle){center(100 * scale) + 100 * scale, 490 * scale, 100 * scale, 100 * scale}, ORANGE);
        DrawRectangleRec((Rectangle){center(100 * scale) - 100 * scale, 490 * scale, 100 * scale, 100 * scale}, ORANGE);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
