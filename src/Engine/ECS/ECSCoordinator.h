#pragma once

#include <Engine/ECS/Entity/EntityDefines.h>
#include <Engine/ECS/Component/ComponentDefines.h>

#include <memory>

namespace Engine
{
class C_EntityManager;
class C_ComponentManager;
class C_SystemManager;

class C_ECSCoordinator
{
public:
  C_ECSCoordinator();
  ~C_ECSCoordinator();

  // Entity
  T_Entity CreateEntity();
  void DestroyEntity(T_Entity entity);

  // Component
  template<typename T>
  void RegisterComponent();

  template<typename T>
  void AddComponent(T_Entity entity, T component);

  template<typename T>
  void RemoveComponent(T_Entity entity);

  template<typename T>
  T& GetComponent(T_Entity entity);

  template<typename T>
  T_ComponentId GetComponentId();

  // System

private:
  std::unique_ptr<C_EntityManager> m_EntityManager;
  std::unique_ptr<C_ComponentManager> m_ComponentManager;
  std::unique_ptr<C_SystemManager> m_SystemManager;
};
}

#include <Engine/ECS/ECSCoordinator.inl>