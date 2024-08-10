#include <FlappyBird/GameDefinition.h>

#include <Engine/Utils/IdGenerator.h>
#include <Engine/Application.h>

#include <Engine/ECS/Entity/EntityDefines.h>

#include <iostream>

int main()
{

  Engine::Application app;

  app.RegisterGame(FlappyBird::C_GameDefinition());
  app.Run();

  return 0;
}