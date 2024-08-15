#include <Engine/ECS/ECSCoordinator.h>

#include <Engine/ECS/Entity/EntityManager.h>
#include <Engine/ECS/Component/ComponentManager.h>
#include <Engine/ECS/System/SystemManager.h>

namespace Engine
{
C_ECSCoordinator::C_ECSCoordinator()
{
  m_ComponentManager = std::make_unique<C_ComponentManager>();
  m_EntityManager = std::make_unique<C_EntityManager>();
  m_SystemManager = std::make_unique<C_SystemManager>();
}

// =================================================
C_ECSCoordinator::~C_ECSCoordinator()
{
/* empty and must be here, the unique_ptr's destructor is unknown if THIS destructor is in the header file
* - https://stackoverflow.com/a/34073093/1953344
*/
}

// =================================================
T_Entity C_ECSCoordinator::CreateEntity()
{
  return m_EntityManager->CreateEntity();
}

// =================================================
void C_ECSCoordinator::DestroyEntity(T_Entity entity)
{
  m_EntityManager->DestroyEntity(entity);
}

// =================================================
}
