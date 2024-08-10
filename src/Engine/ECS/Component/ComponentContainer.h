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
template<typename _ComponentType>
class C_ComponentContainer : public I_ComponentContainer
{
public:
  virtual ~C_ComponentContainer() override = default;
  virtual void EntityDestroyed(T_Entity entity) override;

  void InsertData();
  void RemoveData();
  _ComponentType& GetDataRef();

private:
  std::array<_ComponentType, MAX_ENTITIES> m_ComponentsArray;
  std::unordered_map<T_Entity, uint32_t> m_EntityToIndexMap;
  std::unordered_map<uint32_t, T_Entity> m_IndexToEntityMap;

  uint32_t m_ComponentsCount = 0;
};

}

#include <Engine/ECS/Component/ComponentContainer.inl>