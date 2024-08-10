#pragma once

#include <Engine/ECS/Entity/EntityDefines.h>
#include <Engine/ECS/Component/ComponentDefines.h>

#include <array>
#include <unordered_map>

namespace Engine {

class I_ComponentContainer
{
public:
  virtual ~I_ComponentContainer() = default;
  virtual void EntityDestroyed(T_Entity entity) = 0;
};

// =====================================================
template<typename T>
class C_ComponentContainer : public I_ComponentContainer
{
public:
  using T_Index = uint32_t;

  virtual ~C_ComponentContainer() override = default;
  virtual void EntityDestroyed(T_Entity entity) override;

  void InsertData(T_Entity entity, T data);
  void RemoveData(T_Entity entity);
  T& GetData(T_Entity entity);

private:
  std::array<T, MAX_ENTITIES> m_ComponentsArray;
  std::unordered_map<T_Entity, T_Index> m_EntityToIndexMap;
  std::unordered_map<T_Index, T_Entity> m_IndexToEntityMap;

  T_Index m_ComponentsCount = 0;
};

}

#include <Engine/ECS/Component/ComponentContainer.inl>