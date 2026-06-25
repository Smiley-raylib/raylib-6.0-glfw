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
    SetTargetFPS(60);
}

void AppUnload(App* app)
{
    CloseWindow();
}

void AppUpdate(App* app, float dt)
{
    static bool is_first_frame = true;
    if (!is_first_frame)
    {
        // Do stuff
    }
    else
        is_first_frame = false;
}

void AppDraw(App* app)
{
    BeginDrawing();
    ClearBackground(WHITE);

    DrawCircleV(GetMousePosition(), 20.0f, RED);

    static bool showMessageBox = false;
    if (GuiButton( { 24, 24, 120, 30 }, "#191#Show Message"))
        showMessageBox = true;

    if (showMessageBox)
    {
        int result = GuiMessageBox( { 85, 70, 250, 100 }, "#191#Message Box", "Hi! This is a message!", "Nice;Cool");
        if (result >= 0)
            showMessageBox = false;
    }

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
