#include <Engine/ECS/Entity/EntityManager.h>

#include <assert.h> // TODO glog? spdlog?

namespace Engine{

C_EntityManager::C_EntityManager()
{
  for (int i = 0; i < MAX_ENTITIES; i++)
  {
    m_AvailableEntities.push(i);
  }
}

// =================================================
T_Entity C_EntityManager::CreateEntity()
{
  assert(m_AvailableEntities.size() > 0 && "Ran out of entities");

  T_Entity res = m_AvailableEntities.front();
  m_AvailableEntities.pop();
  return res;
}

// =================================================
void C_EntityManager::DestroyEntity(T_Entity entity)
{
  assert(entity < MAX_ENTITIES && "Out of range");

  // since it's queue, we can't really check if the Entity is even created

  m_Signatures[entity].reset();
  m_AvailableEntities.push(entity);
}

// =================================================
void C_EntityManager::SetSignature(T_Entity entity, T_Signature signature)
{
  assert(entity < MAX_ENTITIES && "Out of range");

  m_Signatures[entity] = signature;
}

// =================================================
const T_Signature& C_EntityManager::GetSignature(T_Entity entity)
{
  assert(entity < MAX_ENTITIES && "Out of range");

  return m_Signatures[entity];
}

}