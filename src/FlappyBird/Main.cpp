#include <FlappyBird/GameDefinition.h>

#include <Engine/Application.h>

int main()
{

  Engine::Application app;

  app.RegisterGame(FlappyBird::C_GameDefinition());
  app.Run();

  return 0;
}