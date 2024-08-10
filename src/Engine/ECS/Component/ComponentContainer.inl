#include <Engine/ECS/Component/ComponentContainer.h>

namespace Engine {

template<typename T>
void C_ComponentContainer<T>::EntityDestroyed(T_Entity entity)
{
  // if found

  RemoveData(entity);
};

// =====================================================
template<typename T>
void C_ComponentContainer<T>::InsertData(T_Entity entity, T data)
{
  auto index = m_ComponentsCount;
  m_EntityToIndexMap[entity] = index;
  m_IndexToEntityMap[index] = entity;
  m_ComponentsArray[index] = data;

  ++m_ComponentsCount;
}

// =====================================================
template<typename T>
void C_ComponentContainer<T>::RemoveData(T_Entity entity)
{
  // assert find

  // copy last -> deleted
  T_Index indexOfRemoved = m_EntityToIndexMap[entity];
  T_Index indexLastComponent = m_ComponentsCount - 1;
  m_ComponentsArray[indexOfRemoved] = m_ComponentsArray[indexLastComponent];

  // change index/entity maps for the moved component
  T_Entity lastComponentEntity = m_IndexToEntityMap[indexLastComponent];
  m_IndexToEntityMap[indexOfRemoved] = lastComponentEntity;
  m_EntityToIndexMap[lastComponentEntity] = indexOfRemoved;

  // cleanup
  m_EntityToIndexMap.erase(entity);
  m_IndexToEntityMap.erase(indexLastComponent);
  --m_ComponentsCount;
}

// =====================================================
template<typename T>
T& C_ComponentContainer<T>::GetData(T_Entity entity)
{
  // assert find

  return m_ComponentsArray[m_EntityToIndexMap[entity]];
}

}