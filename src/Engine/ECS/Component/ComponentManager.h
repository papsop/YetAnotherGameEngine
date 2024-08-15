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

  template<typename T>
  void RegisterComponent();

  template<typename T>
  void AddComponent(T_Entity entity, T component);

  template<typename T>
  void RemoveComponent(T_Entity entity);

  template<typename T>
  T& GetComponent(T_Entity entity);

  template<typename T>
  uint32_t GetComponentId();

  void EntityDestroyed(T_Entity entity);

private:
  template<typename T>
  C_ComponentContainer<T>* GetComponentContainer();

  std::unordered_map<uint32_t, std::unique_ptr<I_ComponentContainer>> m_ComponentContainers;
};

}

#include <Engine/ECS/Component/ComponentManager.inl>