#include <FlappyBird/GameDefinition.h>

#include <Engine/Application.h>

// todo use https://github.com/RobLoach/raylib-cpp

int main()
{
  Engine::Application app;

  app.RegisterGame(FlappyBird::C_GameDefinition());
  app.Run();

  return 0;
}