#include <Engine/ECS/Component/ComponentManager.h>

#include <Engine/Utils/IdGenerator.h>

namespace Engine {

template<typename T>
void Engine::C_ComponentManager::RegisterComponent()
{
  auto componentId = C_IdGenerator<Engine::C_ComponentManager>::GetId<T>();

  
}

// =================================================
template<typename T>
T& Engine::C_ComponentManager::GetComponent(T_Entity entity)
{

}

// =================================================
template<typename T>
void Engine::C_ComponentManager::RemoveComponent(T_Entity entity)
{

}

// =================================================
template<typename T>
void Engine::C_ComponentManager::AddComponent(T_Entity entity, T component)
{

}

}