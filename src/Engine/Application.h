#pragma once
#include <Engine/Game/GameDefinition.h>

namespace Engine
{
  class Application
  {
  public:
    void RegisterGame(const IGameDefinition& gameDef);

    void Run();
  };
}