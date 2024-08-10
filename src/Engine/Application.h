#pragma once
#include <Engine/Game/GameDefinition.h>

#include <memory>

namespace Engine {

class C_EntityManager;

class Application
{
public:
  Application();
  ~Application();

  void RegisterGame(const I_GameDefinition& gameDef);

  void Run();

private:
  std::unique_ptr<C_EntityManager> m_EntityManager;
};

}