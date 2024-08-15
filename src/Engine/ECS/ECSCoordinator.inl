#include <Engine/ECS/ECSCoordinator.h>

#include <Engine/ECS/Component/ComponentManager.h>

namespace Engine
{

template<typename T>
T_ComponentId C_ECSCoordinator::GetComponentId()
{
  return m_ComponentManager->GetComponentId<T>();
}

// =================================================
template<typename T>
T& C_ECSCoordinator::GetComponent(T_Entity entity)
{
  return m_ComponentManager->GetComponent<T>(entity);
}

// =================================================
template<typename T>
void C_ECSCoordinator::RemoveComponent(T_Entity entity)
{
  m_ComponentManager->RemoveComponent<T>(entity);
}

// =================================================
template<typename T>
void C_ECSCoordinator::AddComponent(T_Entity entity, T component)
{
  m_ComponentManager->AddComponent<T>(entity, component);
}

// =================================================
template<typename T>
void C_ECSCoordinator::RegisterComponent()
{
  m_ComponentManager->RegisterComponent<T>();
}
}