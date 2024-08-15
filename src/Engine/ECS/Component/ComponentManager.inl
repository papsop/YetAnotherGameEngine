#include <Engine/ECS/Component/ComponentManager.h>
#include <Engine/Utils/IdGenerator.h>

namespace Engine {

template<typename T>
void C_ComponentManager::RegisterComponent()
{
  auto componentId = GetComponentId<T>();

  // check find
  m_ComponentContainers.insert({ componentId, std::make_unique<C_ComponentContainer<T>>() });
}

// =================================================
template<typename T>
void C_ComponentManager::RemoveComponent(T_Entity entity)
{
  GetComponentContainer<T>()->RemoveData(entity);
}

// =================================================
template<typename T>
void C_ComponentManager::AddComponent(T_Entity entity, T component)
{
  GetComponentContainer<T>()->InsertData(entity, component);
}

// =================================================
template<typename T>
T& C_ComponentManager::GetComponent(T_Entity entity)
{
  return GetComponentContainer<T>()->GetData(entity);
}

// =================================================
template<typename T>
T_ComponentId C_ComponentManager::GetComponentId()
{
  return C_IdGenerator<C_ComponentManager>::GetId<T>();
}

// =================================================
template<typename T>
C_ComponentContainer<T>* C_ComponentManager::GetComponentContainer()
{
  auto componentId = GetComponentId<T>();

  // check find

  return static_cast<C_ComponentContainer<T>>(m_ComponentContainers[componentId]);
}

}