#pragma once
#include <Engine/Game/GameDefinition.h>
#include <Engine/ECS/ECSCoordinator.h>

#include <memory>

namespace Engine {

class C_ECSCoordinator;

class Application
{
public:
  Application();
  ~Application();

  void RegisterGame(const I_GameDefinition& gameDef);
  void Run();

  //
  C_ECSCoordinator* GetECSCoordinator();

private:
  void InitLogger();

  std::unique_ptr<C_ECSCoordinator> m_ECSCoordinator;
};

}