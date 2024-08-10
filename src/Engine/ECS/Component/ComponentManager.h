#pragma once

#include <Engine/ECS/Entity/EntityDefines.h>
#include <Engine/ECS/Component/ComponentDefines.h>
#include <Engine/ECS/Component/ComponentContainer.h>

#include <unordered_map>
#include <memory>

namespace Engine {

class C_ComponentManager
{
public:
  C_ComponentManager();
  ~C_ComponentManager() = default;

  void RegisterComponent();
  void DestroyEntity(T_Entity entity);

private:
  std::unordered_map<T_ComponentId, std::unique_ptr<I_ComponentContainer>> m_Components;
};

}