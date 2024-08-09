#include <Engine/Application.h>
#include <raylib/src/raylib.h>

namespace Engine
{

  // =================================================
  void Application::RegisterGame(const IGameDefinition& gameDef)
  {
    // todo
  }

  // =================================================
  void Application::Run()
  {
    InitWindow(800, 450, "raylib [core] example - basic window");

    while (!WindowShouldClose())
    {
      BeginDrawing();
      ClearBackground(RAYWHITE);
      DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
      EndDrawing();
    }

    CloseWindow();
  }
}