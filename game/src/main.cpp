#include "raylib.h"
#include "raymath.h"
#include "raygui.h"

struct App
{
    // Insert data here
};

void AppLoad(App* app)
{
    InitWindow(800, 800, "Game");
    InitAudioDevice();
    SetTargetFPS(60);
}

void AppUnload(App* app)
{
    CloseAudioDevice();
    CloseWindow();
}

void AppUpdate(App* app, float dt)
{
    static bool is_first_frame = true;
    if (!is_first_frame)
    {
        // Do update
    }
    else
        is_first_frame = false;
}

void AppDraw(App* app)
{
    BeginDrawing();
    ClearBackground(WHITE);

    DrawCircleV(GetMousePosition(), 20.0f, RED);

    EndDrawing();
}

int main()
{
    App app;
    AppLoad(&app);

    while (!WindowShouldClose())
    {
        AppUpdate(&app, GetFrameTime());
        AppDraw(&app);
    }

    AppUnload(&app);
    return 0;
}
