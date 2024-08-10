#pragma once

#include <Engine/ECS/Entity/EntityDefines.h>
#include <Engine/ECS/Component/ComponentDefines.h>

#include <queue>
#include <array>

namespace Engine {

class C_EntityManager
{
public:
  C_EntityManager();
  ~C_EntityManager() = default;

  T_Entity CreateEntity();
  void DestroyEntity(T_Entity entity);

  void SetSignature(T_Entity entity, T_Signature signature);
  const T_Signature& GetSignature(T_Entity entity);

private:
  std::queue<T_Entity> m_AvailableEntities;
  std::array<T_Signature, MAX_ENTITIES> m_Signatures;
};

}