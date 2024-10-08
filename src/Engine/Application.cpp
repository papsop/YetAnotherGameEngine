#include <Engine/Application.h>
#include <Engine/ECS/Entity/EntityManager.h>
#include <Engine/ECS/Component/ComponentManager.h>

#include <Engine/ECS/Component/Components.h>

#include <raylib/src/raylib.h>

namespace Engine {

Application::Application()
{
  m_ECSCoordinator = std::make_unique<C_ECSCoordinator>();

  InitLogger();
}

Application::~Application()
{
  /* empty and must be here, the unique_ptr's destructor is unknown if THIS destructor is in the header file
  * - https://stackoverflow.com/a/34073093/1953344
  */
}

// =================================================
void Application::InitLogger()
{

}

// =================================================
void Application::RegisterGame(const I_GameDefinition& gameDef)
{
  // todo
}

C_ECSCoordinator* Application::GetECSCoordinator()
{
  return m_ECSCoordinator.get();
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