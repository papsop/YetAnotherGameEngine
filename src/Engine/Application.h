#pragma once
#include <Engine/Game/GameDefinition.h>

namespace Engine
{
  class Application
  {
  public:
    void RegisterGame(const I_GameDefinition& gameDef);

    void Run();
  };
}