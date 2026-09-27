#include "raylib.h"

int main(int argc, char *argv[])
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 450, "vsrg");
    SetTargetFPS(1200);

    while(!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(WHITE);
        DrawFPS(0, 0);

        EndDrawing();
    }

    return 0;
}
